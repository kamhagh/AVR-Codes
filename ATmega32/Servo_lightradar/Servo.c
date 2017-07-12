#include <avr/io.h>

#define F_CPU 16000000UL

#include <util/delay.h>


void adc_init();
uint16_t adc_read(uint8_t ch);

void main()
{
   int i;
   int Value[4];
   uint8_t holder = 0;

   adc_init();

   //Configure TIMER1
   TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

   ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

   DDRD |= (1<<PD5);   //PWM Pins as Out
   DDRB |= 0b00001111;
   PORTB = 0b00001111;

   while(1)
   { // check while rotating


      OCR1A=120;   //0 degree
_delay_ms(1200);
      Value[0] = adc_read(0);
_delay_ms(600);

      OCR1A=316;  //90 degree
_delay_ms(1200);
      Value[1] = adc_read(0);
_delay_ms(600);

if(Value[1] > Value[holder]) holder = 1;

      OCR1A=425;  //135 degree
_delay_ms(1200);
      Value[2] = adc_read(0);
_delay_ms(600);

if(Value[2] > Value[holder]) holder = 2;

      OCR1A=495;  //180 degree
_delay_ms(1200);
      Value[3] = adc_read(0);
_delay_ms(600);

if(Value[3] > Value[0]) holder = 3;
      
      	PORTB = 0b00000000;
      /*for(i=0;i<4;i++)
    {
        if(Value[i]>holder)
        holder = i;
    }*/
     PORTB |= 1 << holder;
	     holder = 0;
   }
}

void adc_init()
{
    // AREF = AVcc
   ADMUX = (1<<REFS0);
   // ADC Enable and prescaler of 128
   // 16000000/128 = 125000
   ADCSRA = (1<<ADEN)|(1<<ADPS2)/*|(1<<ADPS1)|(1<<ADPS0)*/; 
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
