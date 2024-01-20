/*
 * adc.c
 *
 * Created: 17/01/2024 20:03:16
 *  Author: omara
 */ 
#include "adc.h"

void ADC_init() {
    // Set the ADC reference voltage to AVcc
    ADMUX |= (1 << REFS0);

    // Enable the ADC and set the prescaler to 128 (for 1 MHz clock, gives 125 kHz ADC clock)
    ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_read(uint8_t channel) {
    // Select the ADC channel
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // Start a conversion
    ADCSRA |= (1 << ADSC);

    // Wait for the conversion to complete
    while (ADCSRA & (1 << ADSC));

    // Return the ADC result
    return ADC;
}