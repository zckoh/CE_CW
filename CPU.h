/*
 * CPU.h
 *
 *  Created on: Mar 9, 2018
 *      Author: zckoh
 */

#ifndef CPU_H_
#define CPU_H_

#include <stdbool.h>
#include <stdint.h>
#include <iostream>


//define the opcodes
enum opcodes
{
	read,		//Read data from next byte and store temporarily to AC
	write,		//Write data from AC to next 2 bytes in memory
	add,		//Add [PC+1] with [PC+2]
	subtract,	//Subtract [PC+2] from [PC+1]
	CMP, 		//compare accumulator with mem

	EOP		 	//End of Program
};

class CPU{
public:
	// Constructor with default values for data members
	CPU();
	bool running;
	//Registers
	int PC; //Program Counter
	int AC;	//Accumulator
	int IR; //Instruction Register
	//Additional registers for when need more than 2 bytes in original registers
	int REGS[7];
	uint8_t mem_stack[65536];

	uint16_t fetch(uint16_t address);
	void put(uint16_t address,int value);
	void increment_counter();
	void reset();
	void point_next_address();

	void emulate(uint16_t start_addr);
};


#endif /* CPU_H_ */
