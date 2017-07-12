/*
 * lol.cpp
 *
 * Created: 11-Jan-14 5:06:37 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	for(int i = 0;i<5;i++){
		
	DDRD |= 1 << i;
	
	}
	
	PORTD |= 1 << PIND0;
	PORTD |= 1 << PIND2;
	PORTD |= 1 << PIND4;
	PORTD &= ~(1 << PIND1);
	PORTD &= ~(1 << PIND3);
	
	
    while(1)
    {
		for(int i=0;i<5;i++){
        PORTD ^= 1 << i;
	}
		_delay_ms(400);    
	}
}