/*
 * main.h
 *
 *  Created on: Jan 2, 2022
 *      Author: Nguyen Chi Duc

 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "stm32f103xb.h"
#include <stdbool.h>
#include <stdio.h>
#include "rcc.h"
#include "uart.h"
#include "tm1637.h"
#include "gpio.h"
//TM1637 Digit pin
#define Digit_Port GPIOB
#define Digit_CLK_Pin (1UL << 10)
#define Digit_DIO_Pin (1UL << 11)
#endif /* INC_MAIN_H_ */
