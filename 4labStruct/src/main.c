#include "CMSIS/stm32f10x.h"
#include <stdint.h>

struct data{          //объявляем структуру
    int32_t buf[11];
    int size;
};

void sort(struct data str) //Сортировка перемешиванием
{
	uint32_t i, bot=0, top=str.size-1;
	int32_t c;
	
	while(bot<top)
	{
		
		for (i=bot; i<top; i++) //проход вверх
		{
			if (str.buf[i] > str.buf[i+1])
			{
				c=str.buf[i];
				str.buf[i]=str.buf[i+1];
				str.buf[i+1]=c;
			}
		}
		top--;
		
		for(i=top; i>bot; i--) //проход вниз
		{
			if (str.buf[i] < str.buf[i-1])
			{
				c=str.buf[i];
				str.buf[i]=str.buf[i-1];
				str.buf[i-1]=c;
			}
		}
		bot++;
	}
}

/*
int32_t getMedian(int32_t * buf, uint32_t size)
{
  int32_t res[size], c;
	uint32_t i=0;
  
	
	for (i=0; i<size; i++)
	{ res[i]=buf[i]; }
	
//sort(res,size);
	
	return res[size/2];
}
*/

int main(void)
{
	int32_t Sort[11]={20,25,15,23,15,12,2,3,11,5,7};
  struct data input; //Создаём структуру
  int i;             
  
  
  input.size = 11; //заполняем поле size структуры
  
  for(i = 0; i<input.size; i++) //заполняем поле buf структуры, копируем массив
  {
      input.buf[i] = Sort[i];
  }
  

	sort(input); //вызываем функцию и передаём в неё структуру
	
	//int32_t Median[13]={20,25,15,18,50,23,15,12,2,48,3,11,5};
	//int32_t median = getMedian(Median, 13);
	
	while(1)
	return 0;
}
