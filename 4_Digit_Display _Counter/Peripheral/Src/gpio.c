/*
 * gpio.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */


#include "gpio.h"

/*
 * @brief TM1637 LED display GPIO configuration
 */
void gpio_Tm1637_config(void)
{
	//CLK --> PB10
	//DIO --> PB11
	//Enable port B clock
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	//Output mode at 2 MHz
	GPIOB->CRH &= ~(GPIO_CRH_MODE10);
	GPIOB->CRH |= ~(GPIO_CRH_MODE10_1);
	GPIOB->CRH &= ~(GPIO_CRH_MODE11);
	GPIOB->CRH |= ~(GPIO_CRH_MODE11_1);
	//General purpose output push pull
	GPIOB->CRH &= ~(GPIO_CRH_CNF10);
	GPIOB->CRH &= ~(GPIO_CRH_CNF11);
}
