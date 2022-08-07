/*
 * Ejemplo3_PCINT.c
 *
 * Created: 7/05/2022 16:09:55
 * Author : cd_te
 */ 

 #define  F_CPU 8000000UL
 #include <avr/io.h>
 #include <util/delay.h>
 #include <avr/interrupt.h>
 #include <stdbool.h>
 #include "Interrupciones_AVR.h"
 
volatile bool Flag_PCINT= false;
uint8_t i;

 int main(void)
 {	
	cli();// desabilita las interrupcioness globales
	PCINTX_Init();
	DDRB |= (1<<5) ;
	PORTB &= ~(1<<5) ;
	sei();// habilita las interrupcioness globales

	 for (;;)
	 {
		 if (Flag_PCINT)
		 {
			for(i=0;i<=9;i++)
			{
				PORTB ^=(1<<5);
				_delay_ms(200);
			}
		 Flag_PCINT=false;
		 }
	 }
	 
	 
 }
