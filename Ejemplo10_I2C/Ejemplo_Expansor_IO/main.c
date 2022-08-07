/*
 * Ejemplo_Expansor_IO.c
 *
 * Created: 4/06/2022 17:58:47
 * Author : cd_te
 */ 

 #define F_CPU 16000000UL

 #include <avr/io.h>
 #include <util/delay.h>
 #include "I2c_avr.h"

#define  ADDS_PCF1 0b01000000
#define  ADDS_PCF2 0b01001100
#define  ADDS_PCF3 0b01000110

uint8_t unidades,decenas,centenas;

uint8_t Display_7Seg_A[10] = {0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
	
 int main(void)
 {
 I2C_AVR_Init();
 
	 for(;;)
	 {
		for(centenas=0;centenas<10;centenas++){
			            I2C_AVR_Start();
			            I2C_AVR_Address_Slave(ADDS_PCF3,I2C_WRITE);
			            I2C_AVR_Write_Data(Display_7Seg_A[centenas]);
			              for(decenas=0;decenas<10;decenas++){
			                I2C_AVR_Start();
			                I2C_AVR_Address_Slave(ADDS_PCF2,I2C_WRITE);
			                I2C_AVR_Write_Data(Display_7Seg_A[decenas]);
			
			                  for(unidades=0;unidades<10;unidades++){
										I2C_AVR_Start();
										I2C_AVR_Address_Slave(ADDS_PCF1,I2C_WRITE);
			                            I2C_AVR_Write_Data(Display_7Seg_A[unidades]);
			                            _delay_ms(50);
			                  }
			              }
			              I2C_AVR_Stop();
			        }

	 }
 
 }
 


		 //I2C_AVR_Start();
		 //I2C_AVR_Address_Slave(ADDS_PCF1,I2C_WRITE);
		 //I2C_AVR_Write_Data(Display_7Seg_A[0]);
		 //I2C_AVR_Stop();
		 //_delay_ms(1000);
		 //I2C_AVR_Start();
		 //I2C_AVR_Address_Slave(ADDS_PCF2,I2C_WRITE);
		 //I2C_AVR_Write_Data(Display_7Seg_A[1]);
		 //I2C_AVR_Stop();
		 //_delay_ms(1000);
		 //I2C_AVR_Start();
		 //I2C_AVR_Address_Slave(ADDS_PCF3,I2C_WRITE);
		 //I2C_AVR_Write_Data(Display_7Seg_A[2]);
		 //I2C_AVR_Stop();