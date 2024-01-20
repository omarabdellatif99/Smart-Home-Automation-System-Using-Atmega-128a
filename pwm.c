/*
 * pwm.c
 *
 * Created: 17/01/2024 20:03:29
 *  Author: omara
 */ 
#include "pwm.h"
#include "Settings.h"

#include "pwm.h"

void PWM_init() {
    // Set the LED pin as output
     DDRB |= (1 << Lightph); // assuming Lightph is the correct pin for your LED

     // Fast PWM mode, non-inverting
     TCCR2 |= (1 << WGM20) | (1 << COM21);

     // No prescaler, PWM frequency = F_CPU / 256
     TCCR2 |= (1 << CS20);
}

void setPWM(uint8_t duty) {
    OCR2 = duty;
}