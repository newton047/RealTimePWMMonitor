#include "filter.h"

/**
 * @brief Apply exponential moving average filter to smooth ADC readings
 * 
 * Filter equation: new_avg = old_avg + alpha * (current - old_avg)
 * With alpha = 0.5, this gives equal weight to recent and past values.
 * 
 * @param val Current raw ADC voltage value
 * @return Filtered voltage value (0.0-3.3V)
 */
float mv_filter(float val){
	static float old_avg = 0;
	float alpha = 0.5;  /* Smoothing factor (0-1, higher = more responsive) */

	/* Calculate new filtered value */
	float new_avg = old_avg + alpha * (val - old_avg);
	old_avg = new_avg;

	return new_avg;
}
