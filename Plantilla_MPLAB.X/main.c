/*
 * File:   main.c
 * Author: cd_te
 *
 * Created on 30 de abril de 2022, 05:41 PM
 */


#define  F_CPU 16000000UL

//Liberias del ANSI-c
#include <stdio.h>
#include <stdint.h> // sin signo + signo
#include <stdbool.h>
#include <string.h> 
//
#include <avr/io.h>
#include <avr/delay.h>


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


int main(void)
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
	 x = 00011001
     y = x<<5 = 00100000
     z = x>>5 = 000000001
	*/
	
	DDRB |= (1<<5);// definido como salida al pin PB5
	DDRB &= ~(1<<7);// definido como entrada al pin PB7
	
    /*
     0000 0000
     1000 0000
     
     */
    for(;;)
    {
		if (!(PINB & (1<<7))) {
            
            PORTB |= (1<<5);
        }else{
            PORTB &= ~(1<<5);
        }

    }
}

