/*
 * I2c_avr.h
 *
 * Created: 4/06/2022 16:11:28
 *  Author: cd_te
 */ 


#ifndef I2C_AVR_H_
#define I2C_AVR_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>

#define F_CPU 16000000UL

#define I2C_WRITE 0x00
#define I2C_READ 0x01

#define I2C_ACK 0
#define I2C_NACK 1

#define  F_SCL 100000UL//100Khz
#define  Preescaler 1UL
#define  Bit_Rate() ((((F_CPU/F_SCL)/Preescaler)-16UL)/2UL)

#define  MASCARA_STATUS 0xF8
#define  bit_Start 0x08
#define  bit_ReStart 0x10


#define MT_SLA_ACK 0X18
#define MR_SLA_ACK 0X40
#define MT_DATA_ACK 0X28
#define MR_DATA_ACK 0X50
#define MR_DATA_NACK 0X58

void I2C_AVR_Init(void);//Inicializar el perfiferico
uint8_t I2C_AVR_Start(void);//Vamos a iniciar la comunicacion
uint8_t I2C_AVR_Address_Slave(uint8_t address, uint8_t modo);//direccionamiento al esclavo
uint8_t I2C_AVR_Write_Data(uint8_t data);
uint8_t I2C_AVR_Read_Data(uint8_t *ptr_dato,uint8_t ack_nack);
void I2C_AVR_Stop(void);//Finalizamos la comunicacion





#endif /* I2C_AVR_H_ */