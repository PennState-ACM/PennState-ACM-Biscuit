#include <stdlib.h>
#include <avr/io.h>

#define BISC_CMD_LED        139
#define BISC_CMD_SENSORS    142
#define BISC_CMD_SEND_IR    151

#define BISC_LED_POWER      0x08
#define BISC_LED_ADVANCE    0x02
#define BISC_LED_BOTH       0x0A

#define BISC_IR_RC_LEFT     129
#define BISC_IR_RC_FRWRD    130    
#define BISC_IR_RC_RIGHT    131
#define BISC_IR_RC_SPOT     132
#define BISC_IR_RC_MAX      133
#define BISC_IR_RC_SMALL    134
#define BISC_IR_RC_MED      135
#define BISC_IR_RC_LRGCLN   136
#define BISC_IR_RC_PAUSE    137
#define BISC_IR_RC_POWER    138
#define BISC_IR_RC_ALEFT    139
#define BISC_IR_RC_ARIGHT   140
#define BISC_IR_RC_DRVSTOP  141
#define BISC_IR_SR_SNDALL   142
#define BISC_IR_SR_SKDOCK   143
#define BISC_IR_HB_RSRVD    240
#define BISC_IR_HB_FLD      242
#define BISC_IR_HB_GRN      244
#define BISC_IR_HB_GRNFLD   246
#define BISC_IR_HB_RED      248
#define BISC_IR_HB_REDFLD   250
#define BISC_IR_HB_RDGRN    252
#define BISC_IR_HB_ALL      254


#define BISC_HIGH_BYTE(xValue)  ((uint8_t)(((xValue) >> 8) & 0x00FF))
#define BISC_LOW_BYTE(xValue)   ((uint8_t)((xValue) & 0x00FF))

/*
 * description
 * 
 * led: 
 * color: integer 0-255 from green to red
 * intensity: integer 0-255 from 0% to 100%
 */
void bisc_core_led(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * Send the given value to the IR receiver
 * DOES NOT send the given value from the receiver
 * 
 * value: any of the BISC_IR values
 * TODO: Find out what Document 3 means by using a preload resistor
 */
void bisc_core_sendIR(uint8_t value);
