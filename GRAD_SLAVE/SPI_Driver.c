/*
 * SPI_Driver.c
 *
 *  Created on: Dec 11, 2020
 *      Author: Abdelrahman
 */

#include "stdlib.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include"avr/delay.h"
#include "SPI_Driver.h"
#include "SPI_Config.h"
#include "macros.h"
extern unsigned char recieved_spi;


void SPI_INIT(){
	clearBit(DDRB,SS);
	clearBit(DDRB,MOSI);
	setBit(DDRB,MISO);
	clearBit(DDRB,SCK);

	setBit(SPCR,SPE);
	setBit(SPCR,DORD);
	setBit(SPCR,CPOL);

	setBit(SPCR,SPIE);
	sei();

}

void SPI_SEND(unsigned char c){
	clearBit(PORTB,SS);
		SPDR=c;
		_delay_ms(10);
		setBit(PORTB,SS);

}






ISR(SPI_STC_vect){

	recieved_spi=SPDR;

}
