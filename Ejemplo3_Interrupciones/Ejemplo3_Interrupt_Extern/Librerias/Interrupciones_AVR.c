/*
 * Interrupciones_AVR.c
 *
 * Created: 7/05/2022 16:12:22
 *  Author: cd_te
 *INTX_Init*/ 

#include "Interrupciones_AVR.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void INTX_Init(void){
	//CONFIGURACION INT0
	EICRA |= (1<<ISC01) | (1<<ISC00);// INT0 QUE SEA FLANCO DE SUBIDA
	EIMSK |= (1<<INT0);	//HABILITAMOS INT0
	
	//CONFIGURACION INT1
	EICRA |= (1<<ISC11);
	EICRA &= ~(1<<ISC10);// INT1 QUE SEA FLANCO DE BAJADA
	EIMSK |= (1<<INT1);	//HABILITAMOS INT1
	
	
}

ISR(INT0_vect){
	
	PORTB ^=(1<<0);
	EIFR |= (1<<INTF0);//limpiamos la bandera
}

ISR(INT1_vect){
	
	PORTB ^=(1<<5);
	EIFR |= (1<<INTF1);//limpiamos la bandera
}