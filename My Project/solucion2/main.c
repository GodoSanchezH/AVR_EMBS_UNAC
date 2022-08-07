#define  F_CPU 16000000UL
#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>
#include "adc/ADC_avr.h"
uint16_t Resultado;


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	ADC_Avr_Init();
	/* Replace with your application code */
	while (1) {
		Resultado = AnalogRead(AN0);
		printf("ADC: %u \r\n",Resultado);
		
		
		_delay_ms(500);
	}
}
