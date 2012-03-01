#ifndef __BISCUIT_CORE_
#define __BISCUIT_CORE_

#include <stdlib.h>
#include <avr/io.h>


/*
 * Opcode values
 */
#define BISC_CMD_START          128
#define BISC_CMD_BAUD           129
#define BISC_CMD_LED            139
#define BISC_CMD_SENSORS        142
#define BISC_CMD_SEND_IR        151
#define BISC_CMD_DEFINE_SONG    140
#define BISC_CMD_PLAY_SONG      141


/*
 * IO registry values and bitfields
 */

 /*
 * Buffer settings
 * NOTE: For all I/O buffer information,
 *  See that Atmega168 Reference (Document 02), Section 18.9
 *  Also see Section 29. Registry summary for registers UDR0 and UCSR0A
 */
#define BISC_IO_DATA_REG        UDR0
#define BISC_IO_STATUS_REG      UCSR0A

//UCSR0A bit 5
#define BISC_IO_STATUS_EMPTY    _BV(UDRE0)
//USCR0A bit 7
#define BISC_IO_STATUS_FULL     (1 << 7)

//UCSR0A bit 6
#define BISC_IO_SEND_COMPLETE	_BV(TXC0)

/*
 * Baud registry and codes
 */
#define BISC_BAUD_REG           UBRR0

//Create baud codes
#define BISC_BAUD_300           0
#define BISC_BAUD_600           1
#define BISC_BAUD_1200          2
#define BISC_BAUD_2400          3
#define BISC_BAUD_4800          4
#define BISC_BAUD_9600          5
#define BISC_BAUD_14400         6
#define BISC_BAUD_19200         7
#define BISC_BAUD_28800         8
#define BISC_BAUD_38400         9
#define BISC_BAUD_57600         10
#define BISC_BAUD_115200        11

#define BISC_BAUD_REC           BISC_BAUD_28800
#define BISC_BAUD_MAX			BISC_BAUD_115200

//command module codes
#define BISC_ATM_BAUD_300       3839
#define BISC_ATM_BAUD_600       1919
#define BISC_ATM_BAUD_1200      959
#define BISC_ATM_BAUD_2400      479
#define BISC_ATM_BAUD_4800      239
#define BISC_ATM_BAUD_9600      119
#define BISC_ATM_BAUD_14400     79
#define BISC_ATM_BAUD_19200     59
#define BISC_ATM_BAUD_28800     39
#define BISC_ATM_BAUD_38400     29
#define BISC_ATM_BAUD_57600     19
#define BISC_ATM_BAUD_115200    9

#define BISC_ATM_BAUD_REC		BISC_ATM_BAUD_28800
#define BISC_ATM_BAUD_MAX		BISC_ATM_BAUD_115200




/*
 * LED values
 */
#define BISC_LED_POWER          0x08
#define BISC_LED_ADVANCE        0x02
#define BISC_LED_BOTH           0x0A


/*
 * Mode values
 */
#define BISC_MODE_PASSIVE       128
#define BISC_MODE_SAFE          131
#define BISC_MODE_FULL          132


/*
 * IR values
 */
#define BISC_IR_RC_LEFT         129
#define BISC_IR_RC_FRWRD        130
#define BISC_IR_RC_RIGHT        131
#define BISC_IR_RC_SPOT         132
#define BISC_IR_RC_MAX          133
#define BISC_IR_RC_SMALL        134
#define BISC_IR_RC_MED          135
#define BISC_IR_RC_LRGCLN       136
#define BISC_IR_RC_PAUSE        137
#define BISC_IR_RC_POWER        138
#define BISC_IR_RC_ARC_LEFT     139
#define BISC_IR_RC_ARC_RIGHT    140
#define BISC_IR_RC_DRVSTOP      141
#define BISC_IR_SR_SNDALL       142
#define BISC_IR_SR_SKDOCK       143
#define BISC_IR_HB_RSRVD        240
#define BISC_IR_HB_FLD          242
#define BISC_IR_HB_GRN          244
#define BISC_IR_HB_GRNFLD       246
#define BISC_IR_HB_RED          248
#define BISC_IR_HB_REDFLD       250
#define BISC_IR_HB_RDGRN        252
#define BISC_IR_HB_ALL          254


/*
 * Sensor values
 */
#define BISC_SENS_GRP0          0
#define BISC_SENS_GRP1          1
#define BISC_SENS_GRP2          2
#define BISC_SENS_GRP3          3
#define BISC_SENS_GRP4          4
#define BISC_SENS_GRP5          5
#define BISC_SENS_GRP6          6
#define BISC_SENS_BUMPSWHL      7
#define BISC_SENS_WALL          8
#define BISC_SENS_CLIFF_LEFT    9
#define BISC_SENS_CLIFF_FLEFT   10
#define BISC_SENS_CLIFF_FRIGHT  11
#define BISC_SENS_CLIFF_RIGHT   12
#define BISC_SENS_VWALL         13
#define BISC_SENS_OVRCURRENTS   14
#define BISC_SENS_IR            17
#define BISC_SENS_BUTTONS       18
#define BISC_SENS_DISTANCE      19
#define BISC_SENS_ANGLE         20
#define BISC_SENS_CHARGING      21
#define BISC_SENS_VOLTAGE       22
#define BISC_SENS_CURRENT       23
#define BISC_SENS_BATRY_TEMP    24
#define BISC_SENS_BATRY_CHARGE  25
#define BISC_SENS_BATRY_CAPAC   26
#define BISC_SENS_SIG_WALL      27
#define BISC_SENS_SIG_LCLIFF    28
#define BISC_SENS_SIG_FLCLIFF   29
#define BISC_SENS_SIG_FRCLIFF   30
#define BISC_SENS_SIG_RCLIFF    31
#define BISC_SENS_INPUT_UD      32
#define BISC_SENS_INPUT_UA      33
#define BISC_SENS_CHRGSOURCE    34
#define BISC_SENS_OIMODE        35
#define BISC_SENS_SONG_NUM      36
#define BISC_SENS_SONG_PLAY     37
#define BISC_SENS_STREAMPACK    38
#define BISC_SENS_VELOCITY      39
#define BISC_SENS_RADIUS        40
#define BISC_SENS_RVELOCITY     41
#define BISC_SENS_LVELOCITY     42

/*
 * Sensor boundary values
 */
#define BISC_SENS_MIN           0
#define BISC_SENS_MAX           42


/*
 * Error Values
 */
#define BISC_ERR_NONE           0
#define BISC_ERR_INVALID        -1


/*
 * Boolean values
 */
#define BISC_TRUE               1
#define BISC_FALSE              0

/*
 * Macros to get the high and low bytes
 */
#define BISC_HIGH_BYTE(xValue)  ((uint8_t)(((xValue) >> 8) & 0x00FF))
#define BISC_LOW_BYTE(xValue)   ((uint8_t)((xValue) & 0x00FF))

/*
 * Macros to set and check the state of pins
 *
 * Conventions:
 *      H   =   High
 *      L   =   Low
 *      C   =   Check
 *      S   =   Set
 *      U   =   Unset
 *
 *  e.g. BISC_PIN_SH = set the pin to high
 */
#define BISC_PIN_H              0x80
#define BISC_PIN_L              0x04
#define BISC_PIN_CH(pin)        ((pin) & BISC_PIN_H)
#define BISC_PIN_CL(pin)        ((pin) & BISC_PIN_L)
#define BISC_PIN_SH(pin)        ((pin) |= BISC_PIN_H)
#define BISC_PIN_SL(pin)        ((pin) |= BISC_PIN_L)
#define BISC_PIN_UH(pin)        ((pin) &= ~BISC_PIN_H)
#define BISC_PIN_UL(pin)        ((pin) &= ~BISC_PIN_L)


/*
 * Transfers a byte to the Create
 */
void bisc_buffer_send(uint8_t value);

/*
 * Transfers a byte from the Create
 */
uint8_t bisc_buffer_read(void);

/*
 * Returns BISC_TRUE if a byte is available for recieving
 * Returns BISC_FALSE otherwise
 */
uint8_t bisc_buffer_isReady(void);

/*
 * Clears the byte being received in the data IO buffer
 * And sets the control register to be able to send
 */
void bisc_buffer_flush(void);

/*
 * Starts the Open Interface
 */
void bisc_start(void);

/*
 * Set the baud rate of the Create
 */
void bisc_baud(uint8_t value);

/*
 * Set the baud of the command module
 */
void bisc_atm_baud(uint8_t code);

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
 * description
 * 
 * led: 
 * color: integer 0-255 from green to red
 * intensity: integer 0-255 from 0% to 100%
 */
void bisc_led(uint8_t led, uint8_t color, uint8_t intensity);

/*
 * Send the given value TO the IR receiver
 * DOES NOT send the given value FROM the receiver
 * 
 * value: any of the BISC_IR values
 * TODO: Find out what Document 3 means by using a preload resistor
 */
void bisc_sendIR(uint8_t value);


/*
 * Gets the byte packet from the given sensor
 *
 * sensor: a BISC_SENS value representing the desired sensors
 * values: an array to hold the returned bytes
 *  should be allocated
 * size: the number of bytes to place in 'values'
 *  should not be larger than the sensor packet returned
 */
int8_t bisc_sensors(uint8_t sensor, uint8_t* values, uint8_t size);

#endif
