/*
 * utils.c
 *
 * Created: 17/01/2024 22:24:59
 *  Author: omara
 */ 
#include "utils.h"

uint8_t mapADCtoPWM(uint16_t adcValue) {
	// Apply a non-linear mapping to make the brightness change more perceptible
	return (uint8_t)((1.0 - (adcValue / 1023.0)) * 255);
}