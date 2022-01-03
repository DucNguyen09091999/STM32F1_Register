/*
 * rcc.c
 *
 *  Created on: Jan 2, 2022
 *      Author: Nguyen Chi Duc

 */

/*
 * @brief declare libraries
 */
#include "rcc.h"

/*
 * @brief declare variables
 */

//ms Tick delay
static __IO uint32_t msTicks = 0;


/**
 * @brief HSE configuration
 */

void rcc_HSE_Configuration(void)
{
  /*
   * Configuration parameter --> Clock tree for STM32F103
   * Input frequency of HSE = 8 MHz
   * PLL_MUX = 9
   * USB Pre-scaler = 1
   * AHB Pre-Scaler = 1
   * Cortex Pre-scaler = 1
   * --> 72MHz system clock configuration
   *
   * Configuration parameter for peripheral
   * APB1 Pre-scaler = 2 --> 36MHz and 72MHz
   * APB2 Pre-scaler = 1 --> 72MHz and 72MHz
   * ADC Pre-scaler = 6 --> ADC 12MHz
   *
   */

  /*
   * Clock_Mux configuration
   */

  //PLL_Mux configuration
  RCC->CFGR &= ~(RCC_CFGR_PLLMULL); //Clear PLL Mux fields
  RCC->CFGR |= RCC_CFGR_PLLMULL9; //PLL 8MHz *9 = 72MHz
  //USB Pre-scaler
  RCC->CFGR |= RCC_CFGR_USBPRE; //PLL clock is not divided


  /*
   * HSE configuration
   */
  //Enable HSE oscillator
  RCC->CR |= RCC_CR_HSEON;
  //Wait for it to stabilize
  while((RCC->CR & RCC_CR_HSERDY) == 0);
  //Select HSE as PLL source
  RCC->CFGR |= RCC_CFGR_PLLSRC;
  //Enable PLL
  RCC->CR |= RCC_CR_PLLON;
  //Wait for PLL ready
  while((RCC->CR & RCC_CR_PLLRDY) == 0 );

  /*
   * Set-up latency
   *Flash Pre-fetch and wait state configuration
   *Flash 2 wait state = 72MHz
   */

  //Configuration LATENCY field is Two wait state (72MHz)
  FLASH->ACR &= ~(FLASH_ACR_LATENCY_Msk);
  FLASH->ACR |= FLASH_ACR_LATENCY_1;
  //Enable Pre-fetch buffer
  FLASH->ACR |= FLASH_ACR_PRFTBE;


  /*
   * Select system clock
   */

  //Select HSE as system clock
  RCC->CFGR &= ~(RCC_CFGR_SW);
  RCC->CFGR |= RCC_CFGR_SW_1;

  //Wait for PLL to be the active CLK source
  while((RCC->CFGR & RCC_CFGR_SW_1) == 0);

  /*
   * Configuration for peripheral
   */

  //APB1 configuration
  RCC->CFGR &= ~(RCC_CFGR_PPRE1);
  RCC->CFGR |= RCC_CFGR_PPRE1_2;
  //APB2 configuration
  RCC->CFGR &= ~(RCC_CFGR_PPRE2);
  //ADC Pre-scaler configuration
  RCC->CFGR &= ~(RCC_CFGR_ADCPRE);
  RCC->CFGR |= RCC_CFGR_ADCPRE_1;

}

/**
 * @brief sysTick timer configuration
 */
  void rcc_Systick_Configuration(uint32_t arr)
  {
    //Reset SysTick Control and Status Register
    //10.1 Nested vectored interrupt controller (NVIC)
    SysTick->CTRL  = 0;
   //Set the Re-load value (get reload value)
    SysTick->LOAD = arr -1;//Beginning at 0 position
    //Enable SysTick Interrupt (NVIC)
    NVIC_SetPriority(SysTick_IRQn,0); //Interrupt and Priority
    //Reset SysTick Value to 0
    SysTick->VAL = 0;
    //Enable SysTick from Control register
    //Enable sysTick source
    SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
    //Enable sysTick interrupt
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
    //Enable sysTick timer or counter
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;


  }


   /*
    * @brief Increment Milli-Second Ticks
    */
  void rcc_MsTicks(void)
  {
    msTicks++;
  }


   /*
    * @brief Get Milli-Second Ticks
    */
  uint32_t rcc_GetmsTicks(void)
  {
    return msTicks;
  }
   /*
    * @brief Milli_Second Ticks delay
    */
  void rcc_MsTicks_Delay(uint32_t millisecond)
  {
    uint32_t startTicks = rcc_GetmsTicks();
    while((rcc_GetmsTicks() - startTicks) < millisecond);
  }

  /*
   * @brief SysTicks Interrupt callback
   */
  void SysTick_Handler(void)
  {
    NVIC_ClearPendingIRQ(SysTick_IRQn);
    rcc_MsTicks();
  }
