/*
 * ADC_avr.c
 *
 * Created: 15/05/2022 15:48:45
 *  Author: cd_te
 */ 


#include "ADC_avr.h"



void ADC_Avr_Init(void){
	//Seleccionos el AVCC ;//Justificacion a la derecha
	//ADMUX |= (1<<REFS0) ;
	//ADMUX &= ~(1<<REFS1) & ~(1<<ADLAR);
	ADMUX = (1<<REFS0) | (0<<REFS1) | (0<<ADLAR);
	//Seleccionamos el Clock del ADC
	//FOSC/PREESC = 16MHz/128 = 125kHZ
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
	//Habiltamos los canales Analogicos
	DIDR0 = 0XFF;
	
}
void ADC_Enable(void)
{
	ADCSRA |= (1<<ADEN);
}

void ADC_Disable(void)
{
	ADCSRA &= ~(1<<ADEN);
}

void ADC_Start_Conversion(void)
{
	ADCSRA |= (1<<ADSC);
}

bool ADC_State_Conversion(void)
{
	return ( (ADCSRA & (1<<ADSC)) );
}

void ADC_Select_Channel(uint8_t channel)
{
	ADMUX = ( (ADMUX & 0xF0) | (channel & 0x0F) );
}

uint16_t AnalogRead(uint8_t channel)
{
	ADC_Select_Channel(channel); //Seleecion del canal analogico
	ADC_Enable(); //Habilitamos el ADC
	ADC_Start_Conversion(); //Iniciamos la conversion
	while(ADC_State_Conversion() == true); //Esperar que la conversion se complete
	ADC_Disable(); //Deshabilitar el ADC
	return (ADC); //Retorno el valor actual de la conversion
}