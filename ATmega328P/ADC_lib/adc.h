#ifndef ADC.h
#define ADC.h

adc_read(uint8_t)
{
	ADMUX |= ( ADMUX & ~7) | (ch & 7);
	ADMUX |= 1 << ADSC;
	while(ADMUX & (1 << ADSC)); 
	return (ADC);
}

adc_init()
{
	ADMUX |= 1 << REFS0;
	ADCSRA |= 1 << ADEN | 1 << ADPS0 | 1 << ADPS1 | 1 << ADPS2;
}

#endif ADC.h
