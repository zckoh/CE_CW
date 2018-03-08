/*
 * program_counter.h
 *
 *  Created on: Mar 7, 2018
 *      Author: zckoh
 */

#ifndef REGISTERS_PROGRAM_COUNTER_H_
#define REGISTERS_PROGRAM_COUNTER_H_

#include <stdio.h>
#include <math.h>

class PC{
public:
	// Constructor with default values for data members
	PC();
	int address;
	int counter = 0;
	void increment_counter();
	void reset();
	void point_next_address();
};


#endif /* REGISTERS_PROGRAM_COUNTER_H_ */
