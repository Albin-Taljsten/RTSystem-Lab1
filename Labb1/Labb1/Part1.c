/*
 * Part1.c
 *
 * Created: 2025-01-23 13:14:36
 *  Author: albin
 */ 
#include <avr/io.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// Numbers: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int num[] = {0x1551, 0x0110, 0x1e11, 0x1b11, 0x0b50, 0x1b41, 0x1f41, 0x0111, 0x1f51, 0x0b51};

void LCDinit()
{
	CLKPR  = 0x80;
	CLKPR  = 0x00;
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
			if (pos == 0 || pos == 1){
				LCDDR15 = LCDDR15 & ~(0xf << (4 * pos));
				LCDDR15 = LCDDR15 | (((0xf000 & displayNum) >> 12) << (4 * pos));
				LCDDR10 = LCDDR10 & ~(0xf << (4 * pos));
				LCDDR10 = LCDDR10 | (((0x0f00 & displayNum) >> 8) << (4 * pos));
				LCDDR5  = LCDDR5  & ~(0xf << (4 * pos));
				LCDDR5  = LCDDR5  | (((0x00f0 & displayNum) >> 4) << (4 * pos));
				LCDDR0  = LCDDR0  & ~(0xf << (4 * pos));
				LCDDR0  = LCDDR0  | ((0x000f & displayNum) << (4 * pos));
				return;
			}
			else if (pos == 2 || pos == 3){
				LCDDR16 = LCDDR16 & ~(0xf << (4 * (pos - 2)));
				LCDDR16 = LCDDR16 | ((0xf000 & displayNum) >> 12) << (4 * (pos -2));
				LCDDR11 = LCDDR11 & ~(0xf << (4 * (pos - 2)));
				LCDDR11 = LCDDR11 | ((0x0f00 & displayNum) >> 8) << (4 * (pos - 2));
				LCDDR6 = LCDDR6 & ~(0xf << (4 * (pos - 2)));
				LCDDR6 = LCDDR6 | ((0x00f0 & displayNum) >> 4) << (4 * (pos - 2));
				LCDDR1 = LCDDR1 & ~(0xf << (4 * (pos - 2)));
				LCDDR1 = LCDDR1 | (0x000f & displayNum) << (4 * (pos - 2));
				return;
			}
			else{
				LCDDR17 = LCDDR17 & ~(0xf << (4 * (pos - 4)));
				LCDDR17 = LCDDR17 | ((0xf000 & displayNum) >> 12) << (4 * (pos - 4));
				LCDDR12 = LCDDR12 & ~(0xf << (4 * (pos - 4)));
				LCDDR12 = LCDDR12 | ((0x0f00 & displayNum) >> 8) << (4 * (pos - 4));
				LCDDR7 = LCDDR7 & ~(0xf << (4 * (pos - 4)));
				LCDDR7 = LCDDR7 | ((0x00f0 & displayNum) >> 4) << (4 * (pos - 4));
				LCDDR2 = LCDDR2 & ~(0xf << (4 * (pos - 4)));
				LCDDR2 = LCDDR2 | (0x000f & displayNum) << (4 * (pos - 4));
				return;
			}
			
		}
	}

}
void writeLong(long i){

	char conv[21];
	sprintf(conv, "%ld", i);
	int len = strlen(conv);
	for(int t = 0; t < len; t++){
		writeChar(conv[t], t); 
	} 
	
}
bool is_prime(long i){
	int cnt = 0;
	if(i <= 1){
		return false;
	}
	else{
		for(int n = 2; n < i; n++){
			if(i % n == 0){
				cnt++;
			}			
		}
		if(cnt > 2){
			return false;
		}
		else{
			return true;
		}						
	}
	
}
void prime(){
	long k = 0;
	for(int n = 0; n <= 21; n++){
		if(is_prime(k) == true){
			writeLong(k);			
		}
		k++;
	}
	
	
}