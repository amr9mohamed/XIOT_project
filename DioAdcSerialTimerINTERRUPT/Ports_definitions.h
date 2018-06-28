/*
 * Ports_definitions.h
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#ifndef PORTS_DEFINITIONS_H_
#define PORTS_DEFINITIONS_H_

//Peripheral A
#define PORTA      *((volatile u8_t *) (0x3B))
#define DDRA       *((volatile u8_t *) (0x3A))
#define PINA       *((volatile u8_t *) (0x39))

//Peripheral B
#define PORTB      *((volatile u8_t *) (0x38))
#define DDRB       *((volatile u8_t *) (0x37))
#define PINB       *((volatile u8_t *) (0x36))

//Peripheral C
#define PORTC      *((volatile u8_t *) (0x35))
#define DDRC       *((volatile u8_t *) (0x34))
#define PINC       *((volatile u8_t *) (0x33))

//Peripheral D
#define PORTD      *((volatile u8_t *) (0x32))
#define DDRD       *((volatile u8_t *) (0x31))
#define PIND       *((volatile u8_t *) (0x30))

//Analogue to Digital Converter Registers
#define ADMUX      *((volatile u8_t *) (0x27))
#define ADCSRA     *((volatile u8_t *) (0x26))
#define ADCH       *((volatile u8_t *) (0x25))
#define ADCL       *((volatile u8_t *) (0x24))

//status register
#define  SREG      *((volatile u8_t *) (0x5F))

//General interrupt control register
#define  GICR      *((volatile u8_t *) (0x5B))

//General interrupt flag register
#define  GIFR      *((volatile u8_t *) (0x5A))

//MCU control register
#define MCUCR      *((volatile u8_t *) (0x55))

//MCU control and status register
#define  MCUCSR    *((volatile u8_t *) (0x54))

//Ports numbering
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

//ADMUX bit numbering
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define MUX4  4
#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0

//ADCSR bit numbering
#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

//GICR Bit numbering
#define INT1  7
#define INT0  6
#define INT2  5

//GIFR Bit numbering
#define INTF1 7
#define INTF0 6
#define INTF2 5

//MCUCR Bit numbering
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

//MCUCSR Bit numbering
#define ISC2  6

#endif /* PORTS_DEFINITIONS_H_ */
