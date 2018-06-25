/*
 * timers.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#include "types.h"
#include "timers.h"

void timer0_IntEnable(){
	TIMSK |= (1<<TOIE0);//special interrupt enable
}
