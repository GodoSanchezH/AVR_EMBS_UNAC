/*
 * PWM_avr.c
 *
 * Created: 5/06/2022 04:40:36
 *  Author: cd_te
 */ 

#include "PWM_avr.h"
#include <avr/io.h>

void PWM_Init(void){
	//Salida OC1A: Pin PB1
	DDRB |= (1<<PINB1);
	//TC1: PWM non-inverting mode, Fast PWM 10 bits
	TCCR1A = (1<<COM1A1)|(0<<COM1A0)|(1<<WGM11)|(1<<WGM10);
	//TC1: Fast PWM 10 bits, PRESCALER x1
	TCCR1B = (0<<WGM13)|(1<<WGM12)|(0<<CS12)|(0<<CS11)|(1<<CS10);
	/*
	PWM con resolucion de 10 bits -> 1023

	TOP_Value = 1023

	fOCnxPWM = Fosc /  (N * ( 1 + TOP))
	fOCnxPWM = 16Mhz / (1 * ( 1 + 1023))
	fOCnxPWM = 16Mhz / 1024
	fOCnxPWM = 15625 hz  -> 15.6Khz*/
	
}
void PWM_DutyCycle(uint16_t dutyCycle){
	
	OCR1A = dutyCycle;
	
}