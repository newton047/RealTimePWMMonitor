#ifndef _H_DEBUG_PORT_H_
#define _H_DEBUG_PORT_H_

/**
 * @file DebugPort.h
 * @brief UART debug output module for STM32F401
 * 
 * Provides serial communication via USART2 on PA2 (TX) and PA3 (RX).
 * Baud rate: 9600 (configured for 1MHz APB1 clock)
 * Used for sending debug data to host computer.
 */

#include <stm32f4xx.h>

#define UART_TX_PIN  2  /* PA2 - USART2 TX */
#define UART_RX_PIN  3  /* PA3 - USART2 RX */

/**
 * @brief Initialize UART debug port (USART2)
 * - Configures PA2/PA3 as alternate function (AF7)
 * - Sets up USART2 with 9600 baud rate
 * - Enables transmitter
 */
void DebugPortInit();

/**
 * @brief Send data string over UART
 * @param data Pointer to data buffer
 * @param length Number of bytes to send
 * 
 * @note This is a blocking call - waits for each character to be transmitted
 */
void DebugPortSend(char* data, int length);

#endif
