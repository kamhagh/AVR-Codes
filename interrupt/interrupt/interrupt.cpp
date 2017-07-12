#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	sei();

	DDRD |= 0b01111111;
	PORTD |= 0b01010101;

	TCCR1B |= 1<<CS10 | 1<<CS11 | 1<<WGM12;
	TIMSK |= 1<<OCIE1A; //If using atmega324, this regester is TIMSK1
	OCR1A = 15624;

	while(1)
	{
	}
}

ISR(TIMER1_COMPA_vect)
{
	for(int i=0;i<=6;i++){
	PORTD ^= 1 << i;
	}
}