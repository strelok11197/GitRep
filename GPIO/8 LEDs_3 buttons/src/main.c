#include "CMSIS/stm32f10x.h"

int main(void)
{   
  RCC->APB2ENR|=1<<2; //enable port A for 0-7 pins LED
  RCC->APB2ENR|=1<<3; //enable port B for 0-2 buttons

  GPIOA->CRL|=0x11111111;   //Set in 0001 - 00(General purpose output push-pull), 01(Output mode)

  GPIOB->CRL&=0xFFFFF000;
  GPIOB->CRL|=0x888;        //input with pull-up/down

  uint32_t q=0;
  
  while(1)
  {
    GPIOA->ODR=(q|=1<<(GPIOB->IDR));
    q=0;
  }
  
  return 0;
}  