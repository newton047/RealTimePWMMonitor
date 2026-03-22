#ifndef _H_MOTOR_H
#define _H_MOTOR_H

/**
 * @file motor.h
 * @brief Motor PWM control module for STM32F401
 * 
 * Controls motor speed via PWM on TIM2 Channel 2 (PA1).
 * PWM resolution: 0-10 duty cycle (11 levels)
 * Base frequency: 2MHz clock / prescaler configuration
 */

#include <stm32f4xx.h>

#define MOTOR_GPIO_PORT  GPIOA
#define MOTOR_GPIO_PIN   1

/**
 * @brief Initialize motor PWM hardware
 * - Configures PA1 as alternate function for TIM2_CH2
 * - Sets up clock division for APB1
 */
void MotorInt();

/**
 * @brief Start PWM generation on motor pin
 * - Enables TIM2 clock
 * - Configures prescaler and ARR for desired frequency
 * - Sets PWM mode and enables channel 2
 * Duty cycle range: 0-10
 */
void MotorStart();

/**
 * @brief Update motor speed
 * @param dutycycle PWM duty cycle value (0-10)
 */
void MotorSpeedUpdate(int dutycycle);

/**
 * @brief Stop PWM generation (duty cycle = 0)
 */
void MotorStop();

#endif
