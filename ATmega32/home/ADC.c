#ifndef ADC
#define ADC

#include <avr/io.h>
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

#endif 
