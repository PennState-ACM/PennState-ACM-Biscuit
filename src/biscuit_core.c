#include "biscuit_core.h"


void bisc_core_start() {
    byteTx(BISC_CMD_START);
}


void bisc_core_setMode(uint8_t mode) {
    byteTx(mode);
}


//TODO: Check for out-of-bounds values
void bisc_core_led(uint8_t led, uint8_t color, uint8_t intensity) {
    byteTx(BISC_CMD_LED);
    byteTx(led);
    byteTx(color);
    byteTx(intensity);
}


void bisc_core_sendIR(uint8_t value) {
    byteTx(BISC_CMD_SEND_IR);
    byteTx(value);
}

int8_t bisc_core_sensors(uint8_t sensor, uint8_t* values, uint8_t size) {
	//exit on invalid sensor data or null values
	if(sensor < BISC_SENS_MIN || sensor > BISC_SENS_MAX 
		|| values == NULL) {
		return BISC_ERR_INVALID;
	}

	//send the command to query for sensor data
	byteTx(BISC_CMD_SENSORS);
	byteTx(sensor);

	//place the returned sensor data in values
	for(int i = 0; i < size; i++) {
		values[i] = byteRx();
	}

	//everything went smoothly
	return BISC_ERR_NONE;
}
