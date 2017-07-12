/*
 * USART.cpp
 *
 * Created: 15-Jan-14 8:02:05 PM
 *  Author: K
 */ 


# include <avr/io.h>
# define USART_BAUDRATE 9600
// # define BAUD_PRESCALE ((( 16000000 / ( USART_BAUDRATE * 16 UL))) - 1)

int BAUD_PRESCALE = ((( 16000000 / (BAUD_PRESCALE * 16))) -1);

int main ( void )
{
	char ReceivedByte ;
	
	DDRD |= 1 << 7;
	
	UCSRB = (1 << RXEN ) | (1 << TXEN ); // Turn on the transmission and reception circuitry
	UCSRC = (1 << URSEL ) | (1 << UCSZ0 ) | (1 << UCSZ1 ); // Use 8- bit character sizes
	UBRRH = ( BAUD_PRESCALE >> 8); // Load upper 8- bits of the baud rate value into the high byte
	UBRRL = BAUD_PRESCALE ; // Load lower 8- bits of the baud rate value into the low byte of the
	
    while(1)
    {
		while (( UCSRA & (1 << RXC )) == 0);
        ReceivedByte = UDR;
		if(ReceivedByte == 1){
			PORTD |= 1 << 7;
			while (( UCSRA & (1 << UDRE )) == 0);
			UDR = 1;
		} else{ if(ReceivedByte == 0){
		PORTD &= ~(1 << 7);
			}
		}
	}
}