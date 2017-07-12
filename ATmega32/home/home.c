#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

uint16_t adc_read(uint8_t ch);
void adc_init();

void main()
{
	adc_init();
	DDRB |= 1 << 0 | 1 << 1;
	while(1)
	{
		if(adc_read(1) > 110)
		{
			 PORTB |= 1 << 0;
		} else {
			PORTB &= ~(1 << 0);
			}

		if(adc_read(0) > 50)
		{
			 PORTB |= 1 << 1;
		} else {
			PORTB &= ~(1 << 1);
			}


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
   ADCSRA = (1<<ADEN)|(1<<ADPS2)/*|(1<<ADPS1)|(1<<ADPS0)*/; 
}
