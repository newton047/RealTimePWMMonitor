#include "motor.h"

/**
 * @brief Initialize motor PWM hardware (TIM2 on PA1)
 * 
 * Configuration:
 * - GPIOA clock enabled
 * - PA1 set to alternate function AF1 (TIM2_CH2)
 * - APB1 prescaler set to divide by 16 (1MHz)
 */
void MotorInt(){
	/* Set clock source as HSI (default 16MHz) */

	/* Set clock division to make APB1 as 1MHz */
	RCC->CFGR &= ~(0x7 << 10);
	RCC->CFGR |= (0x7 << 10);   /* Divide by 16: 111 */

	/* Enable clock for GPIOA, used for TIM2_CH2 */
	RCC->AHB1ENR |= (0x1 << 0x0);

	/* Set PA1 mode as alternate function */
	MOTOR_GPIO_PORT->MODER &= ~(0x3 << (2 * MOTOR_GPIO_PIN));
	MOTOR_GPIO_PORT->MODER |= (0x2 << (2 * MOTOR_GPIO_PIN));

	/* Set alternate function as AF1 (TIM2) */
	MOTOR_GPIO_PORT->AFR[0] &= ~(0xF << (4 * MOTOR_GPIO_PIN));
	MOTOR_GPIO_PORT->AFR[0] |= (0x1 << (4 * MOTOR_GPIO_PIN));
}

/**
 * @brief Start PWM generation on TIM2 Channel 2
 * 
 * Configuration:
 * - TIM2 prescaler = 1 (clock = 1MHz)
 * - ARR (auto-reload) = 10 (period = 10µs, frequency = 100kHz)
 * - PWM mode enabled on channel 2
 * - Initial duty cycle = 0
 */
void MotorStart(){
	/* Enable clock for TIM2 */
	RCC->APB1ENR |= (0x1 << 0);

	/* Set prescaler for internal clock (2MHz -> 1MHz division) */
	TIM2->PSC = (1);

	/* Set auto-reload register for 10 counts */
	TIM2->ARR = 9;

	/* Configure channel 2 as PWM mode */
	TIM2->CCMR1 &= ~(0x7 << 12);
	TIM2->CCMR1 |= (0x6 << 12);   /* PWM mode */
	TIM2->CCMR1 |= (1 << 11);     /* Preload enabled */

	/* Enable output on channel 2 */
	TIM2->CCER |= (1 << 4);

	/* Set initial duty cycle to 0 */
	TIM2->CCR2 = 0;

	/* Generate update event to load preload values */
	TIM2->EGR |= (1 << 0);

	/* Enable preload and timer */
	TIM2->CR1 |= (1 << 7);  /* Enable preload */
	TIM2->CR1 |= (1 << 0);  /* Enable timer */
}

/**
 * @brief Update motor PWM duty cycle
 * @param dutycycle PWM duty cycle (0-10, corresponds to 0-100%)
 */
void MotorSpeedUpdate(int dutycycle){
	TIM2->CCR2 = dutycycle;
}

/**
 * @brief Stop motor (PWM duty cycle = 0)
 */
void MotorStop(){
	TIM2->CCR2 = 0;
}

