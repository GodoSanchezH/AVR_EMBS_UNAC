/*
 * Ejemplo2_LCD.c
 *
 * Created: 1/05/2022 17:00:27
 * Author : cd_te
 */ 
#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_avr.h"

int main(void)
{
   LCD_AVR_Init();
   //LCD_AVR_Set_Cursor(0,Fila1);
   //LCD_AVR_Print_Char('H');
   //LCD_AVR_Set_Cursor(0,Fila2);
   //LCD_AVR_Print_Char('O');
   //LCD_AVR_Set_Cursor(0,Fila3);
   //LCD_AVR_Print_Char('L');
   //LCD_AVR_Set_Cursor(0,Fila4);
   //LCD_AVR_Print_Char('A');
   
   
      LCD_AVR_Set_Cursor(0,Fila1);
      LCD_AVR_Print_String("Bienvidos al Curso");
      LCD_AVR_Set_Cursor(0,Fila2);
      LCD_AVR_Print_String("de AVR en C");
      LCD_AVR_Set_Cursor(0,Fila3);
      LCD_AVR_Print_String("EMBS UNAC");
      LCD_AVR_Set_Cursor(0,Fila4);
      LCD_AVR_Print_String("MUCHAS GRACIAS");
   for (;;)
   {
	   
	   
   }
}

