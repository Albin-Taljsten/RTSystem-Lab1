/*
 * Part1.c
 *
 * Created: 2025-01-23 13:14:36
 *  Author: albin
 */ 
#include <avr/io.h>
#include <ctype.h>

// Numbers: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int num[] = {0x1551, 0x0110, 0x1e11, 0x1b11, 0x0b50, 0x1b41, 0x1f41, 0x0111, 0x1f51, 0x0b51};

void LCDinit()
{
	CLKPR = 0b10000000;
	LCDCRA = 0b11000000;
	LCDCRB = 0b10110111;
	LCDFRR = 0b00000111;
	LCDCCR = 0b00001111;
}

void writeChar(char ch, int pos)
{
	if ((pos > 5) || (pos < 0))
	{
		return;
	}
	else
	{
		if (!isdigit(ch))
		{
			return;
		}
		else
		{
			int n = ch - '0';
			int displayNum = num[n];
			LCDDR15 = (0xf000 & displayNum);
			LCDDR10 = (0x0f00 & displayNum);
			LCDDR5 = (0x00f0 & displayNum);
			LCDDR0 = (0x000f & displayNum);
		}
	}
}
