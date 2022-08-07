/*
 * Aplicacion_Interrupt.c
 *
 * Created: 7/05/2022 17:12:04
 * Author : cd_te
 */ 

 #define  F_CPU 8000000UL
 #include <avr/io.h>
 #include <util/delay.h>
 #include <avr/interrupt.h>
 #include <stdbool.h>
 #include <stdint.h>
 #include "Interrupciones_AVR.h"
 #include "LCD_avr.h"
 
volatile uint16_t Algodon=0,Cemento=0;
volatile bool Algodon_F=false, Cemento_F=false;
char Str_Algodon[20],Str_Cemento[20];

 int main(void)
 {
	 cli();// desabilita las interrupcioness globales
	 LCD_AVR_Init();
	 
	 //conversion
	 sprintf(Str_Algodon,"Algodon : %04u",Algodon);
	 sprintf(Str_Cemento,"Cemento : %04u",Cemento);
	 
	 LCD_AVR_Set_Cursor(0,Fila1);
	 LCD_AVR_Print_String(Str_Algodon);
	 LCD_AVR_Set_Cursor(0,Fila2);
	 LCD_AVR_Print_String(Str_Cemento);
	 
	 
	 INTX_Init();
	 
	 sei();// habilita las interrupcioness globales

	 for (;;)
	 {
		if (Algodon_F || Cemento_F)
		{
			 sprintf(Str_Algodon,"Algodon : %04u",Algodon);
			 sprintf(Str_Cemento,"Cemento : %04u",Cemento);
			 
			 LCD_AVR_Set_Cursor(0,Fila1);
			 LCD_AVR_Print_String(Str_Algodon);
			 LCD_AVR_Set_Cursor(0,Fila2);
			 LCD_AVR_Print_String(Str_Cemento);
			 
			 //borramos las banderas
			Algodon_F = false;
			Cemento_F = false;
		}
	 }
	 
	 
 }


