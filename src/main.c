#include "CMSIS/stm32f10x.h"
#include <stdint.h>

int32_t strToInt(const char *str)
{
	int64_t result = 0;
	int i = 0;
	_Bool flagMinus = 0;
	_Bool flagPlus = 0;
	
	while(str[i] != '\0')
	{		
		if (str[i] == '-' && !flagPlus)				// Если обнаружен знак '-' и до этого не обнаруживалось цифр, то число отрицательное
			flagMinus = 1;
		
		if (str[i] >=48 && str[i] <=57)
		{
			flagPlus = 1;															// Если обнаружена цифра, обновить флаг
			result = result * 10 + str[i] - 48;
		}
		
		i++;
	}
		
	if (flagMinus)
		result = -result;
	
	return result;
}

uint8_t countSetBits(uint32_t n)
{
	uint8_t result = 0;
	
	uint32_t nOld;
	uint32_t mask = 1; 					// Маска с единицей в одном(правом) разряде
	
	while	(mask<=0x80000000)
	{
		nOld = n;
		n |= mask;
		
		if (nOld == n) result++; 			// Если при применении маски не изменилось число, значит в разряде, в котором у маски стоит 1, у числа тоже стоит 1
		
		if (mask < 0x80000000)
			mask <<= 1; 						// Сдвиг единицы на 1 влево, если 1 не в самом левом разряде
		else
			break;
	}
	
	return result;
}

uint8_t countLeadingZeros( uint32_t n)
{
	uint8_t result = 0;
	
	uint32_t nOld;
	uint32_t mask = 0x80000000; // Маска с единицей в одном(левом) разряде
	
	while	(mask >= 1)
	{
		nOld = n;
		n |= mask;
		
		if (nOld != n)
			result++;										// Если при применении маски не изменилось число, значит в разряде, в котором у маски стоит 1, у числа тоже стоит 1
		else
			return result;

		mask >>= 1; 							// Сдвиг единицы на 1 вправо
	}
	
	return 32;											// Если не нули не найдены, значит это число 0, оно целиком состоит из 0
}

int main(void)
{
	int32_t numberInt;
	const char numberStr[12] = "3d-s89ds5a"; // 12, т.к. самое длинное число -2147483648 (+ символ '\0')
	numberInt = strToInt (numberStr);
	
	uint8_t numberOnes;
	numberOnes = countSetBits (15);
	
	uint8_t numberZeros;
	numberZeros = countLeadingZeros(5);
	
	while(1)
	return 0;
}
