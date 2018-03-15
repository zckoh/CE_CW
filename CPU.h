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
	undefined,	//When no opcode is detected, move on to next byte
	//Data movement
	LDA,		//load accumulator from direct memory
	STA,		//Store accumulator to memory

	//Arithmetic operations
	ADD,		//Add memory to accumulator (16 bits operation)
	ADI,		//Add immediate to accumulator
	SUB,		//Subtract memory from accumulator (16 bits operation)
	SBI,		//subtract immediate from accumulator
	MUL,		//Multiply first operand with ACC

	//others
//	CMP, 		//compare accumulator with mem
	SLT,		//set temporary registers to high if less than
	SLI,		//set temporary registers to high if IMM1 less than IMM2
	JMP,		//Jump to location in memory
	BNE,		//Branch if not equal (A != B)
	BEQ,		//Branch if equal (A == B)
	CLA,		//clear accumulator
	EOP,		 	//End of Program
};

class CPU{
public:
	// Constructor with default values for data members
	CPU();

	//flags
	bool running;
	bool cmp_flag;

	//Registers
	int PC; //Program Counter
	int AC;	//Accumulator
	int IR; //Instruction Register

	//Additional registers for when need more than 2 bytes in original registers
	int REGS[7];
	int temp;

	uint8_t mem_stack[65536];

	uint16_t fetch(uint16_t address);
	void put(uint16_t address,int value);
	void increment_counter();
	void reset();
	void point_next_address();

	void emulate(uint16_t start_addr);
};


#endif /* CPU_H_ */
