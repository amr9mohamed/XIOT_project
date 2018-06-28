/*
 * ADC.h
 *
 *  Created on: Jun 25, 2018
 *      Author: amr
 */

#ifndef ADC_H_
#define ADC_H_

//configuration section
#define ADCPort    PortA
#define ADCPortDir 0x00
#define ADMUXInit  0x40
#define ADCSRAInit 0x07

#define RIGHT 0
#define LEFT  1

//prototype section
void ADC_Initialize();
void ADC_MuxSelection(u8_t);
u8_t ADC_isConversionComplete();
void ADC_ClearADIF();
u16_t ADC_getVal();
void ADC_StartConversion();
void ADC_Adjustment(u8_t);
void ADC_EnableINT();
void ADC_EnableADC();
void ADC_PescalerValue(u8_t);

#endif /* ADC_H_ */
