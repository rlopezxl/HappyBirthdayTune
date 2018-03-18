/**
 * Copyright (c) 2016, ?ukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 * ATtiny13/007 https://github.com/lpodkalicki/blog/tree/master/avr/attiny13/007_tone_generator
 * Simple tone generator.
 *
 * Modified by Ruben Lopez
 */

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#define	N_1	(_BV(CS00))
#define	N_8	(_BV(CS01))
#define	N_64	(_BV(CS01)|_BV(CS00))
#define	N_256	(_BV(CS02))
#define	N_1024	(_BV(CS02)|_BV(CS00))

#define BPM 120
#define QUARTER 60000 / BPM
#define HALF QUARTER * 2
#define EIGHTH QUARTER / 2
#define SIXTEENTH QUARTER / 4
#define WHOLE HALF * 2

typedef struct s_note {
	uint8_t OCRxn; // 0..255
	uint8_t N;
} note_t;

typedef struct s_octave {
	note_t note_C;
	note_t note_CS;
	note_t note_D;
	note_t note_DS;
	note_t note_E;
	note_t note_F;
	note_t note_FS;
	note_t note_G;
	note_t note_GS;
	note_t note_A;
	note_t note_AS;
	note_t note_B;
} octave_t;


void tone(uint8_t octave, uint8_t note);
void stop_sound(void);
void init_sound(void);

