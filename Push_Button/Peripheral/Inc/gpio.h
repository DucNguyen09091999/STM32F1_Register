/*
 * gpio.h
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

/*
 * @brief LEDs GPIO configuration PB13
 */
void gpio_LEDs_Configuration(void);

/*
 * @brief Write function
 */

void gpio_LEDs_WritePB13(bool state);


/*
 * @brief Toggle function
 */


void gpio_PB_Configuration();


/*
 * @brief read PB function
 */
bool gpio_PB_Read(void);
#endif /* INC_GPIO_H_ */
