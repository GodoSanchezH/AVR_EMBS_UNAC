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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set led aliases
#define led_SetHigh() do { PORTB |= 0x20; } while(0)
#define led_SetLow() do { PORTB &= ~0x20; } while(0)
#define led_Toggle() do { PINB |= 0x20; } while(0)
#define led_GetValue() (PINB & (0x1 << 5))
#define led_SetDigitalInput() do { DDRB &= ~0x20; } while(0)
#define led_SetDigitalOutput() do { DDRB |= 0x20; } while(0)
#define led_SetPullUp() do { PORTB |= 0x20; } while(0)
#define led_ResetPullUp() do { PORTB &= ~0x20; } while(0)
#define led_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define led_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set boton aliases
#define boton_SetHigh() do { PORTB |= 0x80; } while(0)
#define boton_SetLow() do { PORTB &= ~0x80; } while(0)
#define boton_Toggle() do { PINB |= 0x80; } while(0)
#define boton_GetValue() (PINB & (0x1 << 7))
#define boton_SetDigitalInput() do { DDRB &= ~0x80; } while(0)
#define boton_SetDigitalOutput() do { DDRB |= 0x80; } while(0)
#define boton_SetPullUp() do { PORTB |= 0x80; } while(0)
#define boton_ResetPullUp() do { PORTB &= ~0x80; } while(0)
#define boton_SetInverted() do { PORTB_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define boton_ResetInverted() do { PORTB_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PD1 aliases
#define PD1_SetHigh() do { PORTD |= 0x2; } while(0)
#define PD1_SetLow() do { PORTD &= ~0x2; } while(0)
#define PD1_Toggle() do { PIND |= 0x2; } while(0)
#define PD1_GetValue() (PIND & (0x1 << 1))
#define PD1_SetDigitalInput() do { DDRD &= ~0x2; } while(0)
#define PD1_SetDigitalOutput() do { DDRD |= 0x2; } while(0)
#define PD1_SetPullUp() do { PORTD |= 0x2; } while(0)
#define PD1_ResetPullUp() do { PORTD &= ~0x2; } while(0)
#define PD1_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PD1_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PD0 aliases
#define PD0_SetHigh() do { PORTD |= 0x1; } while(0)
#define PD0_SetLow() do { PORTD &= ~0x1; } while(0)
#define PD0_Toggle() do { PIND |= 0x1; } while(0)
#define PD0_GetValue() (PIND & (0x1 << 0))
#define PD0_SetDigitalInput() do { DDRD &= ~0x1; } while(0)
#define PD0_SetDigitalOutput() do { DDRD |= 0x1; } while(0)
#define PD0_SetPullUp() do { PORTD |= 0x1; } while(0)
#define PD0_ResetPullUp() do { PORTD &= ~0x1; } while(0)
#define PD0_SetInverted() do { PORTD_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PD0_ResetInverted() do { PORTD_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)

void PIN_MANAGER_Initialize();
#endif /* PINS_H_INCLUDED */
