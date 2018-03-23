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

extern uint16_t mem_stack[65536];

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
	DIV,		//Divide value of next address by AC and store in AC
	REM,		//obtain the remainder of the division of next address by AC and store in AC

	//others
	SLT,		//set temporary registers to high if less than
	SLI,		//set temporary registers to high if IMM1 less than IMM2
	LET,		//Less or equal than
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
	bool running; //check for the program is still running
	bool cmp_flag;

	//Registers
	int PC; //Program Counter
	int AC;	//Accumulator
	uint64_t IR; //Instruction Register
	uint16_t temp_op; //temporary variable to store the current opcode to be executed

	//Additional registers in CPU
	int REGS[7];

	//memory access functions
	uint16_t fetch(uint16_t address);
	void put(uint16_t address,int value);

	//functions for fetch step
	uint64_t fetch_instruction(uint16_t address);
	void fetch_step();

	//functions for decode step
	uint16_t fetch_operand(int value);
	uint16_t fetch_opcode();
	void decode_step();

	//functions for execute step
	void execute();

	//emulate the computer starting from start_addr
	void emulate(uint16_t start_addr);
};


#endif /* CPU_H_ */
