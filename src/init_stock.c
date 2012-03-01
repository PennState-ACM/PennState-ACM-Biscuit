#include "init_stock.h"

void init_stock(void) {
  initialize();
  powerOnRobot();
  baud28k();
  byteTx(CmdFull);
  flushRx();
}

void init_stock_1(void){
  bisc_init();
  powerOnRobot();
  baud28k();
  byteTx(CmdFull);
  flushRx();
}

void init_stock_2(void) {
    bisc_init();
    bisc_power_on();
    baud28k();
    byteTx(CmdFull);
    flushRx();
}

void init_stock_3(void) {
    bisc_init();
    bisc_power_on();
    bisc_baud_all(BISC_BAUD_REC);
    byteTx(CmdFull);
    flushRx();
}

void init_stock_4(void) {
    bisc_init();
    bisc_power_on();
    bisc_baud_all(BISC_BAUD_REC);
    bisc_mode_full();
    flushRx();
}

void init_stock_5(void) {
    bisc_init();
    bisc_power_on();
    bisc_baud_all(BISC_BAUD_REC);
    bisc_mode_full();
    bisc_buffer_flush();
}

void initialize(void)
{
  // Turn off interrupts
  cli();

  // Configure the I/O pins
  DDRB = 0x10;
  PORTB = 0xCF;
  DDRC = 0x02;
  PORTC = 0xFF;
  DDRD = 0xE6;
  PORTD = 0x7D;

  // Set up the serial port for 57600 baud
  UBRR0 = Ubrr57600;
  UCSR0B = (_BV(TXEN0) | _BV(RXEN0));
  UCSR0C = (_BV(UCSZ00) | _BV(UCSZ01));
}

void powerOnRobot(void)
{
  // If Create's power is off, turn it on
  if(!RobotIsOn)
  {
      while(!RobotIsOn)
      {
          RobotPwrToggleLow;
          delay10ms(50);  // Delay in this state
          RobotPwrToggleHigh;  // Low to high transition to toggle power
          delay10ms(10);  // Delay in this state
          RobotPwrToggleLow;
      }
      delay10ms(350);  // Delay for startup
  }
}

void baud28k(void)
{
  // Send the baud change command for 28800 baud
  byteTx(CmdBaud);
  byteTx(Baud28800);

  // Wait while until the command is sent
  while(!(UCSR0A & _BV(TXC0))) ;

  // Change the atmel's baud rate
  UBRR0 = Ubrr28800;

  // Wait 100 ms
  delay10ms(10);
}

void delay10ms(uint16_t delay_10ms)
{
  // Delay for (delay_10ms * 10) ms
  while(delay_10ms-- > 0)
  {
    // Call a 10 ms delay loop
    _delay_loop_2(46080);
  }
}

uint8_t byteRx(void)
{
  // Receive a byte over the serial port (UART)
  while(!(UCSR0A & _BV(RXC0))) ;
  return UDR0;
}

void flushRx(void)
{
  uint8_t temp;

  // Clear the serial port
  while(UCSR0A & _BV(RXC0))
    temp = UDR0;
}

void byteTx(uint8_t value)
{
  // Send a byte over the serial port
  while(!(UCSR0A & _BV(UDRE0))) ;
  UDR0 = value;
}
