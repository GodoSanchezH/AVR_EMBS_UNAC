
#include "I2C_Master.h"

//Desarrollo de funciones
void I2C_Init(void)
{
	//Generacion de Bit Rate
	TWBR = ((uint8_t)BIT_RATE_GENERATOR);
	//Prescaler x1
	TWCR = (0<<TWPS1)|(0<<TWPS0);
	/*
	TWBR = ( ( ( (16Mhz / 100Khz) / 1) - 16UL ) / 2UL)
	TWBR = ( ( 160 - 16UL ) / 2UL)
	TWBR = ( 144 / 2UL)
	TWBR = 72;
	*/
}

uint8_t I2C_Start(void)
{
	uint8_t statusCode = 0;
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); //Generar la condicion de START
	while( !(TWCR & (1<<TWINT)) );// Esperar que el START sea transmitido
	//Leo el Status Code
	statusCode = (TWCR & MASK_STATUS);
	//Evaluar el Status Code
	if( statusCode == START )
	{
		//La transaccion a sido exitosa START
		return 1;
	}
	else if( statusCode == START_RPTD )
	{
		//La transaccion a sido exitosa de START_RPTD
		return 2;
	}
	//La transaccion a sido fallida
	return statusCode;
}

uint8_t I2C_Write_Address_Slave(uint8_t address, uint8_t data_dir)
{
	uint8_t statusCode = 0;
	//Ejemplo:
	// (0100 000 0 & 1111 111 0) = ADDRESS
	// (0000 000 1 & 0000 000 1) = dato_RW
	TWCR = ( (address & 0xFE) | (data_dir & 0x01) ); //Cargar el byte de control a ser transmitido
	TWCR = (1<<TWINT)|(1<<TWEN); //Inicio la transmision del byte de control Addrees_Slave + RW
	while( !(TWCR & (1<<TWINT)) ); //Espera mientras se realiza la transaccion del byte de control
	//Leo el Status Code
	statusCode = (TWCR & MASK_STATUS);
	//Evaluar el Status Code
	if( statusCode == MT_SLA_W)
	{
		//La transaccion a sido exitosa modo MT_SLA_W
		return 1;
	}
	else if( statusCode == MT_SLA_R)
	{
		//La transaccion a sido exitosa modo MT_SLA_R
		return 2;
	}
	//La transaccion a sido fallida
	return statusCode;
}

uint8_t I2C_Write_Data_Slave(uint8_t data)
{
	uint8_t statusCode = 0;
	TWCR = data; //Cargar el registros de datos
	TWCR = (1<<TWINT)|(1<<TWEN); //Inicio la transmision del byte de datos
	while( !(TWCR & (1<<TWINT)) ); //Esperar que el esclavo reciba el dato correctamente y responda con un ACK
	//Leo el Status Code
	statusCode = (TWCR & MASK_STATUS);
	//Evaluar el Status Code
	if( statusCode == MT_DATA_ACK)
	{
		//La transaccion a sido exitosa
		return 1;
	}
	//La transaccion a sido fallida
	return statusCode;
}

void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN); //Generar la condicion de STOP (parada)
	while( (TWCR & (1<<TWSTO)) == 1 ); //Eperarar hasta que STOP sea transmitido al bus
}




uint8_t I2C_Read_Data(uint8_t *Ptr_Data, uint8_t var_Ack_nAck)
{
	uint8_t statusCode = 0;
	//I2C_Read_Data(&data_Rx, I2C_ACK);
	//I2C_Read_Data(&data_Rx, I2C_nACK);
	if( var_Ack_nAck == I2C_ACK)
	{
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN); //Hablito la generacion del ACK
		while( !(TWCR & (1<<TWINT)) ); //Esperar que el ACk sea generado en el bus
		//Leo el Status Code
		statusCode = (TWCR & MASK_STATUS);
		//Evaluar el Status Code
		if( statusCode == MR_DATA_ACK)
		{
			*Ptr_Data = TWCR; //Leo el dato recibido por el Master
			//La transaccion a sido exitosa
			return 1;
		}
		//La transaccion a sido fallida
		return statusCode;
	}
	else if( var_Ack_nAck == I2C_nACK)
	{
		TWCR = (1<<TWINT)|(0<<TWEA)|(1<<TWEN); //Habilito la generacion del nACK
		while( !(TWCR & (1<<TWINT)) ); //Esperar que el ACk sea generado en el bus
		//Leo el Status Code
		statusCode = (TWCR & MASK_STATUS);
		//Evaluar el Status Code
		if( statusCode == MR_DATA_nACK)
		{
			*Ptr_Data = TWCR; //Leo el dato recibido por el Master
			//La transaccion a sido exitosa
			return 2;
		}
		//La transaccion a sido fallida
		return statusCode;
	}
	
	return 0;
}