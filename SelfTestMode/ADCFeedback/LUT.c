/**
 * @file LUT.c
 * @brief Lookup table for PWM duty cycle to expected ADC voltage mapping
 * 
 * This table maps each PWM duty cycle level (0-10) to the expected
 * ADC feedback voltage. If the actual reading differs from the expected
 * value by more than ±0.2V, an error is flagged.
 */

/** 
 * @brief Lookup table: Expected ADC voltage for each duty cycle (0-10)
 * 
 * Index corresponds to duty cycle:
 * - Index 0: Duty cycle 0% -> Expected voltage 0.74V
 * - Index 1: Duty cycle 10% -> Expected voltage 0.96V
 * - ...
 * - Index 10: Duty cycle 100% -> Expected voltage 3.3V
 * 
 * Tolerance band: ±0.2V from table value
 */
float LUT_ADC_vals[] = { 0.74, 0.96, 1.22, 1.43, 1.66, 1.9, 2.15, 2.35, 2.6, 2.9, 3.2, 3.3 };
