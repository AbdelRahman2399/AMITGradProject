/*
 * main.c
 *
 *  Created on: Jan 15, 2021
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


int main(){
	SPI_INIT();
	setBit(DDRA,0);
	setBit(DDRA,1);
    DDRD=0xFF;




	while (1){
		SPI_SEND(0xFF);
	    if(recieved_spi == 0x31){
	    			setBit(PORTA,0);
	    		}
	    		if(recieved_spi == 0x32){
	    			clearBit(PORTA,0);
	    		}
	    	    if(recieved_spi == 0x33){
	    	    			setBit(PORTA,1);
	    	    		}
	    	    		if(recieved_spi == 0x34){
	    	    			clearBit(PORTA,1);
	    	    		}
		PORTD=recieved_spi;

	}

	return 0;
}
