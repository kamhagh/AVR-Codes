#include <avr/io.h>
#include <util/delay.h>

#define LCD_RS 0
#define LCD_RW 1
#define LCD_E 2


void LCD_While_busy();
void LCD_init();
void LCD_command(unsigned char Command);
void LCD_senddata(unsigned char var);
void LCD_sendstring(unsigned char *var);
void LcdSendByte(uint8_t theByte);
void pulseE();

int main(void)
{
	DDRB |= 1 << 3;
	PORTB = 0x00;

	_delay_ms(200);
	LCD_init();
	LCD_sendstring("hellow Fellow travelers");

	while(1){

	}

}

void LCD_While_busy()
{
	DDRD &= ~(1 << 7);
	DDRC |= 1 << LCD_E;

	PORTC &= ~(1 << LCD_RS);
	PORTC |= 1 << LCD_RW;

	PORTB = 1 << 3; // for loop

	while(PIND & (1 << 7)){
		pulseE();
	}

	PORTB = 0; // for end loop


}

void LCD_init()
{
	LCD_command(0x38);
	LCD_While_busy();
	
	LCD_command(0x0F);
	LCD_While_busy();

	LCD_command(0x01);
	LCD_While_busy();

	LCD_command(0x06);
	LCD_While_busy();

	LCD_command(0x02);
}

void LCD_command(unsigned char Command)
{
	_delay_ms(15);
	LCD_While_busy();

	DDRD = 0xFF;
	PORTD = Command;
	DDRC |= 1 << LCD_RS | 1 << LCD_RW | 1 << LCD_E;
	pulseE();
}

void LCD_senddata(unsigned char var)
{
	_delay_ms(15);
	LCD_While_busy();

	DDRD = 0xFF;
	PORTD = var;

	DDRC = 1 << LCD_E | 1 << LCD_RS | 1 << LCD_RW;
	PORTC = 0x0;

	PORTC |= 1 << LCD_RS | 1 << LCD_E;
	
	pulseE();
}

void LCD_sendstring(unsigned char *var)
{
	_delay_ms(15);
     while(*var)              //till string ends
       LCD_senddata(*var++);  //send characters one by one
}

void pulseE()
{
	PORTC = 1 << LCD_E;
    _delay_us(1);
	PORTC &= ~(LCD_E);
}