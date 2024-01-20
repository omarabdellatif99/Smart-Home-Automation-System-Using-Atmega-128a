/*
 * adc.h
 *
 * Created: 17/01/2024 20:03:04
 *  Author: omara
 */ 


#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void ADC_init();
uint16_t ADC_read(uint8_t channel);

#endif // ADC_H