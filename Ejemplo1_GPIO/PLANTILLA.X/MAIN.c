/*
 * File:   MAIN.c
 * Author: cd_te
 *
 * Created on May 29, 2022, 5:53 PM
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    /* Replace with your application code */
    DDRB |= (1<<5);
    while (1) {
        
        PORTB ^= (1<<5);
        _delay_ms(500);
    }
}
