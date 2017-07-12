#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
	
		DDRD |= 1 << 5;
		
		//TCCR0 |= CS11 | CS10;
		
		TCCR1A |= /*1 << WGM10 |*/ 1 << WGM12 | 1 << COM1A1;
		TCCR1B |=  1 <<CS11;
		ICR1 = 977;
		OCR1A = 1;
		
		while(1)
		{
			/*for (int i=0; i<200;i++)
			{
				OCR1A++;
				_delay_ms(50);
			}
			
			_delay_ms(100);
			
			for(int i=0;i<200;i++)
			{
				OCR1A--;
				_delay_ms(50);
				
			}
			
			_delay_ms(100);
			
			*/
		}
}
