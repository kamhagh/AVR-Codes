#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB |= 1 << PINB0;
	DDRB &= ~(1 << PINB1); 
	PORTB |= 1 << PINB1; 
	
	while (1)
	{
		if(bit_is_clear(PINB,1))
		{
			PORTB ^= 1 << PINB0;
			_delay_ms(300);
		} else {
			_delay_ms(250);			
		}
	}
}