/*
 * Settings.h
 *
 * Created: 16/01/2024 15:47:48
 *  Author: omara
 */ 
#ifndef SETTINGS_H_
#define SETTINGS_H_
#define F_CPU 16000000UL
#include <avr/io.h>

// Pin Definitions
#define DDR_BUZZER DDRB
#define BIT_BUZZER2 PORTB4
#define Lightph PORTB7
#define FLAME_PIN PIND1
#define SOUND_SENSOR_PIN PIND2
#define PIR_Motion PINA2
#define PIR_LEDPIN PINB3
#define LED_PIN PINA0
#define BUTTON_PIN PINC7

// Delay Definitions
#define led_delay 100
#define pir_delay 200
#define SOUND_DETECTED_DURATION 1
#define DEBOUNCE_TIME 30


#endif /* SETTINGS_H_ */