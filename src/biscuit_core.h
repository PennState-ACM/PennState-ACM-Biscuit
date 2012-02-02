#include <stdlib.h>
#include <avr/io.h>

#define BISC_CMD_LED 		139
#define BISC_CMD_SEND_IR	151

#define BISC_LED_POWER		0x08
#define BISC_LED_ADVANCE	0x02
#define BISC_LED_BOTH		0x0A

#define BISC_HIGH_BYTE(xValue) ((uint8_t)(((xValue) >> 8) & 0x00FF))
#define BISC_LOW_BYTE(xValue) 	((uint8_t)((xValue) & 0x00FF))

/*
 * description
 * color: integer 0-255 from green to red
 * intensity: integer 0-255 from 0% to 100%
 */
void bisc_core_led(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * Send the given value to the IR receiver
 * DOES NOT send the given value from the receiver
 * NOTE: This may actually be useless
 * TODO: Find out what Document 3 means by using a preload resistor
 */
void bisc_core_sendIR(uint8_t value);
