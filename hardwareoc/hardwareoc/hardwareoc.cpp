/*
 * hardwareoc.cpp
 *
 * Created: 14-Jan-14 5:59:34 PM
 *  Author: K
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
	DDRD |= 1<<5;
	TIMSK |= 1 << TOIE1;
	TCCR1B |= 1 << CS11 | 1 << CS11;
	sei();
	TCNT1 = 49911;
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
ISR(TIMER1_OVF_vect)
{
	PORTD ^= 1 << 5;
	TCNT1 = 300;	
}