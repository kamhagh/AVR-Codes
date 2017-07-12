#include <avr/io.h>
#include <util/delay.h>

int buttonstate;
int main(void)
{
	DDRB |= 1 << PINB0;
	DDRB &= ~(1 << PINB1);
	DDRB |= 1 << PINB2;
	PORTB |= 1 << PINB1;
	buttonstate = 0;
	
	while (1)
	{
		if(bit_is_clear(PINB,1))
		{
			buttonstate++;
			_delay_ms(250);
		} else { _delay_ms(250); }
		
		switch(buttonstate){
			case 0:
				PORTB &= ~(1 << PINB0);
				PORTB &= ~(1 << PINB2);
				break;
			case 1:
				PORTB |= 1 << PINB0;
				break;
			case 2:
				PORTB &= ~(1 << PINB0);
				PORTB |= 1 << PINB2;
				break;
			case 3:
				PORTB ^= 1 << PINB2;
				break;
			case 4:
				PORTB ^= 1 << PINB0;
				PORTB &= ~(1 << PINB2);
				break;
			case 5:
				PORTB ^= 1	<< PINB0;	
				PORTB ^= 1	<< PINB2;
				break;
			case 6:
				buttonstate = 0;
				break;
		}
	}
	}
