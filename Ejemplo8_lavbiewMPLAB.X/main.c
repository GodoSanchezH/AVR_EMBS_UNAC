/*
 * File:   main.c
 * Author: cd_te
 *
 * Created on 22 de mayo de 2022, 05:16 PM
 */


#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include "USART_avr.h"
#include "ADC_avr.h"
#include <string.h>


uint16_t  Pot0=0,Pot1=0,Pot2=0,Pot3=0,Pot4=0,Pot5=0;
char Str_Pot0[8],Str_Pot1[8],Str_Pot2[8],Str_Pot3[8],Str_Pot4[8],Str_Pot5[8],STR_SEND[50];

int main(void)
{	ADC_Avr_Init();
	UART0_Avr_Init(9600);
	DDRD |= (1<<7) | (1<<6);
	PORTD &= ~(1<<7) & ~(1<<6);
	sei();
    asm("nop");
	for (;;)
	{
		//Inicamos la conversion
		Pot0 = AnalogRead(0);
		Pot1 = AnalogRead(1);
		Pot2 = AnalogRead(2);
		Pot3 = AnalogRead(3);
		Pot4 = AnalogRead(4);
		Pot5 = AnalogRead(5);


		//Convertimos uint a string
		sprintf((char*)STR_SEND,"%04u;%04u;%04u;%04u;%04u;%04u\n\r",Pot0,Pot1,Pot2,Pot3,Pot4,Pot5);
//		sprintf((char*)Str_Pot0,"%u;",Pot0);
//		sprintf((char*)Str_Pot1,"%u;",Pot1);
//		sprintf((char*)Str_Pot2,"%u;",Pot2);
//		sprintf((char*)Str_Pot3,"%u;",Pot3);
//		sprintf((char*)Str_Pot4,"%u;",Pot4);
//		sprintf((char*)Str_Pot5,"%u\n\r",Pot5);
//		
		//Escribimos en la uart
//		
//		strcat(STR_SEND,Str_Pot0);
//        strcat(STR_SEND,Str_Pot1);
//        strcat(STR_SEND,Str_Pot2);
//        strcat(STR_SEND,Str_Pot3);
//        strcat(STR_SEND,Str_Pot4);
//        strcat(STR_SEND,Str_Pot5);
//        
		UART0_Avr_Print_String(STR_SEND);
//		memset(STR_SEND, '\0', sizeof(STR_SEND));
        
		
	}
}

