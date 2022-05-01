/*
 * LCD_avr.h
 *
 * Created: 1/05/2022 17:01:36
 *  Author: cd_te
 */ 


#ifndef LCD_AVR_H_
#define LCD_AVR_H_


#include <avr/io.h>
#include <stdint.h>


#define E_ON  PORTB |=(1<<0);
#define E_OFF PORTB &= ~(1<<0);

#define RS_ON PORTB |=(1<<1);
#define RS_OFF PORTB &= ~(1<<1);

#define D4_ON PORTB |=(1<<2);
#define D4_OFF PORTB &= ~(1<<2);

#define D5_ON PORTB |=(1<<3);
#define D5_OFF PORTB &= ~(1<<3);

#define D6_ON PORTB |=(1<<4);
#define D6_OFF PORTB &= ~(1<<4);

#define D7_ON PORTB |=(1<<5);
#define D7_OFF PORTB &= ~(1<<5);


typedef enum{
	Fila1=0,
	Fila2,
	Fila3,
	Fila4
}Ubicacion;


void LCD_AVR_Cmd(uint8_t a);
void LCD_AVR_Data_Bus(uint8_t a);
void LCD_AVR_Init(void);
void LCD_AVR_Set_Cursor(uint8_t x,Ubicacion y);
void LCD_AVR_Print_Char(char c);
void LCD_AVR_Print_String(char *c);


#endif /* LCD_AVR_H_ */