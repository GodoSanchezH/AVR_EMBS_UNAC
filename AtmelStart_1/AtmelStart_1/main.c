#include <atmel_start.h>
#include <util/delay.h>
#include <stdio.h>


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	while (1) {
		
		
		if (Boton_get_level())
		{
			LED_set_level(false);
			printf("BotonApagado\n\r");
		}else{
			LED_set_level(true);
			printf("BotonPrendido\n\r");
			
		}
	
		_delay_ms(250);
		
	//LED_set_level(true);
	//_delay_ms(500);
	//LED_set_level(false);
		//_delay_ms(500);
	}
}
