/*
 * led_on.cpp
 *
 * Created: 10-Jan-14 6:32:48 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= 1 << PINB0;
	DDRB |= 1 << PINB1;
	DDRB |= 1 << PINB2;
	DDRB |= 1 << PINB3;
	DDRB |= 1 << PINB4;
	
	PORTB |= 1 << PINB0;
	PORTB &= ~(1 << PINB1);
	PORTB |= 1 << PINB4;
	PORTB &= ~(1 << PINB3);
	PORTB |= 1 << PINB2;
	
    while(1)
    {
        //PORTB ^= 1 << PINB0;
		_delay_ms(400);
    }
}