/*
 * rcc.h
 *
 *  Created on: Jan 2, 2022
 *      Author: Nguyen Chi Duc

 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "main.h"

/**
 * @brief HSE configuration
 */

void rcc_HSE_Configuration(void);

/*
 * @brief sysTick timer configuration
 */
 void rcc_Systick_Configuration(uint32_t arr);

 /*
  * @brief Increment Milli-Second Ticks
  */
void rcc_MsTicks(void);


 /*
  * @brief Get Milli-Second Ticks
  */
uint32_t rcc_GetmsTicks(void);
 /*
  * @brief Milli_Second Ticks delay
  */
void rcc_MsTicks_Delay(uint32_t millisecond);

/*
 * @brief SysTicks Interrupt callback
 */
void SysTick_Handler(void);
#endif /* INC_RCC_H_ */
