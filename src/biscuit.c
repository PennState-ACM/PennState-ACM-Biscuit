#include "biscuit.h"

void bisc_prepare() {
    //TODO: when we handle interrupt stuff, it will go here
    cli();

    sei();

    bisc_led_off(BISC_LED_BOTH);
    bisc_power_on();
    bisc_start();
    bisc_baud_all(BISC_BAUD_REC);
    bisc_mode_safe();
}

void bisc_power_on() {
    //check if the power is already on
    if(!BISC_PWR_IS_ON) {
        //loop until the power is on
        while(!BISC_PWR_IS_ON) {
            //a power tranisition happens when the powr toggles low to high
            //delays are included to let the create notice the change
            BISC_PWR_TOGGLE_LOW();
            bisc_delay(100);
            BISC_PWR_TOGGLE_HIGH();
            bisc_delay(100);
        }
        //toggle power back to low
        BISC_PWR_TOGGLE_LOW();

        //delay for create bootloader
        bisc_delay(2000);
    }
}

void bisc_baud_all(uint8_t code) {
   if(code >= 0 && code <= BISC_BAUD_MAX) {
       bisc_baud(code);

       //with the Create's baud set, set the command baud to match it
       cli();
       //if we value interrupts more than space preserved, move this call outside
       BISC_BAUD_REG = bisc_baud_atm_from_create(code);
       sei();
       bisc_delay(100);
   } 
}

uint16_t bisc_baud_atm_from_create(uint8_t code) {
    uint16_t atm_code = 0;
    
    //not sure if switch statements supported -- using if/else
    if(code == BISC_BAUD_300) {
        atm_code = BISC_ATM_BAUD_300;
    } 
    else if(code == BISC_BAUD_600) {
        atm_code = BISC_ATM_BAUD_600;
    } 
    else if(code == BISC_BAUD_1200) {
        atm_code = BISC_ATM_BAUD_1200;
    } 
    else if(code == BISC_BAUD_2400) {
        atm_code = BISC_ATM_BAUD_2400;
    } 
    else if(code == BISC_BAUD_4800) {
        atm_code = BISC_ATM_BAUD_4800;
    } 
    else if(code == BISC_BAUD_9600) {
        atm_code = BISC_ATM_BAUD_9600;
    } 
    else if(code == BISC_BAUD_14400) {
        atm_code = BISC_ATM_BAUD_14400;
    } 
    else if(code == BISC_BAUD_28800) {
        atm_code = BISC_ATM_BAUD_28800;
    }
    else if(code == BISC_BAUD_57600) {
        atm_code = BISC_ATM_BAUD_57600;
    }
    else if(code == BISC_BAUD_115200) {
        atm_code = BISC_ATM_BAUD_115200;
    }

    return atm_code;
}

void bisc_mode_passive() {
    bisc_setMode(BISC_MODE_PASSIVE);
}

void bisc_mode_safe() {
    bisc_setMode(BISC_MODE_SAFE);
}

void bisc_mode_full() {
    bisc_setMode(BISC_MODE_FULL);
}

void bisc_led_on(uint8_t led, uint8_t color, uint8_t intensity) {
    bisc_led(led, color, intensity);
}


void bisc_led_off(uint8_t led) {
    bisc_led(led, 0, 0);
}

void bisc_delay(uint16_t ms) {
    //for now, just busy wait
    _delay_ms(ms);
}
