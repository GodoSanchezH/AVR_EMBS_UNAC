/*
 * ADC.c
 *
 * Created: 15/05/2022 15:47:14
 * Author : cd_te
 */ 

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include "LCD_avr.h"
#include "ADC_avr.h"


//uint16_t Pot0,Pot1,Pot2,Pot3,Pot4,Pot5;
float Pot0,Pot1,Pot2,Pot3,Pot4,Pot5;
char Str_Pot0[20],Str_Pot1[20],Str_Pot2[20],Str_Pot3[20],Str_Pot4[20],Str_Pot5[20];

int main(void)

{		ADC_Avr_Init();
		LCD_AVR_Init();
	
	//Ubicamos los Indicadores
	 LCD_AVR_Set_Cursor(0,Fila1);
	 LCD_AVR_Print_String("Pot0:");
	 LCD_AVR_Set_Cursor(0,Fila2);
	 LCD_AVR_Print_String("Pot1:");
	 LCD_AVR_Set_Cursor(0,Fila3);
	 LCD_AVR_Print_String("Pot2:");
	 LCD_AVR_Set_Cursor(0,Fila4);
	 LCD_AVR_Print_String("Pot3:");
	 LCD_AVR_Set_Cursor(10,Fila1);
	 LCD_AVR_Print_String("Pot4:");
	 LCD_AVR_Set_Cursor(10,Fila2);
	 LCD_AVR_Print_String("Pot5:");
	 
	
 
 
	 for (;;)
	 {
		 //Inicamos la conversion
		 Pot0 = (((float)AnalogRead(0))*(VREF_AVR/Resolucion_AVR));
		 Pot1 = (((float)AnalogRead(1))*(VREF_AVR/Resolucion_AVR));
		 Pot2 = (((float)AnalogRead(2))*(VREF_AVR/Resolucion_AVR));
		 Pot3 = (((float)AnalogRead(3))*(VREF_AVR/Resolucion_AVR));
		 Pot4 = (((float)AnalogRead(4))*(VREF_AVR/Resolucion_AVR));
		 Pot5 = (((float)AnalogRead(5))*(VREF_AVR/Resolucion_AVR));
		 
		 //Convertimos uint a string
		 
		 sprintf((char*)Str_Pot0,"%0.2f",Pot0);
		 sprintf((char*)Str_Pot1,"%0.2f",Pot1);
		 sprintf((char*)Str_Pot2,"%0.2f",Pot2);
		 sprintf((char*)Str_Pot3,"%0.2f",Pot3);
		 sprintf((char*)Str_Pot4,"%0.2f",Pot4);
		 sprintf((char*)Str_Pot5,"%0.2f",Pot5);
		 
		 //Escribimos en la LCD
		 
		  LCD_AVR_Set_Cursor(5,Fila1);
		  LCD_AVR_Print_String(Str_Pot0);
		  LCD_AVR_Set_Cursor(5,Fila2);
		  LCD_AVR_Print_String(Str_Pot1);
		  LCD_AVR_Set_Cursor(5,Fila3);
		  LCD_AVR_Print_String(Str_Pot2);
		  LCD_AVR_Set_Cursor(5,Fila4);
		  LCD_AVR_Print_String(Str_Pot3);
		  LCD_AVR_Set_Cursor(16,Fila1);
		  LCD_AVR_Print_String(Str_Pot4);
		  LCD_AVR_Set_Cursor(16,Fila2);
		  LCD_AVR_Print_String(Str_Pot5);
		
	 }
 
}

