#include "biscuit_core.h"

void bisc_buffer_send(uint8_t value) {
	while(!(BISC_REG_IO_STATUS & BISC_BUFFER_EMPTY));
	BISC_REG_IO_DATA = value;
}

uint8_t bisc_buffer_read() {
	while(!(BISC_REG_IO_STATUS & BISC_BUFFER_FULL));
	return BISC_REG_IO_DATA;
}

uint8_t bisc_buffer_isReady() {
	if(BISC_REG_IO_STATUS & BISC_BUFFER_FULL) {
		return BISC_TRUE;
	} else {
		return BISC_FALSE;
	}
}

void bisc_buffer_clear() {
	BISC_REG_IO_DATA = 0;
	BISC_REG_IO_STATUS = BISC_BUFFER_EMPTY;
}

void bisc_start() {
    bisc_buffer_send(BISC_CMD_START);
}


void bisc_setMode(uint8_t mode) {
    bisc_buffer_send(mode);
}


//TODO: Check for out-of-bounds values
void bisc_led(uint8_t led, uint8_t color, uint8_t intensity) {
    bisc_buffer_send(BISC_CMD_LED);
    bisc_buffer_send(led);
    bisc_buffer_send(color);
    bisc_buffer_send(intensity);
}


void bisc_sendIR(uint8_t value) {
    bisc_buffer_send(BISC_CMD_SEND_IR);
    bisc_buffer_send(value);
}

int8_t bisc_sensors(uint8_t sensor, uint8_t* values, uint8_t size) {
	//exit on invalid sensor data or null values
	if(sensor < BISC_SENS_MIN || sensor > BISC_SENS_MAX 
		|| values == NULL) {
		return BISC_ERR_INVALID;
	}

	//send the command to query for sensor data
	bisc_buffer_send(BISC_CMD_SENSORS);
	bisc_buffer_send(sensor);

	//place the returned sensor data in values
	for(int i = 0; i < size; i++) {
		if(bisc_buffer_isReady()) {
			values[i] = bisc_buffer_read();
		} else {
			break;
		}
	}

	//everything went smoothly
	return BISC_ERR_NONE;
}