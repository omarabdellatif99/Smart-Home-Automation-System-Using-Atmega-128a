/*
 * pwm.h
 *
 * Created: 17/01/2024 20:03:44
 *  Author: omara
 */ 


#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void PWM_init();
void setPWM(uint8_t duty);

#endif // PWM_H