/*
 * citizen.cpp
 *
 * Created: 14-Jan-14 3:02:48 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRD |= 1<<6;
	DDRD |= 1<<5;
	
	TCCR1B |= 1 << CS10 | 1 << CS11 | 1 << WGM12;
	OCR1A = 5000;
	TIMSK |= 1 <<OCIE1A ;
	sei();
	
    while(1)
    {
       if(TCNT1 > 400){
		   PORTD ^= 1 << 6;
			TIFR = 1 << OCF1A;
		}
	}
}
ISR (TIMER1_COMPA_vect)
{
	{
		PORTD ^= 1<<5;
	}
}