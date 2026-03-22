#ifndef _H_LUT_H_
#define _H_LUT_H_

/**
 * @file LUT.h
 * @brief Lookup table for duty cycle to voltage mapping
 * 
 * Maps PWM duty cycle (0-10) to expected ADC feedback voltage.
 * These are the target voltage values that should be read at each speed setting.
 * The system flags an error if the actual reading differs by more than ±0.2V.
 */

/** 
 * @brief Lookup table of expected ADC voltages for each duty cycle (0-10)
 * 
 * Duty cycle 0-10 maps to voltages (in volts):
 * 0 -> 0.74V
 * 1 -> 0.96V
 * 2 -> 1.22V
 * ... 
 * 10 -> 3.3V
 */
extern float LUT_ADC_vals[];

#endif
