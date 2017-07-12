#ifndef ADC
#define ADC

#include <avr/io.h>
uint16_t adc_read(uint8_t ch);
void adc_init();

#endif ADC
