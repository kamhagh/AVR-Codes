/*
 * SR.cpp
 *
 * Created: 16-Jan-14 2:45:01 PM
 *  Author: K
 */ 
#include <avr/io.h>

void adc_init();
uint16_t adc_read(uint8_t ch);
void PWM_Start();

int main(void)
{
	DDRD |= 1 << 5;
	
	PWM_Start();
	adc_init();
	
	OCR1A = 1023;
    while(1)
    {
       /*OCR1A = (adc_read(0)/2);*/
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

uint16_t adc_read(uint8_t ch)
{
	// select the corresponding channel 0~7
	// ANDing with '7' will always keep the value
	// of 'ch' between 0 and 7
	ch &= 0b00000111; // AND operation with 7
	ADMUX |= ch;
	// start single convertion
	// write '1' to ADSC
	ADCSRA |= (1<<ADSC);
	// wait for convertion to complete
	// ADSC becomes '0' again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	return (ADC);
}

void PWM_Start()
{
	TCCR1A |= 1 << WGM10 |1 << WGM12 | COM1A1;
	TCCR1B |= 1 << CS12 | 1 << CS10;
	
			
}