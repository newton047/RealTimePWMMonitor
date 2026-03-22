#include "timebase.h"
#include "system_stm32f4xx.h"

/** Global counter for elapsed milliseconds */
static int seconds_lapsed = 0;

/** Global callback chain */
static NotficationChain NC;

/**
 * @brief Initialize SysTick timer at 1kHz (1ms period)
 * 
 * Configuration:
 * - SysTick clock source: processor clock
 * - Period: 1ms (SystemCoreClock / 1000)
 * - Interrupt enabled
 * - Timer started
 */
void TimeBaseInit(){
	/* Set SysTick reload value for 1ms period */
	SysTick->LOAD = ((SystemCoreClock / 1000) - 1);
	
	/* Clear current value */
	SysTick->VAL = 0;

	/* Configure SysTick control register */
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |  /* Use processor clock */
	                SysTick_CTRL_TICKINT_Msk    |  /* Enable interrupt */
	                SysTick_CTRL_ENABLE_Msk;       /* Enable SysTick */

	/* Initialize callback chain */
	NC.len = 0;
}

/**
 * @brief Register a periodic callback function
 * 
 * @param milliseconds Interval in milliseconds for callback execution
 * @param callback Function pointer to execute periodically
 * @return 0 on success, -1 if callback table full (limit is 10)
 * 
 * @note Callbacks execute in interrupt context (SysTick_Handler)
 * @note All 10 slots must be filled before returning error
 */
int TimeBaseRegisterCallback(int milliseconds, void* callback){
	/* Check if callback table is full */
	if(NC.len >= 10) return -1;
	
	/* Disable interrupts for atomic operation */
	__disable_irq();

	/* Register new callback */
	NC.Node[NC.len].callback = callback;
	NC.Node[NC.len].time_delay = milliseconds;
	NC.Node[NC.len].prev_value = -1;  /* Trigger on first tick */
	NC.len++;
	
	/* Re-enable interrupts */
	__enable_irq();

	return 0;
}

/**
 * @brief SysTick interrupt handler
 * Executes every 1ms. Checks all registered callbacks and executes
 * those whose interval has elapsed.
 */
void SysTick_Handler(void) {
	static int temp = 0;
	temp++;

	/* Iterate through all registered callbacks */
	for(int i = 0; i < NC.len; i++){
		/* Calculate when callback should next trigger */
		int delta_to_trigger = NC.Node[i].prev_value + NC.Node[i].time_delay;
		
		/* Initialize callback on first call */
		if(NC.Node[i].prev_value == -1){
			NC.Node[i].prev_value = temp;
		}
		/* Execute callback if interval has elapsed */
		else if(delta_to_trigger == temp){
			NC.Node[i].callback();
			NC.Node[i].prev_value = temp;
		}
	}
}
