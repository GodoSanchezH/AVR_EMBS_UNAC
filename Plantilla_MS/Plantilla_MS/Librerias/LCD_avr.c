/*
 * LCD_avr.c
 *
 * Created: 1/05/2022 14:12:40
 *  Author: cd_te
 */ 

#include "LCD_avr.h"
#include "avr/io.h"

void pin_toggle(void){
	
	PORTB ^= (1<<5);
	
}