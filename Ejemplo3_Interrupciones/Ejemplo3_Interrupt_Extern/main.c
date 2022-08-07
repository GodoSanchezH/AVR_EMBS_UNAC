/*
 * Ejemplo3_Interrupt_Extern.c
 *
 * Created: 7/05/2022 16:09:22
 * Author : cd_te
 */ 

 
 #define  F_CPU 8000000UL
 #include <avr/io.h>
 #include <util/delay.h>
 #include <stdbool.h>
 #include <avr/interrupt.h>
 #include "Interrupciones_AVR.h"

volatile bool Flag_PCINT;
uint8_t i;
 int main(void)
 {	cli();// desabilita las interrupcioness globales
	INTX_Init();
	DDRB |= (1<<5) | (1<<0);
	PORTB &= ~(1<<5) & ~(1<<0);
	sei();// habilita las interrupcioness globales

	 for (;;)
	 {
		 if (Flag_PCINT)
		 {
			 for (i=0;i<=9;i++)
			 {
				 PORTB ^=(1<<5);
				 _delay_ms(200);
				 Flag_PCINT = false;
			 }
			 
		 }
		 
	 }
 
 
 }
