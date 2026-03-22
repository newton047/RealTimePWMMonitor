#ifndef _H_USER_LED_H_
#define _H_USER_LED_H_

/**
 * @file user_led.h
 * @brief LED control module for error indication
 * 
 * Controls a general-purpose output LED on PA5.
 * Used to indicate error conditions during operation.
 */

#include <stm32f4xx.h>

#define USER_LED_PORT GPIOA
#define USER_LED_PIN  5

#define RCC_USER_LED_PORT_ON   0

/**
 * @brief Initialize LED GPIO (PA5 as output)
 * - Configures PA5 as general purpose output
 * - Enables GPIOA clock
 */
void UserLedInit();

/**
 * @brief Set LED state
 * @param val Non-zero: LED ON, Zero: LED OFF
 */
void UserLedUpdate(int val);

#endif
