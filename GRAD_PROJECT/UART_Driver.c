/*
 * UART_Driver.c
 *
 *  Created on: Dec 5, 2020
 *      Author: Abdelrahman
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "stdlib.h"
#include "string.h"
#include "UART_Driver.h"
#include "SPI_Driver.h"
#include "SPI_Config.h"
#include "macros.h"
extern unsigned char rec;
void UART_init(){
	setBit(UCSRB,TXEN);
	setBit(UCSRB,RXEN);
	UBRRL=103;
	UBRRH=(103>>8);
	clearBit(UCSRC,UMSEL);
	clearBit(UCSRC,UPM1);
	clearBit(UCSRC,UPM0);
	clearBit(UCSRC,USBS);
	clearBit(UCSRB,UCSZ2);
	setBit(UCSRC,UCSZ1);
	setBit(UCSRC,UCSZ0);
    setBit(UCSRC,URSEL);


    setBit(UCSRB,RXCIE);
    setBit(UCSRB,TXCIE);

    sei();

}

void UART_send(unsigned char x){
	while(((1<<UDRE)&(UCSRA))==0);
	UDR=x;
}

void UART_sendString(unsigned char* x){
	for(int i=0;i<strlen(x);i++){
	while(((1<<UDRE)&(UCSRA))==0);
	UDR=x[i];
	}
}

ISR(USART_RXC_vect){
	rec=UDR;
	UART_sendString(" You sent:");
	UART_send(rec);
	SPI_SEND(rec);
}
ISR(USART_TXC_vect){
}
