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
	cmp_flag = false;
	temp = 0;

}

//Returns the fetched value from address given by PC
//first byte is for MSB of 16 bits
uint16_t CPU::fetch(uint16_t address)
{
	return mem_stack[address]*256 + mem_stack[address+1];
}

//Puts the 16 bits value into 2 bytes in memory
//Start from LSB of 16 bits
void CPU::put(uint16_t address,int value)
{
	mem_stack[address+1] = (uint8_t)((value & 0xFF00) >> 8);
	mem_stack[address] = (uint8_t)(value & 0x00FF);
}

void CPU::emulate(uint16_t start_addr)
{
	PC = start_addr;
//	int temp;
//	long int ltemp;

	running = true;

	while(running)
	{
		//fetch instruction & store in IR
		IR = mem_stack[PC];
		//check IR (decode)
		switch (IR)
		{
			case undefined:
			{
				printf("No command detected\n");
			}break;
			//Execute its task
			case LDA:
			{
				AC = fetch(fetch(PC+1));
				//point PC to next instruction
				PC += 2;
			}break;
			case STA:
			{
				put(fetch(PC+1),AC);
				PC += 2;
			}break;
			case ADD:
			{
				AC = AC + fetch(fetch(PC+1));
				//increment to next instruction
				PC += 2;
			}break;
			case ADI:
			{
				AC = AC + fetch(PC+1);
				PC += 2;
			}break;
			case SUB:
			{
				AC = AC - fetch(fetch(PC+1));
				PC += 2;
			}break;
			case SBI:
			{
				AC = AC - fetch(PC+1);
				PC += 2;
			}break;
			case SLT:
			{
				if(fetch(fetch(PC+3)) < fetch(fetch(PC+5)))
				{
					put(fetch(PC+1),1);
				}
				PC += 6;
			}break;
			case SLI:
			{
				if(fetch(PC+2)<fetch(PC+3))
				{
					put(fetch(PC+1),1);
				}
				else
				{
					put(fetch(PC+1),0);
				}
				PC += 6;
			}break;
			case JMP:
			{
				PC = fetch(PC+1)-1;
			}break;
			case BNE:
			{
				REGS[0] = fetch(fetch(PC+1));
				REGS[1] = fetch(fetch(PC+3));
				if(REGS[0]!=REGS[1])
				{
					PC = fetch(PC+5)-1; //because outside always increment by 1
					printf("PC = %d\n",PC);
				}
				else
				{
					PC += 6;
				}
			}break;
			case EOP:
			{
				running = false;
			}break;

		}
		PC ++;
	}
	//Write back


}

