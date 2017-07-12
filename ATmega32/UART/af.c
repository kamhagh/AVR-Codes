#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <avr/iom32.h>
#include <avr/interrupt.h>
#include <string.h>
#include "lcd.h"

#define Baud 4800

#define Ubrr1 F_CPU/16/Baud-1
char b[] = { "What ever." };
char a;

int i;

void transmit( unsigned char caract )
{
        while (! (UCSRA & _BV(UDRE)));
        UDR = caract;
}

unsigned char receive( void )
{
   while (! (UCSRA & _BV(RXC)));
   return UDR;
}

void Usart_init( unsigned int Ubrr )
{
    cli();
    UBRRH = (unsigned char)(Ubrr>>8);
     UBRRL = (unsigned char)Ubrr;
         UCSRB |= _BV(RXEN) | _BV(TXEN) | _BV(RXCIE);
     sei();
 
}


ISR(USART_RXC_vect)
{
	/*lcd_clrscr();
	lcd_puts("Recived: ");
	lcd_gotoxy(0,1);*/
	a = receive();
	lcd_puts(a);
}


int main (void)
{
		Usart_init(Ubrr1);
		lcd_init(LCD_DISP_ON_CURSOR);
    lcd_clrscr();
		lcd_home();	
		lcd_puts("Recived: ");
		DDRD|=_BV(PD6);
		for(i = 0;b[i] != '.';i++){
			transmit(b[i]);
		}


	while(1)
	{
		for(i = 0;b[i] != '.';i++){
			transmit(b[i]);
		}

		transmit(' ');
		_delay_ms(250);
}

}

