/*
 * Ejemplo8_GrabArduino.c
 *
 * Created: 28/05/2022 15:19:57
 * Author : cd_te
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRB|= (1<<4);
    while (1) 
    {
		PORTB ^= (1<<4);
		_delay_ms(200);
    }
}

