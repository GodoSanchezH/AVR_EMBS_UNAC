/*
 * USART_avr.h
 *
 * Created: 15/05/2022 18:42:44
 *  Author: cd_te
 */ 


#ifndef USART_AVR_H_
#define USART_AVR_H_

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>

void UART0_Avr_Init(uint32_t BaudRate);
void UART0_Avr_Print_Char(char C);
void UART0_Avr_Print_String(char *C);



#endif /* USART_AVR_H_ */