/*
 * timer.c
 *
 * Created: 8/25/2023 11:41:55 AM
 *  Author: Khater
 */ 
#include "timer.h"

void timer0_normal_init(void){
	TCCR0 = 0b101; // prescaler 1024
	TIMSK = 1; // enable ovf irq
	SETBIT(SREG, 7); // enable global irq
}

void timer0_ctc_init(uint8_t count){
	TCCR0 = 0b101; // prescaler 1024
	SETBIT(TCCR0,WGM01); // ctc mode
	OCR0 = count;
	TIMSK = 0b10; // enable ctc irq
	SETBIT(SREG, 7); // enable global irq	
}

void timer0_frq_gen_init(uint8_t count){
	TCCR0 = 0b01; // no-prescaler
	SETBIT(TCCR0,COM00); // toggle pb3
	SETBIT(TCCR0,WGM01); // ctc mode
	SETBIT(DDRB, 3);
	OCR0 = count;
	//TIMSK = 0b10; // enable ctc irq
	//SETBIT(SREG, 7); // enable global irq
}



void timer1_pwm_oc1A_init(void){
	SETBIT(DDRD,PD5); // OC1A output
	/* non inverting mode enable */
	SETBIT(TCCR1A, COM1A1);
	CLRBIT(TCCR1A, COM1A0);
	
	/* SET fast PWM 10 bit */
	SETBIT(TCCR1A, WGM11);
	SETBIT(TCCR1A, WGM10);
	SETBIT(TCCR1B, WGM12);
	
	/* enable timer */
	SETBIT(TCCR1B, CS10);
}
/* 
DC = (ocr1A/ 1023) * 100
ocr1A = DC  * 10.23
*/
void timer1_pwm_oc1A_dc(uint8_t dc){
	OCR1A = dc  * 10.23;
}


