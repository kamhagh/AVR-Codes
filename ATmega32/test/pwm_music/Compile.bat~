avr-gcc -g -Os -mmcu=atmega32 -c pwmmusic.c
avr-gcc -g -mmcu=atmega32 -o music.elf pwmmusic.o
avr-objcopy -j .text -j .data -O ihex music.elf music.hex

