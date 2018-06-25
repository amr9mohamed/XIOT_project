/*
 * main.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#include "types.h"
#include "Ports_definitions.h"
#include "DIO.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(){
	//initializing DIO
	DIO_Initialize();
	//setting the global interrupt
	sei();
	ExtInt_Enable((u8_t)ZERO);
	ExtINT_SenseControl((u8_t)TWO,(u8_t)ZERO);//on both edges for Interrupt 0 sense control
	while(1){
		/*
		 * do the program here
		 */
	}
}

ISR(INT0_vect)//external interrupt 1
{
	DIO_ToggleBit(PortD, SEVEN);
}
