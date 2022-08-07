#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>

uint16_t resultado;
int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
		ADC_0_start_conversion(0);
		resultado = ADC_0_get_conversion(1) ;
		printf(" ADC: %u",resultado);
		PWM_0_test_pwm_basic();
		_delay_ms(500);
	}
}
