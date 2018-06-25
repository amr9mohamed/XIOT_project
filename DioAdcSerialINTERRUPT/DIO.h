/*
 * DIO.h
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#ifndef DIO_H_
#define DIO_H_

/*
 * configuration and initialization section
 */
//Initializing data direction registers
#define PortA_InitDir 0x00    //input  by default
#define PortB_InitDir 0xFF    //output by default
#define PortC_InitDir 0xFF    //output by default
#define PortD_InitDir 0xE0    //3 OUTPUT AND 4 INPUT

//Initializing value of bits of ports
#define PortA_InitVal 0x00    //all as low not to burn anything
#define PortB_InitVal 0x00    //all as low not to burn anything
#define PortC_InitVal 0x00    //all as low not to burn anything
#define PortD_InitVal 0x00    //all as low not to burn anything

////////////////////////////////////////////////////////////////////////
/*
 * prototypes section
 */
void DIO_Initialize(void);
void DIO_SetPortDirection(u8_t, u8_t);
void DIO_SetBitDirection(u8_t, bit_num, direction_state);
void DIO_SetPortValue(u8_t, u8_t);
void DIO_SetBitValue(u8_t, bit_num, Bit_state);
void DIO_InitPortForSevenSegment(u8_t, u8_t);
void DIO_SetPortValueForSevenSegment(u8_t,u8_t);
u8_t DIO_GetBitInputValue(u8_t,bit_num);
void DIO_ToggleBit(u8_t port,bit_num number);

#endif /* DIO_H_ */
