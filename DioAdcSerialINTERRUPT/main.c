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
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(){
	//initializing DIO and ADC
	DIO_Initialize();
	ADC_Initialize();

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

	ExtInt_Enable((u8_t)ZERO);
	ExtINT_SenseControl((u8_t)TWO,(u8_t)ZERO);//on both edges for Interrupt 0 sense control
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

ISR(ADC_vect, ISR_NOBLOCK)
{
	u16_t ADCVal = ADC_getVal();
	//TODO add the following line in the ISA of the timer
	//ADC_StartConversion();
}
