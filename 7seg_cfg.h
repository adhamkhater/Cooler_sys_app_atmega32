/*
 * _7seg_cfg.h
 *
 * Created: 8/19/2023 12:38:54 PM
 *  Author: safifi
 */ 


#ifndef SEG_CFG_H_
#define SEG_CFG_H_

#include "generic_macros_header.h"

#define SEVEN_SEG_PORT_INIT() DDRB = 0xff; SETBIT(DDRC,0); SETBIT(DDRC,1);
#define SS_PORT PORTB

#define SS_EN1(x) if(x == 0) CLRBIT(PORTC, PC1); else SETBIT(PORTC, PC1);
#define SS_EN2(x) if(x == 0) CLRBIT(PORTC, PC0); else SETBIT(PORTC, PC0);

#endif /* 7SEG_CFG_H_ */