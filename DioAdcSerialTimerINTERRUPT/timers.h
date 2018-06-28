/*
 * timers.h
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#define TCCR0    *((volatile u8_t *) (0x33))
#define TIMSK    *((volatile u8_t *) (0x39))
#define TOIE0   0

void Timer_Initialize();
void timer0_IntEnable();

#endif /* TIMERS_H_ */
