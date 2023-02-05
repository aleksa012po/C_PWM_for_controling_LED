/*
 * init.h
 *
 * Created: 24.11.2022. 13:49:42
 *  Author: Aleksandar Bogdanovic
 */ 
#include <avr/io.h>

#ifndef INIT_H_
#define INIT_H_

void init() {
	DDRD =  (1 << PORTD6);
	PORTD = (1 << PORTD6);
}

#endif /* INIT_H_ */