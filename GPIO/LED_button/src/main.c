#include "CMSIS/stm32f10x.h"

int main(void)
{
  RCC->APB2ENR|=1<<4; //enable port C for LED  
  RCC->APB2ENR|=1<<2; //enable port A for button    
 
  GPIOC->CRH&=0xFFFFFFF0; //Set PC.8 in 0001 - 00(General purpose output push-pull), 01(Output mode)
  GPIOC->CRH|=1;
  GPIOA->CRL&=0xFFFFFFF0;    //0x4 - 01(Floating input) 00(Input mode) for PA.0
  GPIOA->CRL|=0x4;
  
	while(1)
	{
    switch(GPIOA->IDR&1)
    {
        case 1: GPIOC->ODR|=1<<8; break;  //set 8 bit = 1 - PC.8 LED on
        case 0: GPIOC->ODR&=~(1<<8); break;//set 8 bit = 0 - PC.8 LED off
    }    
	}
	return 0;
}
