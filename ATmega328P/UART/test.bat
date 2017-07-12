avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o UART.o UART.c
avr-gcc -w -mmcu=atmega328p UART.o -o UART
avr-objcopy -O ihex -R .eeprom UART UART.hex
avrdude -c stk500v1 -P /dev/ttyACM0 -p ATmega32 -b 19200 -U flash:w:UART.hex:i
