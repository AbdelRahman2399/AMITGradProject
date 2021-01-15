/*
 * main.c
 *
 *  Created on: Jan 15, 2021
 *      Author: Abdelrahman
 */
#include "avr/io.h"
#include "avr/interrupt.h"
#include "avr/delay.h"
#include "stdlib.h"
#include "string.h"
#include "UART_Driver.h"
#include "UART_config.h"
#include "SPI_Driver.h"
#include "SPI_Config.h"
#include "macros.h"

extern unsigned char rec;

int main(){
	UART_init();
	SPI_INIT();
	UART_sendString("Hello");
	while (1){

	}



	return 0;
}

