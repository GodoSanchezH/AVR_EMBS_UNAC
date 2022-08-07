/*
 * Interrupciones_AVR.c
 *
 * Created: 7/05/2022 16:12:22
 *  Author: cd_te
 *INTX_Init*/ 

#include "Interrupciones_AVR.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
 
extern volatile uint16_t Algodon,Cemento;
extern volatile bool Algodon_F, Cemento_F;


void INTX_Init(void){
	//CONFIGURACION INT0
	EICRA |= (1<<ISC01) | (1<<ISC00);// INT0 QUE SEA FLANCO DE SUBIDA
	EIMSK |= (1<<INT0);	//HABILITAMOS INT0
	
	//CONFIGURACION INT1
	EICRA |= (1<<ISC11);
	EICRA &= ~(1<<ISC10);// INT1 QUE SEA FLANCO DE BAJADA
	EIMSK |= (1<<INT1);	//HABILITAMOS INT1
	
	
}

void PCINTX_Init(void){
	
	
	PCICR |= (1<<PCIE0);//habilitamos ese vector
	
	PCMSK0 |= (1<<PCINT7);//habilitamos el pin pb7
}


ISR(PCINT0_vect){
	
	//PORTB ^=(1<<5);
	PCIFR |= (1<<PCIF0);
	
	
}


ISR(INT0_vect){
	Algodon++;
	Algodon_F = true;
	//PORTB ^=(1<<0);
	EIFR |= (1<<INTF0);//limpiamos la bandera
}

ISR(INT1_vect){
	Cemento++;
	Cemento_F = true;
	//PORTB ^=(1<<5);
	EIFR |= (1<<INTF1);//limpiamos la bandera
}