#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	//Configure TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD |=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
	DDRD &= ~(1 << 7);
	PORTD |= 1 << 7;

	OCR1A=135;

	while(1)
	{

		if (bit_is_clear(PIND,7))
		{
			OCR1A=497;  //90 degree
			_delay_ms(900);
			OCR1A = 135;
			_delay_ms(800);
		}
	}	
}