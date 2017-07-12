#include <avr/io.h>
#include <util/delay.h>
void main()
{
	
	DDRD |= 1 <<7 | 1 << 6;
	_delay_microseconds(10);
	PORTD |=

}
