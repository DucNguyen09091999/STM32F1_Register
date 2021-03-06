/*
 * gpio.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */


#include "gpio.h"

/*
 * @brief LEDs GPIO configuration PB13 -- PB14
 */
void gpio_LEDs_Configuration(void)
{
//Enable clock for portB
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
  //Configuration GPIO as output 2MHz
  GPIOB->CRH &= ~(GPIO_CRH_MODE13);
  GPIOB->CRH |=  (GPIO_CRH_MODE13_1);
  GPIOB->CRH &= ~(GPIO_CRH_MODE14);
  GPIOB->CRH |=  (GPIO_CRH_MODE14_1);
  //Set up push - pull output
  GPIOB->CRH &= ~(GPIO_CRH_CNF13);
  GPIOB->CRH &= ~(GPIO_CRH_CNF14);

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
void gpio_LEDs_WritePB14(bool state)
{
  if(state)
    {
      GPIOB->ODR |= (0x1UL <<(14U));
    }
    else
    {
      GPIOB->ODR &= ~(0x1UL <<(14U));
    }
}

/*
 * @brief Toggle function
 */

void gpio_LEDs_TogglePB13(void)
{
  GPIOB->ODR ^= (0x1UL <<(13U));
}
void gpio_LEDs_TogglePB14(void)
{
  GPIOB->ODR ^= (0x1UL <<(14U));
}
