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
#include "serial.h"
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(){
	//initializing DIO, ADC, timer and serial
	DIO_Initialize();
	ADC_Initialize();
	Timer_Initialize();
	Serial_Initialize();

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
	    while(1)
	    {
	    	// code here
	    	serialWrite("LED: ON"); //Default value
	    }
}

ISR(INT0_vect)//external interrupt 1
{
	DIO_ToggleBit(PortD, SEVEN);
	serialWrite("LED: OFF");
}

ISR(ADC_vect)
{
	u16_t ADCVal = ADC_getVal();
	char buffer[TX_BUFFER_SIZE];
	serialWrite(itoa(ADCVal, buffer, 10));
}

ISR(TIMER0_OVF_vect)
{
	static u8_t counter=0;//static is used not to be lost when returning from the interrupt
	counter++;
	if (counter == 31*3) {// this 31*3 equivalent to 3 seconds
		ADC_StartConversion(); // start the ADC  conversion after 3 seconds
		counter = 0;
	}
}
