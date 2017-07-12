#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>


#define Baud 38400
#define Ubrr1 F_CPU/16/Baud-1



void transmit( unsigned char caract )
{
        while (! (UCSRA & _BV(UDRE)));
        UDR = caract;
}

void Usart_init( unsigned int Ubrr )
{
    cli();
    UBRRH = (unsigned char)(Ubrr>>8);
     UBRRL = (unsigned char)Ubrr;
         UCSRB |= _BV(RXEN) | _BV(TXEN) | _BV(RXCIE);
     sei();
 
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

