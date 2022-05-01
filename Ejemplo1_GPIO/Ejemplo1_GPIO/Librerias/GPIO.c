/*
 * GPIO.c
 *
 * Created: 1/05/2022 16:49:01
 *  Author: cd_te
 */ 
#include "GPIO.h"


void GPIO_INIT(void){
	
	DDRB |= (1<<5);
}
void GPIO_TOGGLE(void){
	
	PORTB ^= (1<<5);
}