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
#include "UART_Driver.h"
#include "../DIO_Driver/macros.h"
extern unsigned char recieved_spi;
extern unsigned char y;

void SPI_INIT(){
	setBit(DDRB,SS);
	setBit(DDRB,MOSI);
	clearBit(DDRB,MISO);
	setBit(DDRB,SCK);
	setBit(PORTB,SS);

	setBit(SPCR,SPE);
	setBit(SPCR,DORD);
	setBit(SPCR,MSTR);
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
	UART_send(recieved_spi);
}
