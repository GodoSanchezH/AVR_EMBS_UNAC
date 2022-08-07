
#ifndef I2C_MASTER_H_
#define I2C_MASTER_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdint.h>

#define PRESCALER            1UL
#define F_SCL                100000UL
#define BIT_RATE_GENERATOR   ( ( ( (F_CPU / F_SCL) / PRESCALER) - 16UL ) / 2UL)

#define MASK_STATUS  0xF8
#define START        0x08
#define START_RPTD   0x10
#define MT_SLA_W     0x18
#define MT_SLA_R     0x40
#define MT_DATA_ACK  0x28
#define MR_DATA_ACK  0x50
#define MR_DATA_nACK 0x58

#define I2C_ACK      0
#define I2C_nACK     1
#define I2C_WRITE    0x00
#define I2C_READ     0x01

//Prototipos de Funciones I2C
void I2C_Init(void);
uint8_t I2C_Start(void);
uint8_t I2C_Write_Address_Slave(uint8_t address, uint8_t data_dir);
uint8_t I2C_Write_Data_Slave(uint8_t data);
void I2C_Stop(void);
uint8_t I2C_Read_Data(uint8_t *Ptr_Data, uint8_t var_Ack_nAck);
void I2C_RESTART(void);

#endif /* I2C_MASTER_H_ */