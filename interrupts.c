#include "interrupts.h"
#include "buzzer.h"
#include "sensors.h"
#include <avr/interrupt.h>

volatile int btnflag = 0;// Defined here

ISR(INT0_vect) {
	sei();
	btnflag = 1;
}

ISR(INT1_vect) {
	sei();
	buzzer2_init();
	while(btnflag == 0) {
		buzzer2_tone();
	}
}

ISR(INT2_vect) {
	sei();
	soundtoggle();
}