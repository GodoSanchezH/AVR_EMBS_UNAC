/*
 * grab1.c
 *
 * Created: 28/05/2022 11:24:00
 * Author : cd_te
 */ 

#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "I2C_Master.h"
#define ADDR_PCF1  0b01000000
#define ADDR_PCF2  0b01001100
#define ADDR_PCF3  0b01000110

uint8_t decenas,unidades,centenas;
uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

int main(void)
{
	I2C_Init();
 

    while (1) 
    {
		
		            
	   I2C_Start();
	   I2C_Write_Address_Slave(ADDR_PCF2,I2C_WRITE);
	   I2C_Write_Data_Slave(0XF9);
	   I2C_Stop();
	   _delay_ms(300);
    }
}

