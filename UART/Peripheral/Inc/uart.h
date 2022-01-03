/*
 * uart.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

/*
 * @brief UART1 GPIO configuration
 */
void uart_UART1_GPIO_Configuration(void);

/*
 * @brief UART1 Peripheral Configuration
 */
void uart_UART1_Configuration(void);

/*
 * @brief UART1 Transmit configuration
 */
bool uart_UART1_Transmit(uint8_t *data,uint8_t length, uint8_t timeout);

#endif /* INC_UART_H_ */
