/*
 * printf_redirect.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */


#include "main.h"

int __io_putChar(int Ch);
int _write(int file, char *ptr , int length);
int __io_putChar(int Ch)
{
uint8_t c[1];
c[0] = Ch & 0xFFFF;
uart_UART1_Transmit(&c[0], 1, 100);
return Ch;
}

int _write(int file, char *ptr , int length)
{
int DataIdx;
for (DataIdx=0; DataIdx < length ; DataIdx++)
{
  __io_putChar(*ptr++);
}
return length;
}
