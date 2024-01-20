#include "sensors.h"
#include "settings.h"
#include <util/delay.h>


void readSensorAndReact() {
	int flag = 0;

	// Check if the sensor is active
	while (PINA & (1 << PIR_Motion)) {
		PORTB |= (1 << PIR_LEDPIN); // Turn on LED if motion detected
		flag = 1;
	}
	// Delay after the sensor is no longer active
	if (flag == 1) {
		_delay_ms(172);
	}
	// Turn off the LED
	PORTB &= ~(1 << PIR_LEDPIN);

	// Recursive call with decremented count not needed
	/*if (count >= 0) {
		readSensorAndReact(count - 1);
	}*/
}
void soundtoggle() {
    static int isClap = 0;
    static int ledState = 0;

    PORTA &= ~(1 << LED_PIN);

    if (PIND & (1 << SOUND_SENSOR_PIN)) {
        if (!isClap) {
            ledState = !ledState;
            isClap = 1;
            _delay_ms(80); // Debounce delay
        }
    } else {
        isClap = 0;
    }

    if (ledState)
        PORTA |= (1 << LED_PIN);   // Turn on LED
    else
        PORTA &= ~(1 << LED_PIN);  // Turn off LED
}