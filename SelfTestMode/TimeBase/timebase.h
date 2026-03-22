#ifndef _H_TIMEBASE_H_
#define _H_TIMEBASE_H_

/**
 * @file timebase.h
 * @brief SysTick timer and callback scheduler
 * 
 * Provides periodic callback mechanism using SysTick interrupt.
 * Allows up to 10 concurrent callbacks at different intervals.
 * Resolution: 1ms (ticks every 1ms)
 */

#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

/**
 * @brief Callback node structure
 */
typedef struct {
	int time_delay;             /**< Callback interval in milliseconds */
	void (*callback)(void);     /**< Callback function pointer */
	int prev_value;             /**< Last tick count when callback ran */
} Callback_Node;

/**
 * @brief Notification chain for managing multiple callbacks
 */
typedef struct {
	Callback_Node Node[10];     /**< Array of callback nodes (max 10) */
	int len;                    /**< Current number of registered callbacks */
} NotficationChain;

/**
 * @brief Initialize SysTick timer at 1kHz (1ms period)
 * Enables SysTick interrupt and sets up callback system
 */
void TimeBaseInit();

/**
 * @brief Register a periodic callback function
 * 
 * @param milliseconds Callback interval in milliseconds
 * @param callback Function pointer to call periodically
 * @return 0 on success, -1 if callback table is full (max 10)
 * 
 * @note Callbacks are executed in SysTick interrupt context
 * @note Multiple callbacks can be registered at different intervals
 */
int TimeBaseRegisterCallback(int milliseconds, void* callback);

#endif
