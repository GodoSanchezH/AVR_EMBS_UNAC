/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/usart0.h"


void USART0_Initialize()
{

    //
    UBRR0 = 0x33;
	
    //RXC disabled; TXC disabled; UDRE disabled; FE disabled; DOR disabled; UPE disabled; U2X disabled; MPCM disabled; 
    
    UCSR0A = 0x00;
	
    //RXCIE disabled; TXCIE disabled; UDRIE disabled; RXEN disabled; TXEN enabled; UCSZ2 disabled; RXB8 disabled; TXB8 disabled; 
    UCSR0B = 0x08;
	
    //UMSEL VAL_0x00; UPM VAL_0x00; USBS VAL_0x00; UCSZ 3; UCPOL disabled; 
    UCSR0C = 0x06;

    //RXSIE disabled; RXS disabled; SFDE disabled; 
    UCSR0D = 0x00;

    
}

void USART0_Enable()
{
    UCSR0B |=(( 1 << RXEN0) | ( 1 << TXEN0));
}

void USART0_EnableRx()
{
    UCSR0B |= ( 1 << RXEN0 );
}

void USART0_EnableTx()
{
    UCSR0B |= ( 1 << TXEN0 );
}

void USART0_Disable()
{
    UCSR0B &= ~( ( 1 << RXEN0 ) | ( 1 << TXEN0 ));
}

uint8_t USART0_GetData()
{
    return UDR0;
}

bool USART0_IsTxReady()
{
    return (UCSR0A & ( 1 << UDRE0 ));
}

bool USART0_IsRxReady()
{
    return (UCSR0A & ( 1 << RXC0 ));
}

bool USART0_IsTxBusy()
{
    return (!(UCSR0A & ( 1 << TXC0 )));
}

bool USART0_IsTxDone()
{
    return (UCSR0A & ( 1 << TXC0 ));
}

uint8_t USART0_Read()
{
    while (!(UCSR0A & ( 1 << RXC0 )))
            ;
    return UDR0;
}

void USART0_Write(const uint8_t data)
{
    while (!(UCSR0A & ( 1 << UDRE0 )))
            ;
    UDR0 = data;
}

void UART0_Avr_Print_String(char *C){
	
	char *ptr;
	ptr=C;
	
	while(*ptr)
	USART0_Write(*ptr++);
}
