/*
 * USART_avr.c
 *
 * Created: 15/05/2022 18:43:33
 *  Author: cd_te
 */ 
#include "USART_avr.h"
#include <avr/interrupt.h>
#include <string.h>
#include <stdbool.h>


void UART0_Avr_Init(uint32_t BaudRate){
	//configuramos los Baudios
	UBRR0 = (uint16_t) ((F_CPU/8UL/BaudRate) -1UL);
	
	//Configuramos UART0 doble speed
	UCSR0A |= (1<<U2X0);
	
	//configuramos el tipo de dato a enviar
	UCSR0B &= ~(1<<UCSZ02);
	UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01);
	
	//Configuramos al modo Asincrono
	UCSR0C &= ~(1<<UMSEL00) & ~(1<<UMSEL01);
	
	//Configuramos la paridad
	UCSR0C &= ~(1<<UPM00) & ~(1<<UPM01);
	
	//Configurar el bit de Stop
	UCSR0C &= ~(1<<USBS0);
	
	//Habilitamos la TX 
	UCSR0B |= (1<<TXEN0);
	
	//Habilitamos RX
	UCSR0B |= (1<<RXEN0);
	
	//habilitamos las interrupciones por RX
	UCSR0B |= (1<<RXCIE0);
	
}
void UART0_Avr_Print_Char(char C){
	
	while((UCSR0A & (1<<UDRE0))==0);
	UDR0 = C;
	
}
void UART0_Avr_Print_String(char *C){
	
	char *ptr;
	ptr=C;
	
	while(*ptr)
	UART0_Avr_Print_Char(*ptr++);
	
}
//extern volatile bool a;

ISR(USART0_RX_vect){
	
char byte = UDR0;

switch(byte){
	case 'a':
	PORTD |= (1<<7);
	break;
	case 'b':
	PORTD &= ~(1<<7);
	break;
	case 'c':
	PORTD |= (1<<6);
	break;
	case 'd':
	PORTD &= ~(1<<6);
	break;
	case 'E':
			//a=true;
	break;
	}
	
}
	