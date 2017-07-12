/*
 * USARTsenser.cpp
 *
 * Created: 15-Jan-14 9:30:40 PM
 *  Author: K
 */ 


#include <avr/io.h>

#define  USART_BAUDRATE 9600
int BAUD_PRESCALE (((16000000 / ( USART_BAUDRATE * 16))) - 1);

int main(void)
{
	char ReceivedByte ;
	
	DDRB &= ~(1 << PINB0);
	DDRB |= 1 << 1;
	PORTB |= 1 << 0;
	
	UCSRB = (1 << RXEN) | 1 << TXEN;
	UCSRC = 1 << URSEL | 1 << UCSZ0 | 1 << UCSZ1;
	
	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;
    while(1)
    {
        if (bit_is_clear(PINB,0))
        {
			while (( UCSRA & (1 << UDRE )) == 0);
			UDR = 1;
			while (( UCSRA & (1 << RXC )) == 0);
			ReceivedByte = UDR;
			if (ReceivedByte == 1)
			{
				PORTB |= 1 << 1;
			} else {
			while (( UCSRA & (1 << UDRE )) == 0);
			UDR = 0;
			PORTB &= ~(1 << 1);
		}
    }
}