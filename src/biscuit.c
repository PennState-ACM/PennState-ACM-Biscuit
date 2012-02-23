#include "biscuit.h"


void bisc_init(void) {
    //TODO: when we handle interrupt stuff, it will go here
    cli();

    // Configure the I/O pins
    //TODO: Find out what these pin values mean
    DDRB = 0x10;
    PORTB = 0xCF;
    DDRC = 0x02;
    PORTC = 0xFF;
    DDRD = 0xE6;
    PORTD = 0x7D;

    bisc_baud_atm(BISC_ATM_BAUD_57600);

    bisc_led_off(BISC_LED_BOTH);
    bisc_power_on();
    bisc_start();
    bisc_baud_all(BISC_BAUD_REC);
    bisc_mode_safe();
}


void bisc_power_on(void) {
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
    // warning: comparison is always true due to limited range of data type
    if(code >= 0 && code <= BISC_BAUD_MAX) {
        bisc_baud(code);
        BISC_BAUD_REG = bisc_baud_atm_from_create(code);
        bisc_delay(100);
    } 
}

void bisc_baud_atm(uint8_t code) {
    BISC_BAUD_REG = code;
    UCSR0B = (_BV(TXEN0) | _BV(RXEN0));
    UCSR0C = (_BV(UCSZ00) | _BV(UCSZ01));
}


uint16_t bisc_baud_atm_from_create(uint8_t code) {
    uint16_t atm_code = 0;
    
    //not sure if switch statements supported -- using if/else
    if(code == BISC_BAUD_300) {
        atm_code = BISC_ATM_BAUD_300;
    } else if(code == BISC_BAUD_600) {
        atm_code = BISC_ATM_BAUD_600;
    } else if(code == BISC_BAUD_1200) {
        atm_code = BISC_ATM_BAUD_1200;
    } else if(code == BISC_BAUD_2400) {
        atm_code = BISC_ATM_BAUD_2400;
    } else if(code == BISC_BAUD_4800) {
        atm_code = BISC_ATM_BAUD_4800;
    } else if(code == BISC_BAUD_9600) {
        atm_code = BISC_ATM_BAUD_9600;
    } else if(code == BISC_BAUD_14400) {
        atm_code = BISC_ATM_BAUD_14400;
    } else if(code == BISC_BAUD_28800) {
        atm_code = BISC_ATM_BAUD_28800;
    } else if(code == BISC_BAUD_57600) {
        atm_code = BISC_ATM_BAUD_57600;
    } else if(code == BISC_BAUD_115200) {
        atm_code = BISC_ATM_BAUD_115200;
    }

    return atm_code;
}


void bisc_mode_passive(void) {
    bisc_setMode(BISC_MODE_PASSIVE);
}


void bisc_mode_safe(void) {
    bisc_setMode(BISC_MODE_SAFE);
}


void bisc_mode_full(void) {
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


void bisc_define_song(uint8_t song_num, uint8_t song_len, uint8_t *notes) {
    bisc_buffer_send(BISC_CMD_DEFINE_SONG);
    bisc_buffer_send(song_num);
    bisc_buffer_send(song_len);

    for(int i=0; i<song_len*2; i++) {
        bisc_buffer_send(notes[i]);
    }
}


void bisc_play_song(uint16_t song_num) {
    bisc_buffer_send(BISC_CMD_PLAY_SONG);
    bisc_buffer_send(song_num);
}
