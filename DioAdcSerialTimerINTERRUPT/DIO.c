/*
 * DIO.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */


#include "types.h"
#include "Ports_definitions.h"
#include "DIO.h"

static volatile u8_t* ports_direction_array[] = {&DDRA,&DDRB,&DDRC,&DDRD};
static volatile u8_t* ports_value_array[] = {&PORTA,&PORTB,&PORTC,&PORTD};
static volatile u8_t* pins_value_array[] = {&PINA, &PINB, &PINC, &PIND};

void DIO_Initialize(void)
{
	//initializing ports direction
	DDRA = PortA_InitDir;
	DDRB = PortB_InitDir;
	DDRC = PortC_InitDir;
	DDRD = PortD_InitDir;

	//initializing ports value
	PORTA = PortA_InitVal;
	PORTB = PortB_InitVal;
	PORTC = PortC_InitVal;
	PORTD = PortD_InitVal;
}

void DIO_SetPortDirection(u8_t port,u8_t direction)
{
	if(port >= 0 && port < 4)
	{
		*(ports_direction_array[port]) = direction;
	}
	else
	{
		;
	}
}

void DIO_SetBitDirection(u8_t port, bit_num bitNum, direction_state direction)
{
	if(bitNum >= ZERO && bitNum <= SEVEN && port >= 0 && port < 4)
	{
		switch (direction)
		{
			case INPUT:
			//INPUT  == reseting -> making 0
				*(ports_direction_array[port]) &= ~(1 << bitNum);
				break;
			case OUTPUT:
			//OUTPUT == setting -> making 1
				*(ports_direction_array[port]) |= (1 << bitNum);
				break;
			default:
				break;
		}
	}
	else
	{
		;
	}
}

void DIO_SetPortValue(u8_t port , u8_t value)
{
	if(port >= 0 && port < 4)
	{
		*(ports_value_array[port]) = value;
	}
	else
	{
		;
	}
}

void DIO_SetBitValue(u8_t port, bit_num bitNum, Bit_state state)
{
	if( bitNum >= ZERO && bitNum <= SEVEN && port >= 0 && port < 4)
	{
		switch (state)
		{
			case RESET:
			//reset
				*(ports_value_array[port]) &= ~(1 << bitNum);
				break;
			case SET:
			//set
				*(ports_value_array[port]) |= (1 << bitNum);
				break;
			default:
				break;
		}
	}
	else
	{
		;
	}
}

void DIO_InitPortForSevenSegment(u8_t port, u8_t number)
{
	//setting the port direction
	*(ports_direction_array[port]) &= 0x03;
	*(ports_direction_array[port]) |= 0xFC;
	//setting the port value
	*(ports_value_array[port]) &= 0x0F;
	*(ports_value_array[port]) |= (number << 4);
}

void DIO_SetPortValueForSevenSegment(u8_t port, u8_t number)
{
	*(ports_value_array[port]) &= 0x0F;
	*(ports_value_array[port]) |= (number << 4);
}

u8_t DIO_GetBitInputValue(u8_t port ,bit_num number)
{
	return *(pins_value_array[port]) &= (1 << number);
}

void DIO_ToggleBit(u8_t port,bit_num number)
{
	*(ports_value_array[port]) ^= (1<<number);
}
