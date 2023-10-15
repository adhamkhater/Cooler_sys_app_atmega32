/*
 * CFile1.c
 *
 * Created: 4/7/2023 2:01:31 PM
 *  Author: Khater
 */ 
#include "ADC.h"

void ADC_init(){
	ADMUX = 1<<REFS0; // vcc voltage
	ADCSRA = (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2) | (1<<ADEN); 
}
uint16_t ADC_read(){
	SETBIT(ADCSRA,ADSC);
	while(READBIT(ADCSRA,ADSC) == 1); // adc busy
	return ADC;
}

