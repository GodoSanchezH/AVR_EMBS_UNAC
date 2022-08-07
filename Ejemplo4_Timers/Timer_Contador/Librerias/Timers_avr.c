/*
 * Timers_avr.c
 *
 * Created: 14/05/2022 15:45:55
 *  Author: cd_te
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include "Timers_avr.h"
#include <avr/interrupt.h>


extern volatile bool a;
extern volatile bool b;
void Timer1_Init(void){
	//Timer 1 en Modo Normal Mode
	TCCR1A &= ~(1<<WGM11) & ~(1<<WGM10);
	TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13);
	
	
	//Temporizacion : 100mS ;350mS ;  1uS
	/*
	t = 100mS
	FOSC= 16Mhz
	Pre = 64
	
	ValorTimer= 65536 - ((t X Fosc)/Pre)
	ValorTimer= 65536 - ((100ms X 16MHz)/64)
    ValorTimer= 65536 - ((100x10E-3 X 16x10E6)/64)
	ValorTimer= 65536 -25000
	ValorTimer = 40536
	
	
	//////////////////////////////////////////////////////////////////////////
		t = 350mS
		FOSC= 16Mhz
		Pre = 256
		
		ValorTimer= 65536 - ((t X Fosc)/Pre)
		ValorTimer= 65536 - ((350ms X 16MHz)/64)
		ValorTimer= 65536 - ((350x10E-3 X 16x10E6)/256)
		ValorTimer= 65536 -21875
		ValorTimer = 43661
		
		//////////////////////////////////////////////////////////////////////////
			t = 1uS
			FOSC= 16Mhz
			Pre = 1
			
			ValorTimer= 65536 - ((t X Fosc)/Pre)
			ValorTimer= 65536 - ((1uS X 16MHz)/64)
			ValorTimer= 65536 - ((1x10E-6 X 16x10E6)/1)
			ValorTimer= 65536 -21875
			ValorTimer = 65520
	*/
	TCNT1 = Valor_100mS;
	
	//Configurar Interrupcion por Desbordamiento
	
	TIMSK1  |= (1<<TOIE1);//Habilitamos 
	
	////Habilitamos el clock Fosc/64
	TCCR1B |= (1<<CS11) | (1<<CS10);
	TCCR1B &= ~(1<<CS12);
	
		////Habilitamos el clock Fosc/1
		//TCCR1B &= ~(1<<CS12) & ~(1<<CS11);
		//TCCR1B |= (1<<CS10);
	
}


void Timer2_Init(void){
	
	//timer 2 como temporizador
	TCCR2A &= ~(1<<WGM22) & ~(1<<WGM21) & ~(1<<WGM20);
	
	
	//cargar valor
		//ValorTimer= 256- ((t X Fosc)/Pre)
		//ValorTimer= 256- ((5ms X 16Mhz)/1024)
		//valorTimer = 256-78 = 178
	TCNT2 = 178;
	
	//activar la interrupcion
	TIMSK2 |= (1<<TOIE2);
	//habilitar el clock
	
	TCCR2B |= (1<<CS20) | (1<<CS21)|(1<<CS22);
	
}
void Timer1_ModoContador(void){
	
	//Timer 1 en Modo Normal Mode
	TCCR1A &= ~(1<<WGM11) & ~(1<<WGM10);
	TCCR1B &= ~(1<<WGM12) & ~(1<<WGM13);
	
	//activamos el modo contado con flanco de subida
	
	TCCR1B |= (1<<CS10)|(1<<CS11)|(1<<CS12);
	
	TCNT1 = 0;//inicia en 0
}
	ISR(TIMER1_OVF_vect){
		
		a=true;
		TCNT1 = Valor_100mS;//recarga del valor
		TIFR1 |= (1<<TOV1);//borrar la bandera
		
	}
	
	ISR(TIMER2_OVF_vect){
	b=true;
	TCNT2 = 178;//recarga del valor
	TIFR2 |= (1<<TOV2);//borrar la bandera
}

