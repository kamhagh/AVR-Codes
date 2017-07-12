#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <inttypes.h>
#include <avr/iom32.h>
#include <avr/interrupt.h>
#include <string.h>


#define Baud 38400
#define Ubrr1 F_CPU/16/Baud-1
char a;



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
a=receive(  );
if(a >= 5){
PORTD |= _BV(PD6);
} else if( a >= 0) {
PORTD &= ~_BV(PD6);
}
}

int main (void)
{
Usart_init(Ubrr1);
DDRD|=_BV(PD6);


while(1)
{
transmit( 'U' );
_delay_ms(250);
}

}

