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
 * @brief LEDs GPIO configuration PB13 -- PB14
 */
void gpio_LEDs_Configuration(void);

/*
 * @brief Write function
 */

void gpio_LEDs_WritePB13(bool state);


/*
 * @brief Toggle function
 */

void gpio_LEDs_TogglePB13(void);

#endif /* INC_GPIO_H_ */
