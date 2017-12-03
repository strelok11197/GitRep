#include "CMSIS/stm32f10x.h"
#include <stdint.h>

void sort(int32_t * buf, uint32_t size) //Сортировка перемешиванием
{
	uint32_t i, bot=0, top=size-1;
	int32_t c;
	
	while(bot<top)
	{
		
		for (i=bot; i<top; i++) //проход вверх
		{
			if (buf[i] > buf[i+1])
			{
				c=buf[i];
				buf[i]=buf[i+1];
				buf[i+1]=c;
			}
		}
		top--;
		
		for(i=top; i>bot; i--) //проход вниз
		{
			if (buf[i] < buf[i-1])
			{
				c=buf[i];
				buf[i]=buf[i-1];
				buf[i-1]=c;
			}
		}
		bot++;
	}
}


int32_t getMedian(int32_t * buf, uint32_t size)
{
	int32_t res[size], c;
	uint32_t i=0;
	
	for (i=0; i<size; i++)
	{ res[i]=buf[i]; }
	
	sort(res, size);
	
	return res[size/2];
}


int main(void)
{
	int32_t Sort[10]={20,25,15,23,15,12,2,3,11,5};
	sort(Sort, 10);
	
	int32_t Median[13]={20,25,15,18,50,23,15,12,2,48,3,11,5};
	int32_t median = getMedian(Median, 13);
	
	while(1)
	return 0;
}