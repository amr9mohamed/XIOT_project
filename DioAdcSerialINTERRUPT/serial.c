/*
 * serial.c
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#include "types.h"
#include "serial.h"

char serialBuffer[TX_BUFFER_SIZE];
u8_t serialReadPos = 0;
u8_t serialWritePos = 0;

void Serial_Initialize(){
	UBRRH = (BRC >> 8);
	UBRRL =  BRC;
	UCSRB = (1 << TXEN)  | (1 << TXCIE);
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0);
}

void appendSerial(char c){
	serialBuffer[serialWritePos] = c;
	serialWritePos++;

	if(serialWritePos >= TX_BUFFER_SIZE)
	{
		serialWritePos = 0;
	}
}

void serialWrite(char  c[]){
	for(u8_t i = 0; i < strlen(c); i++)
	{
		appendSerial(c[i]);
	}

	if(UCSRA & (1 << UDRE))
	{
		UDR = 0;
	}
}
