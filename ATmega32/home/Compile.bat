avr-gcc -g -Os -mmcu=atmega8 -c home.c
avr-gcc -g -mmcu=atmega8 -o home.elf home.o
avr-objcopy -j .text -j .data -O ihex home.elf home.hex

