avr-gcc -w -Os -DF_CPU=8000000UL -mmcu=atmega32 -c -o UART.o UART.c
avr-gcc -w -Os -DF_CPU=8000000UL -mmcu=atmega32 -c -o lcd.o lcd.c
avr-gcc -w -mmcu=atmega32 UART.o lcd.o -o UART
avr-objcopy -O ihex -R .eeprom UART UART.hex
avrdude -c stk500v1 -P /dev/ttyACM0 -p ATmega32 -b 19200 -U flash:w:UART.hex:i
