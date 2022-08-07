/*
 * preubapid.c
 *
 * Created: 5/06/2022 04:19:55
 * Author : cd_te
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "USART_avr.h"
#include "PWM_avr.h"
#include "Timers_avr.h"
#include "PID.h"

#define PID_KP 0.026436
#define PID_KI 0.64136
#define PID_KD 0
#define PID_TAU 0
#define PID_LMAX 5.35
#define PID_LMIN 0
#define PID_Ts 10E-3 //tiempo de muestreo
#define S 120

ControladorPID MotorDC = {PID_KP,PID_KI,PID_KD,PID_TAU,PID_LMAX,PID_LMIN,PID_Ts};
//ControladorPID horno_pid;
//ControladorPID Servomotores;
//ControladorPID Planta_nivel;
	//
	
uint16_t PULSOS,i=0;
float rpm,FrecAngular,ref,U;
char DataTX[50],DataRX[50];

int main(void)
{
	DDRB |= (1<<5);//led
	DDRD |= (1<<7)|(1<<6);// sentido de giro
	PORTD &= ~(1<<7) & ~(1<<6) ;
    PORTB &= (1<<PINB5);
	UART0_Avr_Init(9600);
	PWM_Init();//t1
	Timer3_Temporizador();
	Timer4_contador();
	PWM_DutyCycle(500);
	Controlador_PID(&MotorDC);

	
	sei();
    for(;;)
    {
		
		
		
    }
}

 
 

ISR(TIMER3_OVF_vect){
	
	PULSOS = TCNT4;
	TCNT4 = 0;
	
	/*calculamos los rpm y la frecuencia angular*/
	rpm = PULSOS*60.0/(0.01*120);
	FrecAngular = rpm*(2*3.14159265359)/60; //w
	
	 U = ControladorPID_Calculo(&MotorDC,ref,FrecAngular)*1023/PID_LMAX;
	 PWM_DutyCycle((uint16_t)  U);
	 
	sprintf((char*)DataTX,"%.2f\n\r",FrecAngular);
	UART0_Avr_Print_String(DataTX);
	
	TCNT3 = 63036;//recarga del valor
	TIFR3 |= (1<<TOV3);//borrar la bandera
	
}

ISR(USART0_RX_vect){
	
	char byte = UDR0;
	if (byte == 'D') {
		PORTD |=(1<<7);
		PORTD &=~(1<<6);
	}
	else  if (byte == 'I') {
		PORTD |=(1<<6);
		PORTD &=~(1<<7);
		}else  if (byte == 'x') {
		ref = atof(DataRX);
		memset(DataRX,0,i);
		i=0;
		}else{
		DataRX[i]=byte;
		i++;
	}

}
