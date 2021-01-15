/*
 * UART_Driver.h
 *
 *  Created on: Dec 5, 2020
 *      Author: Abdelrahman
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

void UART_init();
void UART_send(unsigned char x);
void UART_sendString(unsigned char* x);
unsigned char rec;

#endif /* UART_DRIVER_H_ */
