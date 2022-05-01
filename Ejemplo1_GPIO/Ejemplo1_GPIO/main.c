/*
 * Ejemplo1_GPIO.c
 *
 * Created: 1/05/2022 15:09:07
 * Author : cd_te
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <math.h>
#include "GPIO.h"
/*
v sp  void mmmm(void);
r sp  float mmmm(void);  x = mmmm(); //ANalogRead()
v ep  void mmmm(uint8_t dato,char c,float ref);
r ep  float ControladorPID_Calculo(ControladorPID *pid,float referencia,float medicion)
*/

// i ==0 ; i=0


void Ejemplo1(void);
void Ejemplo2(void);
void Ejemplo3(void);
void Ejemplo4(void);
void Ejemplo5(void);
void Ejemplo6(void);

int main(void)
{
	GPIO_INIT();
	
	
	for(;;){
	GPIO_TOGGLE();
	_delay_ms(200);	
	
	}
}
void Ejemplo6(void){
	//BT1_ PD0
	//BT2_ PD5
	//BT3_ PC0
	
	/*definimos salidas*/
	DDRB |= (1<<0) |(1<<1)|(1<<2); //pb0 ,pb1 , pb2 como salida
	/*definimos entradas*/
	DDRD &= ~(1<<0) & ~(1<<5);//pd0 y pd5
	DDRC &= ~(1<<0);//pc0
	
	for(;;){
		//0000 0000
		if ((PINC & (1<<0))!=0)//PORTBbits.PB0 == 1
		{
			PORTB |= (1<<0);
			}else {
			PORTB &= ~(1<<0);
		}
		if ((PIND & (1<<0))==0)
		{
			PORTB |= (1<<1);
			}else {
			PORTB &= ~(1<<1);
		}
		if ((PIND & (1<<5))==0)
		{
			PORTB |= (1<<2);
			}else {
			PORTB &= ~(1<<2);
		}
		
		
	}
	
}
void Ejemplo5(void){
	DDRB =  0xFF;//puerto B como salida
	int8_t i=0; //uint8_t 0 255 int8_t -128 127
	PORTB =0x01;
	for(;;){//while(1)
		PORTB =0x01;
		while(i<7){
			PORTB =(PORTB<<1);
			_delay_ms(400);
			i++;
		}
		i=7;
		while(i>=0){
			PORTB = (PORTB>>1);
			_delay_ms(400);
			i--;
		}
		i=0;
	}
	
}
void Ejemplo4(void){
	DDRB =  0xFF;//puerto B como salida
	int8_t i=0; //uint8_t 0 255 int8_t -128 127
	for(;;){//while(1)
		i=0;
		while(i<8){
			PORTB |= (1<<i);
			_delay_ms(200);
			i++;
		}
		i--;
		while(i>=0){
			PORTB &= ~(1<<i);
			_delay_ms(200);
			i--;//i=255
		}
		i=0;
	}
	
	
}
void Ejemplo3(void){
	
	DDRB |= (1<<0)|(1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7); //puerto B como salida
	uint8_t i;
	for(;;){
		
		for (i=1;i<=8;i++)
	{
			PORTB = pow(2,i)-1;
			_delay_ms(300);
		}
		for (i=7;i>0;i--)
		{
			PORTB = pow(2,i)-1;
			_delay_ms(300);
		}
	}
	
}
void Ejemplo2(void){
		DDRB = 0Xff;//Defino todo el puerto como salida
		
		for(;;){
			PORTB = 0X0F;
			_delay_ms(200);
			PORTB = 0XF0;
			_delay_ms(200);
			
			
		}
	
}
void Ejemplo1(void){
	
		DDRB |= (1<<7) | (1<<0); //Defino como salida al PINB7 y PB0
		
		for(;;){
			
			PORTB |= (1<<7);
			PORTB &= ~(1<<0);
			_delay_ms(300);
			PORTB |= (1<<0);
			PORTB &= ~(1<<7);
			_delay_ms(300);
		}
}