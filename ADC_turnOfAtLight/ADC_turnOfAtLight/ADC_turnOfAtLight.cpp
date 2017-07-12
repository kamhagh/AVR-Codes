#include <avr/io.h>
#include <util/delay.h>

uint_least16_t adc_read(uint8_t ch);
void adc_init();

int main(void)
{
	int sens_1,sens_2;
	adc_init();
	DDRD |= 1 << 6;
	DDRD |= 1 << 5;
	
	while (1)
	{
		sens_1 = adc_read(0);
		sens_2 = adc_read(1);
		if(sens_1 < 5 || sens_2 < 5){
			PORTD |= 1 << 6;
		} else {
			PORTD &= ~(1 << 6);
		}
		_delay_ms(1500);
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