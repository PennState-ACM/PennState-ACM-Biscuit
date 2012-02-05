
void baud(uint8_t baud_code);{
	//This function sets up the bits per second rate, command module is reccomended to be run at
	//28800 baud rate instead of the normal 57600 baud rate to prevent data corruption or something
	//like that that is not good. Basically, it's like instantiating a serial rate

	
	//This should be run on create
	//byteTx(129); /* baud opcode */
	//UCSR0A |= 0x40;
	//byteTx(8); /* baud code for 28800 */
	//while(!(UCSR0A & 0x40)) ; //wait for the change to take effect
	
	//Then make the command module match create
	//cli(); /* disable interrupts */
	//UBRR0 = 39;
	//sei(); /* enable interrupts */
	//delayMs(100);

	//Can use
	/*
	UBRR0 = (processor_frequency / (16 * baud_rate)) – 1
	UBRR0 = (18432000 / (16 * 28800)) – 1 = 39
	*/
	//For arbitrary baud rates but see no reason to do so
	// Switch the baud rate on both Create and module
	
	
	//Ohwait, it turns out the baud function was already implemented to near perfection, again the reccomended
	//input is "Baud28800" Why reinvent the weel, amirite broseph? *fistbump*
	//Goddamnit, good luck to whoever needs to put this thing into the c file
  if(baud_code <= 11)
  {
    byteTx(CmdBaud);
    UCSR0A |= _BV(TXC0);
    byteTx(baud_code);
    // Wait until transmit is complete
    while(!(UCSR0A & _BV(TXC0))) ;

    cli();

    // Switch the baud rate register
    if(baud_code == Baud115200)
      UBRR0 = Ubrr115200;
    else if(baud_code == Baud57600)
      UBRR0 = Ubrr57600;
    else if(baud_code == Baud38400)
      UBRR0 = Ubrr38400;
    else if(baud_code == Baud28800)
      UBRR0 = Ubrr28800;
    else if(baud_code == Baud19200)
      UBRR0 = Ubrr19200;
    else if(baud_code == Baud14400)
      UBRR0 = Ubrr14400;
    else if(baud_code == Baud9600)
      UBRR0 = Ubrr9600;
    else if(baud_code == Baud4800)
      UBRR0 = Ubrr4800;
    else if(baud_code == Baud2400)
      UBRR0 = Ubrr2400;
    else if(baud_code == Baud1200)
      UBRR0 = Ubrr1200;
    else if(baud_code == Baud600)
      UBRR0 = Ubrr600;
    else if(baud_code == Baud300)
      UBRR0 = Ubrr300;

    sei();

    delayMs(100);
	}
	}