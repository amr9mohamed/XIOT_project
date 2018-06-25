/*
 * timers.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#include "types.h"
#include "timers.h"

void Timer_Initialize(){
	TCCR0 = 0x05;//setting normal wgm and highest pre-scaler
}

void timer0_IntEnable(){
	TIMSK |= (1<<TOIE0);//special interrupt enable
}
