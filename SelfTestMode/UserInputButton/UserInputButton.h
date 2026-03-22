#ifndef _H_TEST_MODE_ENTER_PIN_H_
#define _H_TEST_MODE_ENTER_PIN_H_

/**
 * @file UserInputButton.h
 * @brief User input button module for speed control
 * 
 * Provides interface to read user button on PC13 (active low).
 * Button is used to cycle through motor speed settings.
 */

#include <stm32f4xx.h>

#define USER_BUTTON_PIN_NO  13
#define USER_BUTTON_PORT    GPIOC

#define RCC_GPIOC_EN            2

#define GPIO_INPUT_MODE         3

/**
 * @brief Initialize button GPIO (PC13 as input)
 * - Configures PC13 as floating input
 * - Enables GPIOC clock
 */
void UserButtonInit();

/**
 * @brief Read button state
 * @return 0 if button pressed (active low), 1 if released
 */
int UserButtonRead();

#endif
