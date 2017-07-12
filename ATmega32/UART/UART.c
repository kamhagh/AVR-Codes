#define F_CPU 16000000ul

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

# define USART_BAUDRATE 4800
# define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL ) ) ) - 1)

char RB ;
char string[20];

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

	lcd_init(LCD_DISP_ON_CURSOR);
  lcd_clrscr();
	lcd_home();

	uart_sends("Hellow! ");
	while(1)
	{
	
	}
}

ISR ( USART_RXC_vect , ISR_BLOCK )
{
	RB = uart_recive();
	uart_sends("Recived: ");
	uart_send(RB);
	// uart_send('\n');
	//lcd_clrscr();
	//lcd_puts("Recived: ");
	lcd_putc(RB);
}

void uart_send(char s)
{
	while (( UCSRA & (1 << UDRE ) ) == 0);
	UDR = s;
}

void uart_sends(char s[])
{
	int i;
	for(i = 0;s[i] != 0x00;i++)
	{
		uart_send(s[i]);
	}

}

char uart_recive()
{
	while(( UCSRA & (1 << RXC)) == 0);
	return (UDR);
}
