#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "lcd_drv.h"

 
int main( void )
{
  uint32_t val = 0;
  char s[sizeof("4294967295")];		// ASCII space for 32 bit number

  lcd_init();
  lcd_xy( 2, 0 );
  lcd_puts( "Hello Peter" );

  for(;;){
    ultoa( val, s, 10 );
    lcd_xy( 0, 1 );
    lcd_blank( 10 - strlen( s ));	// insert spaces until number
    lcd_puts( s );			// display number right adjusted
    val++;
  }
}
