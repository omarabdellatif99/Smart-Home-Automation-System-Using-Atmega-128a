/*
 * buzzer.c
 *
 * Created: 16/01/2024 15:55:48
 *  Author: omara
 */ 
#include "buzzer.h"
#include "settings.h"
#include <util/delay.h>



void buzzer2_init(void) {
	DDR_BUZZER |= (1 << BIT_BUZZER2); // Set Pin as output
	TCCR0 = 0; // Reset Timer Register
	TCCR0 |= (1 << WGM21); // CTC mode
	TCCR0 |= (1 << COM20); // Toggle Mode
	TCCR0 |= (1 << CS20); // No prescaler ==> Timer2 clock is 1MHz
	OCR0 = 0x00;
}

void buzzer2_tone(void) {
	OCR0 = 255;
	_delay_ms(10);
	OCR0 = 0;
	_delay_ms(10);
}