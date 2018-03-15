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
	//Define REGS[0] as zero
	REGS[0] = 0;
	//Define REGS[1] as one
	REGS[1] = 1;
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
		//fetch instruction & store in IR
		IR = mem_stack[PC];
		//check IR (decode)
		switch (IR)
		{
			case undefined:
			{
				printf("No command detected\n");
			}break;
			case CLA:
			{
				AC = 0;
//				printf("Cleared accumulator, AC = %d\n",AC);
			}break;
			//Execute its task
			case LDA:
			{
				AC = fetch(fetch(PC+1));
				//point PC to next instruction
//				printf("Fetched Data to AC, AC = %d\n",AC);
				PC += 2;
			}break;
			case STA:
			{
				put(fetch(PC+1),AC);
//				printf("Stored value of AC (%d) to memory address (%d)\n",AC,fetch(PC+1));
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
//				printf("Add immediate value to AC, AC = %d\n",AC);
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
			case MUL:
			{
				AC = AC*fetch(fetch(PC+1));
				printf("%d\n",AC);
				PC += 1;
			}break;
			case SLT:
			{
				if(fetch(fetch(PC+3)) < fetch(fetch(PC+5)))
				{
					put(fetch(PC+1),1);
//					printf("%d is less than %d, set memory address %d with 1\n",fetch(fetch(PC+3)),fetch(fetch(PC+5)),fetch(PC+1));
				}
				else
				{
					put(fetch(PC+1),0);
				}
				PC += 6;
			}break;
			case SLI:
			{
				if(fetch(PC+3)<fetch(PC+5))
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
//					printf("%d is not equal to %d, set PC to %d\n",REGS[0],REGS[1],PC);
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

