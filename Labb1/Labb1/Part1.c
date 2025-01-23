/*
 * Part1.c
 *
 * Created: 2025-01-23 13:14:36
 *  Author: albin
 */ 
#include <avr/io.h>

typedef struct {
	int one;
	int two;
	int three;
	int four;
	int five;
	
} characters;

void LCDinit()
{
	CLKPR = 0b10000000;
	LCDCRA = 0b11000000;
	LCDCRB = 0b10110111;
	LCDFRR = 0b00000111;
	LCDCCR = 0b00001111;
	
	characters chs;
	chs.one = 1;
	chs.two = 2;
	chs.three = 3;
	chs.four = 4;
	chs.five = 5;
}

void writeChar(char ch, int pos)
{
	switch (ch)
	{
		case '0'
	}
}
