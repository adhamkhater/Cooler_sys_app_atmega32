/*
 * Cooler.c
 *
 * Created: 9/17/2023 12:46:19 AM
 *  Author: khater
 */ 

#include "Cooler.h"

/*
	to get the temp i had to first read the data from the ADC and the highest number
	that can be read from the ADC is 1023 if the ADC is 0 then the temp is 0 aswell
	however if the ADC is x then the temp is x*50/1023 
*/
uint16_t get_temp(uint16_t data){
	uint16_t result;
	result = (data * 150) / 308.0;
	return result;
		
}

/*
	to get the volt from the temp is simple if the temp was 35C or below then the volts are 2.5 
	if the temp is 50 or above then the volt is 5
	however if the temp was x then the volt = x*5/50
*/
uint16_t get_volt(uint16_t data){
	uint16_t result;
	result = (data * 5) / 308.0;
	return result;
		
}
uint16_t get_dc(uint16_t data){
	uint16_t result;
	result = (data * 100) / 16.0;
	return result;
	
}