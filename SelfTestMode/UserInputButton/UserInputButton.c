#include "UserInputButton.h"

/**
 * @brief Initialize user button GPIO (PC13)
 * 
 * Configuration:
 * - GPIOC clock enabled
 * - PC13 configured as floating input (no pull-up/pull-down)
 * - Button is active low (pressed = 0, released = 1)
 */
void UserButtonInit(){
	/* Enable clock to GPIOC */
	RCC->AHB1ENR |= (1 << RCC_GPIOC_EN);

	/* Set PC13 as input (MODER = 00) */
	USER_BUTTON_PORT->MODER &= ~(GPIO_INPUT_MODE << (2 * USER_BUTTON_PIN_NO));
}

/**
 * @brief Read user button state
 * @return 0 if button pressed (active low), 1 if released
 */
int UserButtonRead()
{
	int val = ((USER_BUTTON_PORT->IDR & (1 << USER_BUTTON_PIN_NO)) >> USER_BUTTON_PIN_NO);
	return val;
}
