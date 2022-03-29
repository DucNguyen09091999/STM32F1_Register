/*
 * PB_EXTI.c
 *
 *  Created on: Mar 28, 2022
 *      Author: Nguyen Chi Duc
 */

#include "PB_EXTI.h"

/*
 * @brief configuration PA0 as a EXTI interrupt
 */

void exti_PB_config(void)
{
  //enable AFIO clock
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
   //PA0 map to EXTI0 0000
  AFIO->EXTICR[0] &= ~(AFIO_EXTICR1_EXTI0);
  //Unblock EXTI0 interrupt --- Interrupt mask register
  EXTI->IMR |= EXTI_IMR_IM0;
  //Enable rising edge only --- Rising trigger selection
  EXTI->RTSR |= EXTI_RTSR_TR0;
  EXTI->FTSR &= ~(EXTI_RTSR_TR0);

  //Set priority
  NVIC_SetPriority(EXTI0_IRQn,5);
  //Enable external interrupt
  NVIC_EnableIRQ(EXTI0_IRQn);
}

