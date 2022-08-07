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


#include "mcc.h"

/**
 * Initializes MCU, drivers and middleware in the project
**/
void SYSTEM_Initialize(void)
{
    PIN_MANAGER_Initialize();
    CPU_Initialize();
    WDT_Initialize();
    ADC_Initialize();
    CPUINT_Initialize();
    USART0_Initialize();
    TC0_Initialize();
}

ISR(WDT_vect)
{
    /* Insert your WDT interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    WDTCSR &= ~(1<<WDIF);
}

/**
 * \brief Initialize wdt interface
 */
 
int8_t WDT_Initialize()
{
    //
    WDTCSR = 0x00;

	return 0;
}
/**
 * \brief Initialize cpu interface
 */

int8_t CPU_Initialize()
{
    //
    PRR0 = 0x00;

    //
    PRR1 = 0x00;

    //
    CLKPR = 0x00;
        
    //
    SMCR = 0x00;  
        
    //
    MCUCR = 0x00; 
        
    
    return 0;

}