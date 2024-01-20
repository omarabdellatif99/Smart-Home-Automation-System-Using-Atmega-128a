/*
 * init.c
 *
 * Created: 17/01/2024 01:04:10
 *  Author: omara
 */ 
#include "settings.h"
#include "init.h"

void hardware_init(void) {
	// Set Flame (PINA0) as an input
	DDRD &= ~(1 << FLAME_PIN);
	// Set PIR motion as input
	DDRB &= ~(1 << PIR_Motion);
	// Enable internal pull-up resistor for BUTTON_PIN
	PORTA |= (1 << FLAME_PIN);
	// Set SOUND_SENSOR_PIN (PE3) as input for sound sensor
	DDRE &= ~(1 << SOUND_SENSOR_PIN);
	// Set PB0 as output for LED
	DDRB |= (1 << PIR_LEDPIN);
	DDRA |= (1 << LED_PIN);
	DDRC &= ~(1 << BUTTON_PIN);
	// Enable pull-up resistor on the button pin
	PORTC |= (1 << BUTTON_PIN);
	// Set the LED pin as output
	EIMSK |= (1 << INT0);
	EICRA |= (1 << ISC01); // Set ISC01
	EICRA &= ~(1 << ISC00); // Clear ISC00
	EIMSK |= (1 << INT1);
	// Set for positive edge trigger
	EICRA |= (1 << ISC10) | (1 << ISC11);
	EIMSK |= (1 << INT2); // Enable INT1
	EICRA |= (1 << ISC20) | (1 << ISC21);
}