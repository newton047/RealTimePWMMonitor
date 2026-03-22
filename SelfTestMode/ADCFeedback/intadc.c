#include "intadc.h"

/**
 * @brief Initialize ADC hardware (PA0 input)
 * 
 * Configuration:
 * - GPIOA clock enabled
 * - PA0 configured as analog input
 */
void IntADCInit(){
	/* Enable clock to GPIOA */
	RCC->AHB1ENR |= (0x1 << 0x0);
	
	/* Configure PA0 as analog mode (MODER = 11) */
	GPIOA->MODER |= (0x3 << (PORTA_PIN_NO * 2));
}

/**
 * @brief Start ADC1 with channel 0
 * 
 * Configuration:
 * - ADC1 clock enabled (APB2)
 * - 12-bit resolution
 * - Channel 0 with maximum sampling time
 * - Regular channel sequence length = 1
 */
void IntADCStart(){
	/* Enable ADC1 clock on APB2 */
	RCC->APB2ENR |= (1 << 8);

	/* Select 12-bit resolution (default) */
	ADC1->CR1 &= ~(0x3 << 24);

	/* Set regular channel sequence length to 1 */
	ADC1->SQR1 &= ~(0xF << 20);

	/* Set first position in sequence as channel 0 */
	ADC1->SQR3 &= ~(0xF << 0);
	ADC1->SQR3 |= (ADC_CHANNEL << 0);

	/* Set maximum sampling time on channel 0 */
	ADC1->SMPR2 |= (0x7 << 0);
	ADC1->SMPR2 |= (0x7 << (3 * ADC_CHANNEL));

	/* Enable ADC */
	ADC1->CR2 |= (1 << 0);
}

/**
 * @brief Read raw ADC value (blocking call)
 * Starts conversion and waits for completion
 * @return Raw ADC count (0-4095 for 12-bit)
 */
int readAdc(){
	int val;

	/* Start conversion */
	ADC1->CR2 |= (1 << 30);

	/* Wait for end of conversion */
	while(!(ADC1->SR & (1 << 1)));

	/* Read data register */
	val = ADC1->DR;

	return val;
}

/**
 * @brief Convert raw ADC count to voltage
 * @param val Raw ADC count (0-4095)
 * @return Voltage in volts (0.0-3.3V)
 */
float ConvertToVoltage(int val){
	return (float)val * ADC_FACTOR;
}

