#include "user_led.h"

/**
 * @brief Initialize user LED GPIO (PA5)
 * 
 * Configuration:
 * - GPIOA clock enabled
 * - PA5 configured as general purpose output
 * - Output type: push-pull
 */
void UserLedInit(){
	/* Enable clock to GPIOA */
	RCC->AHB1ENR |= (0x1 << RCC_USER_LED_PORT_ON);

	/* Set PA5 as output mode (MODER = 01) */
	USER_LED_PORT->MODER |= (1 << USER_LED_PIN * 2);
	
	/* Set output type as push-pull (OTYPER = 0) */
	USER_LED_PORT->OTYPER &= ~(1 << USER_LED_PIN);
}

/**
 * @brief Set LED state (on/off)
 * @param val Non-zero: LED ON, Zero: LED OFF
 */
void UserLedUpdate(int val){
	if(val != 0)
	{
		/* Set bit to turn LED on */
		USER_LED_PORT->ODR |= (1 << USER_LED_PIN);
	}
	else
	{
		/* Clear bit to turn LED off */
		USER_LED_PORT->ODR &= ~(1 << USER_LED_PIN);
	}
}
