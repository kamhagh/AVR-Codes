avr-gcc -DF_CPU=16000000UL -g -Os -mmcu=atmega32 -c lcd.c
avr-gcc -g -mmcu=atmega32 -o main.elf lcd.o
avr-objcopy -j .text -j .data -O ihex lcd.elf lcd.hex
avrdude -c arduino -p atmega32 -P COM3 -b 19200 -U flash:w:lcd.hex