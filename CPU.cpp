/*
 * CPU.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: zckoh
 */

#include "CPU.h"

CPU::CPU() {
	PC = 0;
	AC = 0;
	IR = 0;
	REGS[7] = {0};
	mem_stack[65536] = {0};
	running = false;
}

//Returns the fetched instruction from address given by PC
//first byte is for MSB of 16 bits
uint16_t CPU::fetch(uint16_t address)
{
	return mem_stack[address]*256 + mem_stack[address+1];
}

//Puts the 16 bits value into 2 bytes in memory
//Start from MSB of 16 bits
void CPU::put(uint16_t address,int value)
{
	mem_stack[address] = (uint8_t)((value & 0xFF00) >> 8);
	mem_stack[address+1] = (uint8_t)(value & 0x00FF);
}

void CPU::emulate(uint16_t start_addr)
{
	PC = start_addr;
//	int temp;
//	long int ltemp;

	running = true;

	while(running)
	{
		//fetch the first instruction
		IR = mem_stack[PC];
		//decode
		switch (IR)
		{
			case add:
			{
				AC = mem_stack[PC+1] + mem_stack[PC+2];
				//increment to next instruction
				PC = PC +3;
			}break;
			case write:
			{
				put(PC,AC);
				PC = PC + 3;
			}break;
			case EOP:
			{
				running = false;
			}break;

		}
	}
	//fetch & store in IR
	//point PC to next instruction
	//check IR (decode)
	//Execute its task
	//Write back


}

