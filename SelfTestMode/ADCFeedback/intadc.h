#ifndef _H_INTADC_H_
#define _H_INTADC_H_

/**
 * @file intadc.h
 * @brief ADC input module for STM32F401
 * 
 * Provides analog-to-digital conversion on PA0 using ADC1.
 * Conversion results are 12-bit resolution (0-4095).
 * Voltage range: 0-3.3V
 */

#include <stm32f4xx.h>

/** ADC conversion factor: 3.3V / 4096 counts = ~0.805 mV/count */
#define ADC_FACTOR  (float)(3.3/4096)
#define PORTA_PIN_NO    0
#define ADC_CHANNEL     0

/**
 * @brief Initialize ADC hardware on PA0
 * - Configures PA0 as analog input
 * - Enables GPIOA clock
 */
void IntADCInit();

/**
 * @brief Start ADC and configure conversion settings
 * - Enables ADC1 clock (APB2)
 * - Sets 12-bit resolution
 * - Sets channel 0 with maximum sampling time
 * - Enables ADC
 */
void IntADCStart();

/**
 * @brief Read raw ADC value (blocking)
 * @return Raw ADC count (0-4095)
 */
int readAdc();

/**
 * @brief Convert raw ADC count to voltage
 * @param val Raw ADC count (0-4095)
 * @return Voltage in volts (0.0-3.3)
 */
float ConvertToVoltage(int val);

#endif


