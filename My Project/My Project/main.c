#define  F_CPU 8000000UL
#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
		
		printf("hola mundo\n\r");
		_delay_ms(500);
	}
}
