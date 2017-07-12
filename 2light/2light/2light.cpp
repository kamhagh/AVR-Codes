/*
 * snesor_write.cpp
 *
 * Created: 15-Jan-14 11:55:02 PM
 *  Author: K
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

uint16_t adc_read(uint8_t ch);
void adc_init();

int main(void)
{
	DDRD |= 1 << 4 | 1 << 5;
	
	adc_init();
	
	TCCR1A |= _BV(WGM10) | _BV(WGM12) | _BV(WGM11) | _BV(COM1B1) | _BV(COM1A1);
	TCCR1B |= _BV(CS11);
	OCR1A = 0;
	OCR1B = 0;
	
    while(1)
    {
	   OCR1A = adc_read(0);
	   OCR1B = adc_read(1);
	   _delay_ms(30);
    }
}

uint16_t adc_read(uint8_t ch)
{
	// select the corresponding channel 0~7
	// remove the 'old' channel bits
	// add the 'new' channel bits.
	ADMUX = (ADMUX & ~7) | (ch & 7);
	// start single convertion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);
	// wait for convertion to complete
	// ADSC becomes '0' again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	return (ADC);
}

void adc_init()
{
	// AREF = AVcc
	ADMUX = (1<<REFS0);
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}