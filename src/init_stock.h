#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "oi.h"
#include "biscuit.h"
#include "biscuit_core.h"

#define CREATE_SONG  0
#define MODULE_SONG  1
#define USER_HW_SONG 2


void init_stock(void);
void init_stock_1(void);
void init_stock_2(void);
void init_stock_3(void);
void init_stock_4(void);
void init_stock_5(void);

void initialize(void);
void powerOnRobot(void);
void baud28k(void);
void delay10ms(uint16_t delay_10ms);
uint8_t byteRx(void);
void flushRx(void);
void byteTx(uint8_t value);
void defineSongs(void);
void run_all(void);