/*
 * USARTs.cpp
 *
 * Created: 17-Jan-14 8:03:47 PM
 *  Author: K
 */ 
#include <avr/io.h>

int BaudValue = ((( 16000000 / ( 9600 * 16))) - 1);

void adc_init();
uint_least16_t adc_read(uint8_t ch);

int main(void)
{
	char recived;
	adc_init();
	UCSRB |= 1 << RXEN | 1 << TXEN;
	UCSRC = (1 << URSEL ) | (1 << UCSZ0 ) | (1 << UCSZ1 );
	UBRRH = BaudValue >> 8;
	UBRRL = BaudValue;
	
	
    while(1)
    {
		while (( UCSRA & (1 << UDRE )) == 0);
        UDR = adc_read(0);
		while (( UCSRA & (1 << RXC )) == 0);
    }
}

void adc_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint_least16_t adc_read(uint8_t ch)
{
	ch &= 0b00000111; // sets channel pin:P
	ADMUX = (ADMUX & 0xf8) | ch;
	
	ADCSRA |= 1<<ADSC; // starts conversation sets ADSC :1;  !!!
	while(ADCSRA & 1<<ADSC);
	
	return (ADC);
}