#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB = 1<<3; // port B3, ATtiny13a pin 2
  PORTB = 0x0;

  while (1)
  {
    PORTB ^= 1<<3; // port B3, ATtiny13a pin 2
    _delay_ms(300);
  }
}