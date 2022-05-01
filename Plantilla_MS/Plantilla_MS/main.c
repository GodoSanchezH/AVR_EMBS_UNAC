/*
 * Plantilla_MS.c
 *
 * Created: 30/04/2022 16:59:10
 * Author : Godo Sanchez
 */ 



#define  F_CPU 8000000UL

//Liberias del ANSI-c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // sin signo + signo
#include <stdbool.h>
#include <string.h> 
//
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_avr.h"

uint8_t Dato1 ;
uint16_t Dato2 ;
uint32_t Dato3 ;

int dato;

float adc;

char texto;

char dato_sms[50];

typedef struct  
{
	float Conversion;
	uint32_t Alarma_sensor;
	char flag;
}lectura;

typedef enum{
	Stop=60,
	Start,
	Run
}Estados;


int main(int argc, char** argv) 
{
	
	/*
	AVR -> 3 REGISTROS PRINCIPALES
	DDRX -> salida o entrada ( 1 = salida y 0= entrada )
	PORTx -> Escribir 1 o 0 
	PINx -> Lectura del Puerto
	*/
	
	//led PB5
    
	/* operadores al bit
	| = or
	& = and
	^ = xor
	~ = not
	<< corrimiento a la izquierda
	>> corrimiento a la derecha
	**********************
	00000001 => 00100000
	
	10011001 or    salida
	00100000
	10111001
	
	
	00000001 => 10000000 ~ => 01111111
	10011001 and
	01111111
	00011001
	*/
	
	DDRB |= (1<<5);// definido como salida al pin PB5
	DDRB &= ~(1<<7);// definido como entrada al pin PB7
	
    for(;;)
    {
		//PORTB |= (1<<5);
		//_delay_ms(500);
		//PORTB &= ~(1<<5);
		//_delay_ms(500);
		pin_toggle();
		_delay_ms(100);
    }
   return (EXIT_SUCCESS);
    }

