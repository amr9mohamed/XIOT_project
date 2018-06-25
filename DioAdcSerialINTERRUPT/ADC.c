/*
 * ADC.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */


#include "types.h"
#include "Ports_definitions.h"
#include "DIO.h"
#include "ADC.h"


void ADC_Initialize()
{
	ADMUX = ADMUXInit;
	ADCSRA = ADCSRAInit;
}

void ADC_MuxSelection(u8_t muxNum)
{
	if ( muxNum >= 0 || muxNum < 32)
	{
		ADMUX |= muxNum;
	}
	else
	{
		;
	}
}

void ADC_ClearADIF()
{
	ADCSRA |= (1<<ADIF);
}

u16_t ADC_getVal()
{
	u16_t ADCVal;
	if (ADMUX & (1<<ADLAR))//left adjusted 8 bits resolution
	{
		ADCVal = ((u16_t)ADCH<<2);
	}
	else //right adjusted 10 bits resolution
	{
		ADCVal = (u16_t)ADCL;
		ADCVal |= (u16_t)(ADCH<<8);
	}
	return ADCVal;
}

void ADC_StartConversion()
{
	ADCSRA |= (1<<ADSC);
}

void ADC_Adjustment(u8_t adjustment)
{
	switch(adjustment)
	{
		case RIGHT:
			ADMUX &= ~(1<<ADLAR);//ADLAR = 0
			break;
		case LEFT:
			ADMUX |= (1<<ADLAR);//ADLAR = 1
			break;
		default:
			break;
	}
}

void ADC_EnableINT()
{
	ADCSRA |= (1<<ADIE);
}

void ADC_EnableADC()
{
	ADCSRA |= (1<<ADEN);
}

void ADC_PescalerValue(u8_t value)
{
	switch(value)
	{
		case 0:
			ADCSRA |= 0;
			break;
		case 2:
			ADCSRA |= 1;
			break;
		case 4:
			ADCSRA |= 2;
			break;
		case 8:
			ADCSRA |= 3;
			break;
		case 16:
			ADCSRA |= 4;
			break;
		case 32:
			ADCSRA |= 5;
			break;
		case 64:
			ADCSRA |= 6;
			break;
		case 128:
			ADCSRA |= 7;
			break;
	}
}

u8_t ADC_isConversionComplete()
{
	return ADCSRA & (1<<ADIF);
}
