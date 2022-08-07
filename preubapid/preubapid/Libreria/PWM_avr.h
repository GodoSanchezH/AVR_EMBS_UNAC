/*
 * PWM_avr.h
 *
 * Created: 5/06/2022 04:40:20
 *  Author: cd_te
 */ 


#ifndef PWM_AVR_H_
#define PWM_AVR_H_

#include <stdint.h>

void PWM_Init(void);
void PWM_DutyCycle(uint16_t dutyCycle);



#endif /* PWM_AVR_H_ */