/*
 * macros.h
 *
 *  Created on: Nov 14, 2020
 *      Author: Abdelrahman
 */

#ifndef MACROS_H_
#define MACROS_H_

#define setBit(port,pin) (port |=(1<<pin))
#define clearBit(port,pin) (port &= ~(1<<pin))
#define toggleBit(port,pin) (port ^= (1<<pin))
#define readBit(port,pin) (port&(1<<pin))

#endif /* MACROS_H_ */
