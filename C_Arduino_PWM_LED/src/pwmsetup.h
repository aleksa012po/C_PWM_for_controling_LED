/*
 * pwmsetup.h
 *
 * Created: 24.11.2022. 14:01:00
 *  Author: Aleksandar Bogdanovic
 */
#include <avr/io.h> 
#include <avr/interrupt.h>

double dutyCycle;

#ifndef PWMSETUP_H_
#define PWMSETUP_H_

void pwmsetup() {
	
	TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);		// TCCR0A = 0b10000011, Fast PWM, Clear OC0A on Compare match, set OC0A at bottom
	TIMSK0 = (1 << TOIE0);										// TIMSK0 = 0b00000001

	OCR0A =(dutyCycle/100.0)*255;

	sei();														// Interrupt Enable

	TCCR0B = (1 << CS00) | (1 << CS02);							// TCCR0B = 0b00000101
}


#endif /* PWMSETUP_H_ */