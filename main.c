#include "settings.h"
#include "interrupts.h"
#include "buzzer.h"
#include "sensors.h"
#include "init.h"
#include "adc.h"
#include "pwm.h"
#include "utils.h"
#include <util/delay.h>
#include <avr/interrupt.h>
void readSensorAndReact();
void soundtoggle();
void ADC_init();
void PWM_init();

int main(void)
{
	hardware_init();
	sei();
	ADC_init();
	PWM_init();
	
	while (1)
	{
		uint16_t adcValue = ADC_read(0); // Replace with actual ADC channel
		uint8_t pwmValue = mapADCtoPWM(adcValue);
		setPWM(pwmValue);
		
		if (btnflag == 1) {
			// Do something if needed
			btnflag = 0; // Reset btnflag after acknowledging it
		}
		readSensorAndReact();
	}
	return 0;
}