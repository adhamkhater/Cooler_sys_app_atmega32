/*
 * Cooler_System_app.c
 *
 * Created: 9/14/2023 3:15:01 AM
 * Author : khater
 */ 

#include "7seg.h"
#include "LCD.h"
#include "timer.h"
#include "ADC.h"
#include "Cooler.h" // my crafted header file

void convert_display(uint16_t data);

int main(void)
{
	SevenSeg_init();
	LCD_init();
	timer1_pwm_oc1A_init();
	ADC_init(); // enta kont nasy di garab tany 
	//uint8_t dc =0;
	SETBIT(DDRD, 2); // PB3 is output for LED
    while (1) 
    {
		/*
			for the sake of testing i assumed that the ADC read 820 which means that the temp is 40C and the volt should be 4V
			Temp was displayed 40 as assumed 
			volt was displayed 4 as assumed
			as the temp was above 35 the LED was on
			therefore the only problem is the ADC_read() function.
			everything works correctly except for the ADC read
		*/
		uint16_t data = ADC_read();
		uint16_t temp = get_temp(data);// maps the temp from the ADC
		uint16_t volt = get_volt(data);// maps the volt from the temp
		uint16_t dc = get_dc(data);// get the duty cycle according to the volt
		//////////////////////////
 		if(temp >= 35){
 			SETBIT(PORTD, 2);
			timer1_pwm_oc1A_dc(dc);
 		}
 		else if(temp < 35){
 			CLRBIT(PORTD, 2);
 			timer1_pwm_oc1A_dc(dc);
 		}
		//////////////////////////
		LCD_write_command(0x1); // clear
		LCD_write_command(FIRST_LINE(0));
		LCD_write_num(temp);
		LCD_write_command(SECOND_LINE(0));
		LCD_write_num(volt);
		
		SevenSeg_write(temp % 10, 1);
 		_delay_ms(5);
 		SevenSeg_write(temp / 10, 2);
 		_delay_ms(5);
		//_delay_ms(300);	
	}

}