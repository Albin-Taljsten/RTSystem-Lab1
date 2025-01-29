#include <avr/io.h>
#include <ctype.h>
#include <stdbool.h>



 

void blink(){
	TCCR1B = 0b00000100;
	unsigned int cycleDiv2 = 31250 / 2;
	unsigned int nextCycle = 0;
	unsigned int current = 0;
	
	while(1){
		current = TCNT1;
		
		if (nextCycle == current)
		{
			nextCycle += cycleDiv2;
			
			if (LCDDR0 == 0x0000)
			{
				LCDDR0 = 0x0004;
			}
			else
			{
				LCDDR0 = 0x0000;
			}
		}
			
	}
}
