/*
 * Button.cpp
 *
 * Created: 12-Jan-14 3:13:42 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |= 1 << PIND1;
	DDRD &= ~(1 << PIND0);
	PORTD |= 1 << PIND0;
	
    while(1)
    {
        if(bit_is_clear(PIND,0))
		{
			
			PORTD ^= 1 << PIND1;
			
		}
		else{
			PORTD |= 1 << PIND1;
		}
		_delay_ms(300);	
    }
}