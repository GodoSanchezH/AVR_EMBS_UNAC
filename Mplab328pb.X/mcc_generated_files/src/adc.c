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


#include "../include/adc.h"


/** Function pointer to callback function called by IRQ.
    NULL=default value: No callback function is to be used.
*/
adc_irq_cb_t ADC_cb = NULL;

/**
 * \brief Initialize ADC interface
 */
int8_t ADC_Initialize()
{
    //REFS VAL_0x00; ADLAR disabled; MUX ADC0; 
    ADMUX = 0x00;

    //ACME disabled; ADTS VAL_0x00; 
    ADCSRB = 0x00;

    //ADEN enabled; ADSC disabled; ADATE disabled; ADIF disabled; ADIE disabled; ADPS VAL_0x01; 
    ADCSRA = 0x81;

    return 0;
}

void ADC_Enable()
{
	ADCSRA |= (1 << ADEN);
}

void ADC_Disable()
{
	ADCSRA &= ~(1 << ADEN);
}

void ADC_StartConversion(adc_0_channel_t channel)
{
	ADMUX &= ~0x0f;
	ADMUX |= channel;
	ADCSRA |= (1 << ADSC);
}

bool ADC_IsConversionDone()
{
	return ((ADCSRA & (1 << ADIF)));
}

adc_result_t ADC_GetConversionResult(void)
{
	return (ADCL | ADCH << 8);
}

adc_result_t ADC_GetConversion(adc_0_channel_t channel)
{
	adc_result_t res;

	ADC_StartConversion(channel);
	while (!ADC_IsConversionDone());
	res = ADC_GetConversionResult();
	ADCSRA |= (1 << ADIF);
	return res;
}

uint8_t ADC_GetResolution()
{
	return 10;
}

void ADC_RegisterCallback(adc_irq_cb_t f)
{
	ADC_cb = f;
}

ISR(ADC_vect)
{
    /* Insert your ADC result ready interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    if (ADC_cb != NULL) {
		ADC_cb();
	}
}