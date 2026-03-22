#ifndef _H_FILTER_H_
#define _H_FILTER_H_

/**
 * @file filter.h
 * @brief Low-pass filter for ADC readings
 * 
 * Implements a moving average (exponential) filter
 * to smooth noisy ADC voltage readings.
 */

/**
 * @brief Apply moving average low-pass filter to ADC value
 * 
 * Uses exponential moving average with alpha = 0.5:
 * new_avg = old_avg + alpha * (current_reading - old_avg)
 * 
 * @param val Current ADC voltage reading
 * @return Filtered voltage value
 */
float mv_filter(float val);

#endif
