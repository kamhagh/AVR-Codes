#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void main()
{

	int i;

	DDRD |= 1 << 3;
	
	TCCR2A |= _BV(COM2B1) | _BV(WGM20)  | _BV(WGM21);
	TCCR2B |= _BV(CS20);

	OCR2B = 0;

	while(1)
	{

		for(i=0;i<255;i++)
		{
			OCR2B++;
			_delay_ms(10);
		}
		_delay_ms(100);

		for(i=0;i<255;i++)
		{
			OCR2B--;
			_delay_ms(10);
		}

		_delay_ms(100);

	}

}
