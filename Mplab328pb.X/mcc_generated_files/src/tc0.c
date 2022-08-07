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

#include "../include/tc0.h"

void TC0_DefaultCMPAIsrCallback(void);
void (*TC0_CMPA_isr_cb)(void) = &TC0_DefaultCMPAIsrCallback;
void TC0_DefaultCMPBIsrCallback(void);
void (*TC0_CMPB_isr_cb)(void) = &TC0_DefaultCMPBIsrCallback;
void TC0_DefaultOVFIsrCallback(void);
void (*TC0_OVF_isr_cb)(void) = &TC0_DefaultOVFIsrCallback;

void TC0_DefaultCMPAIsrCallback(void)
{
    //Add your ISR code here
}

void TC0_DefaultCMPBIsrCallback(void)
{
    //Add your ISR code here
}

void TC0_DefaultOVFIsrCallback(void)
{
    //Add your ISR code here
}

void TC0_SetOVFIsrCallback(TC0_cb_t cb)
{
    TC0_OVF_isr_cb = cb;
}

void TC0_SetCMPAIsrCallback(TC0_cb_t cb)
{
    TC0_CMPA_isr_cb = cb;
}

void TC0_SetCMPBIsrCallback(TC0_cb_t cb)
{
    TC0_CMPB_isr_cb = cb;
}

ISR(TIMER0_COMPA_vect)
{
    if (TC0_CMPA_isr_cb != NULL)
        (*TC0_CMPA_isr_cb)();
    
    TIFR0 = OCF0A;
}

ISR(TIMER0_COMPB_vect)
{
    if (TC0_CMPB_isr_cb != NULL)
        (*TC0_CMPB_isr_cb)();
    
    TIFR0 = OCF0B;
}

ISR(TIMER0_OVF_vect)
{
    if (TC0_OVF_isr_cb != NULL)
        (*TC0_OVF_isr_cb)();
    
    TIFR0 = TOV0;
}


/**
 * \brief Initialize TC0 interface
 */
int8_t TC0_Initialize()
{
    //Compare A
    OCR0A = 0x7F;

    //Compare B
    OCR0B = 0x00;

    //Count
    TCNT0 = 0x00;


    //TSM disabled; PSRSYNC disabled; 
    GTCCR = 0x00;

    //COMA 0; COMB 0; WGM 3; 
    TCCR0A = 0x03;

    //FOCA disabled; FOCB disabled; WGM disabled; CS VAL_0x02; 
    TCCR0B = 0x02;

    //OCIEB disabled; OCIEA disabled; TOIE disabled; 
    TIMSK0 = 0x00;

    return 0;
}

void TC0_WriteTimer(uint8_t timerVal)
{
    TCNT0=timerVal;
}

uint8_t TC0_ReadTimer(void)
{
    uint8_t readVal;

    readVal = TCNT0;

    return readVal;
}

void TC0_EnableInterrupt(void)
{
    TIMSK0 = 1 << OCIE0A /* Compare A Interrupt: enabled */
                  | 1 << OCIE0B /* Compare B Interrupt: enabled */
                  | 1 << TOIE0; /* Overflow Interrupt: enabled */
}
void TC0_DisableInterrupt(void)
{
    TIMSK0 = 0 << OCIE0A /* Compare 0 Interrupt: disabled */
                  | 0 << OCIE0B /* Compare 1 Interrupt: disabled */
                  | 0 << TOIE0; /* Overflow Interrupt: disabled */
}
void TC0_ClearOverflowInterruptFlag(void)
{
    TIFR0 &= ~TOV0; /* Overflow Interrupt: disabled */
}
bool TC0_IsOverflowInterruptEnabled(void)
{
    return ((TIMSK0 & TOIE0) > 0);
}
