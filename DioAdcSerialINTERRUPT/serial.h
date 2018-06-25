/*
 * serial.h
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define BUAD    9600
#define BRC     ((F_CPU/16/BUAD) - 1)
#define TX_BUFFER_SIZE  128

#define UBRRH      *((volatile u8_t *) (0x20))
#define UBRRL      *((volatile u8_t *) (0x09))
#define UCSRB      *((volatile u8_t *) (0x0A))
#define UCSRC      *((volatile u8_t *) (0x20))
#define UCSRA      *((volatile u8_t *) (0x0B))
#define UDR        *((volatile u8_t *) (0x0C))



#define TXEN    3
#define TXCIE   6
#define UCSZ1   2
#define UCSZ0   1
#define UDRE    5

void Serial_Initialize();
void appendSerial(char c);
void serialWrite(char  c[]);

#endif /* SERIAL_H_ */
