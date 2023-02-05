/*
 * C_Arduino_Asembler,_PWM_LED.c
 *
 * Created: 24.11.2022. 13:06:42
 * Author : Aleksandar Bogdanovic
 */ 

// TCCR0A – Timer/Counter Control Register A
// Fast PWM
#define F_CPU 16000000											// 16MHz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "init.h"
#include "pwmsetup.h"

double dutyCycle = 0;

int main(void)
{
    init();
	
	pwmsetup();
	
    while (1) 
{
		_delay_ms(100);											// Delay
		
		dutyCycle += 10;
		
		if(dutyCycle >100) {
			dutyCycle = 0;										// When DutyCycle = 100, go from bottom = 0
		}
    }
}

ISR(TIMER0_OVF_vect) {											// Interrupt Service Routine
	OCR0A =(dutyCycle/100.0)*255;
}

