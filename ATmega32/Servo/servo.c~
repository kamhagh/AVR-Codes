#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

void main()
{	

	int i;
	
	DDRD |= 1 << 5;
	TCCR1A |= _BV(COM1A1) | _BV(WGM11);
	TCCR1B|= (1<<CS10) | 1 << CS11 | 1 << WGM13 | 1 << WGM12;
	ICR1 = 4999;
	OCR1A=125;

	while(1)
	{
		
		for(i=0;i<370;i++)
		{
			OCR1A++;
			_delay_ms(1);
		}
		_delay_ms(1000);
		for(i=0;i<370;i++)
		{
			OCR1A--;
			_delay_ms(1);
		}
		_delay_ms(1000);

	}	
}

