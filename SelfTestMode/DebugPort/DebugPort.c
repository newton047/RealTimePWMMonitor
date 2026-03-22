#include "DebugPort.h"

/**
 * @brief Initialize UART GPIO pins (PA2 TX, PA3 RX)
 * 
 * Configuration:
 * - GPIOA clock enabled
 * - PA2 and PA3 configured as alternate function AF7 (USART2)
 */
void UARTPinInit(){
	/* Enable clock to GPIOA */
	RCC->AHB1ENR |= (1 << 0);

	/* Set PA2 as alternate function */
	GPIOA->MODER &= ~(0x3 << 2 * UART_TX_PIN);
	GPIOA->MODER |= (0x2 << 2 * UART_TX_PIN);

	/* Set PA3 as alternate function */
	GPIOA->MODER &= ~(0x3 << 2 * UART_RX_PIN);
	GPIOA->MODER |= (0x2 << 2 * UART_RX_PIN);

	/* Set PA2 alternate function to AF7 (USART2) */
	GPIOA->AFR[0] &= ~(0xF << (4 * UART_TX_PIN));
	GPIOA->AFR[0] |= (0x7 << (4 * UART_TX_PIN));

	/* Set PA3 alternate function to AF7 (USART2) */
	GPIOA->AFR[0] &= ~(0xF << (4 * UART_RX_PIN));
	GPIOA->AFR[0] |= (0x7 << (4 * UART_RX_PIN));
}

/**
 * @brief Initialize USART2 for transmission at 9600 baud
 * 
 * Configuration:
 * - USART2 clock enabled (APB1 at 1MHz)
 * - 8 data bits, 1 stop bit
 * - Baud rate: 9600 (BRR = 0x68)
 * - Transmitter enabled
 */
void UARTTXInit(){
	UARTPinInit();
	
	/* Enable clock to USART2 on APB1 (1MHz) */
	RCC->APB1ENR |= (1 << 17);

	/* Set 8 data bits (CR1[M] = 0) */
	USART2->CR1 &= ~(1 << 12);

	/* Set 1 stop bit (CR2 stop bits = 00) */
	USART2->CR2 &= ~(0x3 << 12);

	/* Set baud rate to 9600 for 1MHz clock */
	uint32_t BRR_Val = 0;
	BRR_Val |= (6 << 4) | 8;  /* BRR = 0x68 = 104 decimal */
	USART2->BRR = BRR_Val;

	/* Enable transmitter */
	USART2->CR1 |= (1 << 3);
	
	/* Enable USART2 */
	USART2->CR1 |= (1 << 13);
}

/**
 * @brief Send a buffer of data over UART
 * @param data Pointer to data buffer
 * @param len Number of bytes to send
 */
void UARTSend(char *data, int len){
	for(int i = 0; i < len; i++){
		UARTSendChar(data[i]);
	}
}

/**
 * @brief Send a single character over UART (blocking)
 * Waits for transmit buffer to be empty before sending,
 * and waits for transmission complete before returning.
 * @param tosend Character to send
 */
void UARTSendChar(char tosend){
	/* Wait for transmit data register empty */
	while(!(USART2->SR & (1 << 7)));
	
	/* Send character */
	USART2->DR = tosend;
	
	/* Wait for transmission complete */
	while(!(USART2->SR & (1 << 6)));
}

/**
 * @brief Initialize debug port (USART2)
 */
void DebugPortInit(){
	UARTTXInit();
}

/**
 * @brief Send data string over debug port
 * @param data Pointer to data buffer
 * @param length Number of bytes to send
 */
void DebugPortSend(char* data, int length){
	UARTSend(data, length);
}

