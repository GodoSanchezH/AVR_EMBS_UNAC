/*
 * I2c_avr.c
 *
 * Created: 4/06/2022 16:11:37
 *  Author: cd_te
 */ 
#include "I2c_avr.h"



void I2C_AVR_Init(void){
	
	//EL PRESCALADOR
	TWSR0 &= ~(1<<TWPS0) &~(1<<TWPS1); // 1
	
	//EL BIT RATE
	TWBR0 = (uint8_t) Bit_Rate(); //100KHZ
}
uint8_t I2C_AVR_Start(void){
	uint8_t status;
	TWCR0 |= (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);//inicializamos la condicion dle bit start
	while((TWCR0 & (1<<TWINT))==0);//esperamos q se envie el start
	
	status = ( TWSR0 & MASCARA_STATUS);
	if( (status == bit_Start) || (status == bit_ReStart)){
		
		return 1;// operacion exitosa
	}
	return status;
	
}
uint8_t I2C_AVR_Address_Slave(uint8_t address, uint8_t modo){
	uint8_t status =0;
	
	TWDR0 = ((address & 0XFE) | (modo & 0X01)) ; //ENVIO ADDRESS
	
	TWCR0 = (1<<TWEN)|(1<<TWINT);//INICA LA TRASMISION
	
	while((TWCR0 & (1<<TWINT))==0);//esperamos
	
	status = ( TWSR0 & MASCARA_STATUS);
	
	if ((status == MT_SLA_ACK) || (status ==MR_SLA_ACK))
	{
		return 1;//TRASMSIION EXITOSA
	}
	return status;
	
}
uint8_t I2C_AVR_Write_Data(uint8_t data){
	uint8_t status =0;
	
	TWDR0 = data;//ESCRIBIMOS EL DATO A TX
	TWCR0 = (1<<TWEN)|(1<<TWINT);//INICIA LA TRASMISION	
	while((TWCR0 & (1<<TWINT))==0);//esperamos
	
	//se evalua el estado
	
	status = ( TWSR0 & MASCARA_STATUS);
	
	if (status == MT_DATA_ACK)
	{
		return 1;//TRASMSIION EXITOSA
	}
	return status;
}
uint8_t I2C_AVR_Read_Data(uint8_t *ptr_dato,uint8_t ack_nack){
uint8_t status=0;

//ACK
if (ack_nack == I2C_ACK )
{
	TWCR0 |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);//GENERAMOS EL BIT DE RECOCIMIENTO
	while((TWCR0 & (1<<TWINT))==0);//esperamos
	//Leer el status
	status = (TWSR0 & (MASCARA_STATUS));
	if (status == MR_DATA_ACK)
	{
		*ptr_dato = TWDR0;//leo el dato
		
		return 1;
	}
	
}

//NACK
if (ack_nack == I2C_NACK)
{
	
	TWCR0 |= (1<<TWINT) | (1<<TWEN);
	TWCR0 &= ~(1<<TWEA);			//GENERAMOS EL BIT DE nack
	while((TWCR0 & (1<<TWINT))==0);//esperamos
	
	//Leer el status
	status = (TWSR0 & (MASCARA_STATUS));
	if (status == MR_DATA_NACK)
	{
		*ptr_dato = TWDR0;//leo el dato
		
		return 2;
	}
}
return status;
}
void I2C_AVR_Stop(void){
	TWCR0 |= (1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
	while((TWCR0 & (1<<TWSTO))==1);//esperamos hasta q se complete el stop
}