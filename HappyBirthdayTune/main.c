/*
 * HappyBirthdayTune.c
 *
 * Created: 5/7/2017 8:58:19 PM
 * Author : Ruben Lopez
 * https://www.rlopezxl.com
 */ 

#define F_CPU 1200000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "SoundLib.h"

#define	BUZZER_PIN	PB0

// Common 4 notes.
void common(void) 
{
	tone(4, 7); // G
	_delay_ms(EIGHTH);
	stop_sound();
	tone(4, 7); // G
	_delay_ms(EIGHTH);
	tone(4, 9); // A
	_delay_ms(QUARTER);
	tone(4, 7); // G
	_delay_ms(QUARTER);
}

void delay(void) 
{
	stop_sound();
	_delay_ms(QUARTER + EIGHTH);
}

int main(void)
{
	//Setup
	DDRB |= _BV(BUZZER_PIN);
	init_sound();


	//Music loop
	while (1) {
		common();
		tone(5, 0); // C
		_delay_ms(QUARTER);
		tone(4, 11); // B
		_delay_ms(QUARTER);
		
		delay();
		
		common();
		tone(5, 2); // D
		_delay_ms(QUARTER);
		tone(5, 0); // C
		_delay_ms(QUARTER);
		
		delay();
		
		tone(4, 7); // G
		_delay_ms(EIGHTH);
		stop_sound();
		tone(4, 7); // G
		_delay_ms(EIGHTH);
		tone(5, 7); // G
		_delay_ms(QUARTER);
		tone(5, 4); // E
		_delay_ms(QUARTER);
		tone(5, 0); // C
		_delay_ms(QUARTER);
		tone(4, 11); // B
		_delay_ms(QUARTER);
		tone(4, 9); // A
		_delay_ms(QUARTER);
		
		delay();
		
		tone(5, 5); // F
		_delay_ms(EIGHTH);
		stop_sound();
		tone(5, 5); // F
		_delay_ms(EIGHTH);
		tone(5, 4); // E
		_delay_ms(QUARTER);
		tone(5, 0); // C
		_delay_ms(QUARTER);
		tone(5, 2); // D
		_delay_ms(QUARTER);
		tone(5, 0); // C
		_delay_ms(QUARTER);
		
		stop_sound();
		_delay_ms(WHOLE);
		
	}

}

