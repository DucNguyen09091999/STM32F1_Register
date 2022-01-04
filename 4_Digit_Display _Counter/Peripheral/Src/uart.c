/*
 * uart.c
 *
 *  Created on: Jan 3, 2022
 *      Author: Nguyen Chi Duc

 */

/*
 * @brief declare libraries
 */
#include "uart.h"



/*
 * Set-Up UART1
 * Set-up UART (PA9 --> TX -- PA10 --> RX and GPIO)
 * configuration UART peripheral settings such as Baund rate
 * printf link to UART
 * Add Floating point flag
 */


/*
 * @brief UART1 GPIO configuration
 */
void uart_UART1_GPIO_Configuration(void)
{
  //PA9 --> TX ------ PA10 --> RX
  //Enable clock for port A
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
  //Configuration to Alternative function(AF) UART1
  //Configuration for PA9(TX)
  GPIOA->CRH &= ~(GPIO_CRH_CNF9);
  GPIOA->CRH |=  (GPIO_CRH_CNF9_1); //Output mode at 10MHz
  //Configuration for PA10(RX)
  GPIOA->CRH &= ~(GPIO_CRH_CNF10);
  GPIOA->CRH |=  (GPIO_CRH_CNF10_0);//Input mode at floating input
  //Output mode  max 10MHz
  GPIOA->CRH &= ~(GPIO_CRH_MODE9);
  GPIOA->CRH |=  (GPIO_CRH_MODE9_0);//TX is output
  GPIOA->CRH &= ~(GPIO_CRH_MODE10); //RX is input
  //Mapping PA9 and PA10 to UART1
  RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; //Enable alternate function IO clock enable
  //Configuration UART1 Remap (PA9-PA10)
  AFIO->MAPR &= ~(AFIO_MAPR_USART1_REMAP);

}

/*
 * @brief UART1 Peripheral Configuration
 */
void uart_UART1_Configuration(void)
{
  //Enable UART1 clock
  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
  //Enable transmit
  USART1->CR1 |= USART_CR1_TE;
  //Parity to Even (Even parity)
  USART1->CR1 &= ~(USART_CR1_PS);
  //Parity control enable
  USART1->CR1 &= ~(USART_CR1_PCE);
  //Word length to 8 bits
  USART1->CR1 &= ~(USART_CR1_M);
  //Stop bit to 1
  USART1->CR2 &= ~(USART_CR2_STOP);
  //Disable HW flow control
  //Disable RTS HW flow control disable
  USART1->CR3 &= ~(USART_CR3_RTSE);
  //Disable CTS HW flow control disable
  USART1->CR3 &= ~(USART_CR3_CTSE);
  //Set Baud rate to 115200
   /*
    * TX/RX Baud rate = F_ck / (16*USARTDN) = 72000000 / (16*115200) = 39.0625
    * Mantissa = 39
    * Fraction = 0.0625*16 = 1
    * Fraction(USARTDIV) = 1/ 16 =0.0625
    */
  //Reset BRR (Baud rate register)
  USART1->BRR = 0;
  //Mantissa field
  USART1->BRR |= (39UL << (4U));
  USART1->BRR |= (1UL << (0U));
  //Clear some flag and enable
  //LIN mode and CK pin are disable
  USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN);
  USART1->CR3 &= ~(USART_CR3_HDSEL | USART_CR3_IREN | USART_CR3_SCEN);
  //Enable UART
  USART1->CR1 |= USART_CR1_UE;
}

/*
 * @brief UART1 Transmit configuration
 */
bool uart_UART1_Transmit(uint8_t *data,uint8_t length, uint8_t timeout)
{
  //Wait on TXE to start transmit
  //Wait to DR as TXE flag is high (TX buffer empty)
  uint8_t dataIdx = 0;
  uint32_t startTick = rcc_GetmsTicks();
  while(dataIdx < length)
  {
    if ((USART1-> SR & USART_SR_TXE)) //TX buffer empty
    {
      USART1->DR = data[dataIdx];
      dataIdx++;
    }
    else
    {
      //Management timeout
      if((rcc_GetmsTicks() - startTick) >= timeout) return false;
    }
  }

  //while for busy flag
  while((USART1-> SR & USART_SR_TC))
  {
    if((rcc_GetmsTicks() - startTick) >= timeout) return false;
  }

  return true;
}
