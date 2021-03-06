/*
 * gpio.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */


#include "gpio.h"

/*
 * @brief LEDs GPIO configuration PB13
 */
void gpio_LEDs_Configuration(void)
{
//Enable clock for portB
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
  //Configuration GPIO as output 2MHz
  GPIOB->CRH &= ~(GPIO_CRH_MODE13);
  GPIOB->CRH |=  (GPIO_CRH_MODE13_1);

  //Set up push - pull output
  GPIOB->CRH &= ~(GPIO_CRH_CNF13);


}

/*
 * @brief Write function
 */

void gpio_LEDs_WritePB13(bool state)
{
  if(state)
  {
    GPIOB->ODR |= (0x1UL <<(13U));
  }
  else
  {
    GPIOB->ODR &= ~(0x1UL <<(13U));
  }
}



/*
 * @brief Push-Button function PA0
 */

void gpio_PB_Configuration()
{
	//Enable clock for port A
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	//FLoating input
	GPIOA->CRL &= ~(GPIO_CRL_CNF0);
	GPIOA->CRL |=  (GPIO_CRL_CNF0_0);
	//Input mode
	GPIOA->CRL &= ~(GPIO_CRL_MODE0);
}

/*
 * @brief read PB function
 */
bool gpio_PB_Read(void)
{
	return (bool)(GPIOA->IDR & GPIO_IDR_IDR0);
}
