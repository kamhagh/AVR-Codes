avr-gcc -w -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o LCD.o LCD.c
avr-gcc -w -mmcu=atmega328p LCD.o -o LCD
avr-objcopy -O ihex -R .eeprom LCD LCD.hex
avrdude -c stk500v1 -b 19200 -P /dev/ttyACM0 -p ATmega328p -U flash:w:LCD.hex:i
