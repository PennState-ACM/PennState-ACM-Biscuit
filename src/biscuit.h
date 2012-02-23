#ifndef __BISCUIT_
#define __BISCUIT_

#include <avr/interrupt.h>
#include <util/delay.h>

#include "biscuit_core.h"

/*
 * Power related macros
 *
 * Power High bit is 0x80 on PORTD
 * Power Sense bit is 0x20 on PINB
 */
#define BISC_PWR_HIGH               0x80
#define BISC_PWR_SENSE              0x20
#define BISC_PWR_TOGGLE_HIGH()      (PORTD |= BISC_PWR_HIGH)
#define BISC_PWR_TOGGLE_LOW()       (PORTD &= ~BISC_PWR_HIGH)
#define BISC_PWR_IS_ON              (PINB & BISC_PWR_SENSE)


/*
 * Prepares the Create to execute programs
 */
void bisc_init(void);

/*
 * Powers on the Create
 */
void bisc_power_on(void);

/*
 * Sets the same baud rate for the Create and for the Command module
 * 
 * code: must be of one of the BISC_BAUD values
 */
void bisc_baud_all(uint8_t code);

/*
 * Sets the operating mode of Create to passive
 */
void bisc_mode_passive(void);

/*
 * Sets the operating mode of Create to safe
 */
void bisc_mode_safe(void);

/*
 * Sets the operating mode of Create to full
 */
void bisc_mode_full(void);

/*
 * Turns on the given led with given color and intensity
 * 
 * led: must be of BISC_LED
 * color: integer 0-255 from green to red
 * intensity: integer 0-255 from 0% to 100%
 */
void bisc_led_on(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * Turns of the given led
 * 
 * led: must be of BISC_LED
 */
void bisc_led_off(uint8_t led);


/*
 * Busy clock cycles to stall for time in milliseconds
 */
void bisc_delay(uint16_t ms);


/*
 * Define a song to play
 */
void bisc_define_song(uint8_t song_num, uint8_t song_len, uint8_t *notes);

/*
 * Play the given song. Song must have previously defined
 */
void bisc_play_song(uint16_t song_num);

#endif