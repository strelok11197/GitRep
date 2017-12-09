#include "CMSIS/stm32f10x.h"

int main(void)
{
  RCC->APB2ENR|=RCC_APB2ENR_IOPCEN; //enable port C for LED  
  RCC->APB2ENR|=RCC_APB2ENR_IOPAEN; //enable port A for button    
  
  GPIOC->CRH&=0xFFFFFF00;           //Set PC.8 and PC.9 in 0001 - 00(General purpose output push-pull), 01(Output mode)
  GPIOC->CRH|=0x11;
  GPIOA->CRL&=0xFFFFFFF0;           //0x4 - 01(Floating input) 00(Input mode) for PA.0
  GPIOA->CRL|=0x4;
  
  uint32_t i; //счётчик
  
	while(1)
	{
		GPIOC->ODR|=1<<8;		            //set 8 bit = 1 - PC.8 LED on
    GPIOC->ODR&=~(1<<9); 	          //set 9 bit = 0 PC.9 LED off 
    for(i=0; i<1000000; i++){}      //delay
    
    GPIOC->ODR&=~(1<<8); 
    GPIOC->ODR|=1<<9;	
    for(i=0; i<1000000; i++){}
	}

	return 0;
}
