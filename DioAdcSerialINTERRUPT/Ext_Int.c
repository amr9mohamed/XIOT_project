/*
 * Ext_Int.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */


#include "types.h"
#include "Ports_definitions.h"
#include "DIO.h"
#include "Ext_Int.h"

void ExtInt_Enable(u8_t INTno)
{
	switch (INTno)
	{
		case 0:
			GICR |= 1 << INT0;
			break;
		case 1:
			GICR |= 1 << INT1;
			break;
		case 2:
			GICR |= 1 << INT2;
			break;
		default:
			break;
	}
}

void ExtINT_SenseControl(u8_t SenseControlNo, u8_t INTno)
{
	switch (INTno) {
		case 0:
			switch (SenseControlNo)
			{
				case 0://falling edge
					MCUCR &= 0b00;
					MCUCR |= 0b10;
					break;
				case 1://rising edge
					MCUCR &= 0b00;
					MCUCR |= 0b11;
					break;
				case 2://both edges
					MCUCR &= 0b00;
					MCUCR |= 0b01;
					break;
				default:
					break;
			}
			break;
		case 1:
			switch (SenseControlNo)
			{
				case 0://falling edge
					MCUCR &= 0b0011;
					MCUCR |= 0b1000;
					break;
				case 1://rising edge
					MCUCR &= 0b0011;
					MCUCR |= 0b1100;
					break;
				case 2://both edges
					MCUCR &= 0b0011;
					MCUCR |= 0b0100;
					break;
				default:
					break;
			}
			break;
		case 2:
			switch (SenseControlNo)
			{
				case 0://falling edge
					MCUCSR &= 0b10111111;
					break;
				case 1://rising edge
					MCUCSR |= 0b01000000;
					break;
				default:
					break;
			}
				break;
		default:
			break;
	}
}
