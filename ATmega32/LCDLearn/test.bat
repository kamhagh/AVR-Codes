avr-gcc -g -Os -mmcu=atmega32 -c main.c
avr-gcc -g -mmcu=atmega32 -o main.elf main.o
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
avrdude -c arduino -p atmega32 -P COM3 -b 19200 -U flash:w:main.hex