/*
 * ADC_avr.h
 *
 * Created: 15/05/2022 15:48:34
 *  Author: cd_te
 */ 


#ifndef ADC_AVR_H_
#define ADC_AVR_H_

#define  F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define  Resolucion_AVR 1023.0
#define  VREF_AVR 5.0


typedef enum{
	AN0=0,
	AN1,
	AN2,
	AN3,
	AN4,
	AN5,
	AN6,
	AN7
	}Channel;


void ADC_Avr_Init(void); //Inicializacion del Periferico
void ADC_Enable(void);
void ADC_Disable(void);
void ADC_Start_Conversion(void);
bool ADC_State_Conversion(void);
void ADC_Select_Channel(uint8_t channel);
uint16_t AnalogRead(uint8_t channel);

#endif /* ADC_AVR_H_ */