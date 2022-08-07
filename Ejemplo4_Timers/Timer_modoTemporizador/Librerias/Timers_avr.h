/*
 * Timers_avr.h
 *
 * Created: 14/05/2022 15:45:32
 *  Author: cd_te
 */ 


#ifndef TIMERS_AVR_H_
#define TIMERS_AVR_H_

#define Valor_100mS 40536
#define Valor_350mS 43661	//Prescalador 256
#define Valor_1uS 65520		//Prescalador 1

void Timer1_Init(void);
void Timer2_Init(void);


#endif /* TIMERS_AVR_H_ */