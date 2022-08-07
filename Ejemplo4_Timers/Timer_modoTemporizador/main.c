/*
 * Timer_modoTemporizador.c
 *
 * Created: 14/05/2022 15:43:35
 * Author : cd_te
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Timers_avr.h"

#define  LedC0_Toggle() (PORTC ^= (1<<PINC0))
#define  LedC1_Toggle() (PORTC ^= (1<<PINC1))

volatile bool a=false;
volatile bool b=false;
int main(void)
{
	Timer1_Init();
	Timer2_Init();
	DDRC |= (1<<0) | (1<<1);
	PORTC &= ~(1<<0) & ~(1<<1);
	sei();
    for (;;)
    {
		if (a)
		{
			LedC0_Toggle();
			a=false;
		}
		if (b)
		{
			LedC1_Toggle();
			b=false;
		}
    }
}

