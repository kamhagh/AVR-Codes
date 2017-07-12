/*
 * leds_dance.cpp
 *
 * Created: 10-Jan-14 5:59:53 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= 1 << PIND0;
	DDRD |= 1 << PIND1;
	DDRD |= 1 << PIND3;
	DDRD |= 1 << PIND4;
	PORTD = 1010101;
	
    while(1)
    {
        PORTD ^= PORTD;
		_delay_ms(400);
    }
}