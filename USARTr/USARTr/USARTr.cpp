/*
 * USARTr.cpp
 *
 * Created: 17-Jan-14 8:33:00 PM
 *  Author: K
 */ 


#include <avr/io.h>

int BaudValue = ((( 16000000 / ( 9600 * 16))) - 1);

int main(void)
{
	char recived;
	
	DDRD |= 1 << 7;
	
	UCSRB |= 1 << RXEN | 1 << TXEN;
	UCSRC = (1 << URSEL ) | (1 << UCSZ0 ) | (1 << UCSZ1 );
	UBRRH = BaudValue >> 8;
	UBRRL = BaudValue;
	
    while(1)
    {
        while (( UCSRA & (1 << RXC )) == 0);
		recived = UDR;
		if (recived > 100)
		{
			PORTD |= 1 << 7;
			while (( UCSRA & (1 << UDRE )) == 0);
			UDR = 1;
		} else {
			PORTD &= ~(1 << 7);
			while (( UCSRA & (1 << UDRE )) == 0);
			UDR = 1;
		}
	}
}