#include <avr/io.h>

int main (void)
{
	DDRD |= (1 << 6); // Set LED as output
	TCCR1B |= 1 << CS10; // Set up timer
	OCF1A = 1;

	for (;;)
	{
		// Check timer value in if statement, true when count matches 1/20 of a second
		if (TCNT1 >= 1)
		{
			PORTD |= 1 << 6;
			} else{
				PORTD &= ~(1 << 6);
			}
		}
	}