/*
 * Ejemplo_EEPROM.c
 *
 * Created: 5/06/2022 16:43:35
 * Author : cd_te
 */ 
 #define F_CPU 16000000UL

 #include <avr/io.h>
 #include <util/delay.h>
 #include "I2c_avr.h"
 #include "USART_avr.h"
 #include <string.h>
 
#define  EEPROM5 0b10100110
#define  EEPROM4 0b10100010
#define  EEPROM2 0b10100000

char Str_1[] = "Hola EEPROM2";
char Str_2[] = "IEE EMBS UNAC";
char Str_3[] = "Curso AVR";

char Read_String[20];
char  *ptr_read;

void Write_EEPROM_I2C(char *ptr_Str,uint16_t ADD_EEP);
void Read_EEPROM_I2C(char *ptr_Str,uint16_t Nbytes, uint16_t ADD_EEP,uint8_t i2c_Address);

int main(void)
{
    I2C_AVR_Init();
	UART0_Avr_Init(9600);
    UART0_Avr_Print_String("eeprom\n\r");
	I2C_AVR_Start();
	I2C_AVR_Address_Slave(EEPROM2,I2C_WRITE);
	Write_EEPROM_I2C(Str_1,0x0028);	
	I2C_AVR_Stop();
	_delay_ms(5);
	
	I2C_AVR_Start();
	I2C_AVR_Address_Slave(EEPROM4,I2C_WRITE);
	Write_EEPROM_I2C(Str_2,0x0100);
	I2C_AVR_Stop();		
	_delay_ms(5);
			
	I2C_AVR_Start();
	I2C_AVR_Address_Slave(EEPROM5,I2C_WRITE);
	Write_EEPROM_I2C(Str_3,0x50);
	I2C_AVR_Stop();
    _delay_ms(5);
    
	//LECTURA
	  
	 I2C_AVR_Start();
	 I2C_AVR_Address_Slave(EEPROM4,I2C_WRITE);
	 Read_EEPROM_I2C(Read_String,strlen(Str_2),0x0100,EEPROM4);
	 I2C_AVR_Stop();
	 
	 _delay_ms(5);
	 UART0_Avr_Print_String(Read_String);
	 
	
	for(;;)
    {
		
		
		
		
    }
}

void Write_EEPROM_I2C(char *ptr_Str,uint16_t ADD_EEP){

I2C_AVR_Write_Data((uint8_t) (ADD_EEP>>8)); //high byte
I2C_AVR_Write_Data((uint8_t) (ADD_EEP)) ;//low byte}
while(*ptr_Str)
	I2C_AVR_Write_Data(*ptr_Str++);
}

void Read_EEPROM_I2C(char *ptr_Str,uint16_t Nbytes, uint16_t ADD_EEP ,uint8_t i2c_Address){
	
	uint8_t dato_leido;
	I2C_AVR_Write_Data((uint8_t) (ADD_EEP>>8)); //high byte
    I2C_AVR_Write_Data((uint8_t) (ADD_EEP)) ;//low byte}
	I2C_AVR_Start();//start repetido
	I2C_AVR_Address_Slave(i2c_Address,I2C_READ);
	
	while(Nbytes>1){
	
	I2C_AVR_Read_Data(&dato_leido,I2C_ACK);
	*ptr_Str = dato_leido;
	 ptr_Str++;
	 Nbytes--;
	}
	//leemo el ultimo byte
	I2C_AVR_Read_Data(&dato_leido,I2C_NACK);
	*ptr_Str = dato_leido;
	
}
