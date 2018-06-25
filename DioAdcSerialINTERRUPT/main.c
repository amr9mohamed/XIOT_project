/*
 * main.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#include "types.h"
#include "Ports_definitions.h"
#include "DIO.h"
#include "ADC.h"
#include "Ext_Int.h"
#include "timers.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(){
	//initializing DIO and ADC
	DIO_Initialize();
	ADC_Initialize();
	//setting the timer
	TCCR0 = 0x05;//setting normal wgm and highest pre-scaler

	//setting the global interrupt
	sei();

	//select ADC MUX
	ADC_MuxSelection(ZERO);
	//enable ADC interrupt
	ADC_EnableINT();
	//8-bit or 10-bit resolution
	ADC_Adjustment(RIGHT);
	//adjust pre_scaler value
	ADC_PescalerValue(128);
	//turn on the ACD
	ADC_EnableADC();
	ADC_StartConversion();

	// enable external interrupt
	ExtInt_Enable((u8_t)ZERO);
	ExtINT_SenseControl((u8_t)TWO,(u8_t)ZERO);//on both edges for Interrupt 0 sense control

	// enable timer interrupt
	timer0_IntEnable();

	while(1){
		/*
		 * never ending loop
		 */
	}
}

ISR(INT0_vect)//external interrupt 1
{
	DIO_ToggleBit(PortD, SEVEN);
	//TODO send the led status to the serial monitor
}

ISR(ADC_vect)
{
	u16_t ADCVal = ADC_getVal();
	//TODO SENT TO THE SERIAL MONITOR
}

ISR(TIMER0_OVF_vect)
{
	static uint8_t counter=0;//static is used not to be lost when returning from the interrupt
	counter++;
	if (counter == 31*3) {// this 31*3 equivalent to 3 seconds
		ADC_StartConversion(); // start the ADC  conversion after 3 seconds
		counter =0;
	}
}
