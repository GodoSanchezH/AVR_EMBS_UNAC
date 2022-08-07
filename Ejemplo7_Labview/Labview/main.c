/*
 * Labview.c
 *
 * Created: 22/05/2022 16:25:52
 * Author : cd_te
 */ 
#define  F_CPU 16000000UL


#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC_avr.h"
#include "USART_avr.h"

uint16_t  Pot0,Pot1,Pot2,Pot3,Pot4,Pot5;
char Str_Pot0[8],Str_Pot1[8],Str_Pot2[8],Str_Pot3[8],Str_Pot4[8],Str_Pot5[8],STR_SEND[50];

int main(void)
{
   ADC_Avr_Init();
   UART0_Avr_Init(9600);
   sei();

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
	 		 
	 		 sprintf((char*)Str_Pot0,"%u;",Pot0);
	 		 sprintf((char*)Str_Pot1,"%u;",Pot1);
	 		 sprintf((char*)Str_Pot2,"%u;",Pot2);
	 		 sprintf((char*)Str_Pot3,"%u;",Pot3);
	 		 sprintf((char*)Str_Pot4,"%u;",Pot4);
	 		 sprintf((char*)Str_Pot5,"%u\n\r",Pot5);
	 		 
	 		 //Escribimos en la LCD
	 		 strcat(STR_SEND,Str_Pot0);
	 		 strcat(STR_SEND,Str_Pot1);
			 strcat(STR_SEND,Str_Pot2);
			 strcat(STR_SEND,Str_Pot3);
			 strcat(STR_SEND,Str_Pot4);
			 strcat(STR_SEND,Str_Pot5);
		
			UART0_Avr_Print_String(STR_SEND);
			_delay_ms(500);
				
   }
}

