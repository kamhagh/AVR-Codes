#define F_CPU 16000000ul

#include <avr/io.h>
#include <avr/interrupt.h>

# define USAR T_BAUDR_RATE 4800
# define BAUD_PRESCALE ((( F_CPU / ( USART_B AUDRATE * 16 UL ) ) ) - 1)

char RB ;

void usart_sends(char s[]);
void uart_send(char s);
char uart_recive();

void main(){
	UCSRB = (1 << RXEN ) | (1 << TXEN ) ;
	UCSRC = (1 << URSEL ) | (1 << UCSZ0 ) | (1 << UCSZ1 ) ;
	UCSRB |= (1 << RXCIE ) ;

	UBRRH = ( BAUD_PRESCALE >> 8) ;	
	UBRRL = BAUD_PRESCALE ;
	sei();

	uart_sends("Hellow! ");
	while(1)
	{
	
	}
}

ISR ( USART_RXC_vect , ISR_BLOCK )
{
	RB = uart_recive();
	uart_sends("Recived : ");
	uart_send(RB);
	uart_send('\n');
}

void uart_send(char s)
{
	while (( UCSRA & (1 << UDRE ) ) == 0);
	UDR = s;
}

void uart_sends(char s[])
{
	int i=0;
	while(s[i] != 0x00)
	{
		uart_send(s[i]);
		i++
	}

}

char uart_recive()
{
	while(( UCSRA & (1 << RXC)) == 0);
	Return (UDR);
}
