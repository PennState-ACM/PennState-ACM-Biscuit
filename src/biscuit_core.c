#include "biscuit_core.h"


void bisc_buffer_send(uint8_t value) {
	//stall until the buffer is empty
	while(!(BISC_IO_STATUS_REG & BISC_IO_STATUS_EMPTY));

	//write the balue to the data buffer
	BISC_IO_DATA_REG = value;
}


uint8_t bisc_buffer_read(void) {
	//stall until the buffer is full
	while(!(BISC_IO_STATUS_REG & BISC_IO_STATUS_FULL));

	//read the data
	return BISC_IO_DATA_REG;
}


uint8_t bisc_buffer_isReady(void) {
	if(BISC_IO_STATUS_REG & BISC_IO_STATUS_FULL) {
		return BISC_TRUE;
	} else {
		return BISC_FALSE;
	}
}


void bisc_buffer_flush(void) {
	uint8_t temp;
	while(BISC_IO_STATUS_REG & BISC_IO_STATUS_FULL) {
		temp = BISC_IO_DATA_REG;
	}
}


void bisc_start(void) {
    bisc_buffer_send(BISC_CMD_START);
}


void bisc_baud(uint8_t value) {
	bisc_buffer_send(BISC_CMD_BAUD);
	
	//send the code
	bisc_buffer_send(value);
	
	//stall until the baud is set
	while(!(BISC_IO_STATUS_REG & BISC_IO_SEND_COMPLETE));
}


void bisc_mode_passive(void) {
    bisc_buffer_send(BISC_MODE_PASSIVE);
}


void bisc_mode_safe(void) {
    bisc_buffer_send(BISC_MODE_SAFE);
}


void bisc_mode_full(void) {
    bisc_buffer_send(BISC_MODE_FULL);
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
