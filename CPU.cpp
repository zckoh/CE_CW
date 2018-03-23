/*
 * CPU.cpp
 *
 *  Created on: Mar 9, 2018
 *      Author: zckoh
 */

#include "CPU.h"
#define DEBUG

CPU::CPU() {
	PC = 0;
	AC = 0;
	IR = 0;
	temp_op = 0;
	REGS[7] = {0};
	mem_stack[65536] = {0};
	running = false;
	cmp_flag = false;

}

//Returns the fetched value from address given by PC
//first byte is for MSB of 16 bits
uint16_t CPU::fetch(uint16_t address)
{
	return mem_stack[address];
}

//Puts the 16 bits value into 2 bytes in memory
//Start from LSB of 16 bits
void CPU::put(uint16_t address,int value)
{
	mem_stack[address] = value;
}


//fetch the instruction (16+16+16+16 bits)
uint64_t CPU::fetch_instruction(uint16_t address)
{
	uint64_t opcode = mem_stack[address];
	uint64_t operand1 = mem_stack[address+1];
	uint64_t operand2 = mem_stack[address+2];
	uint64_t operand3 = mem_stack[address+3];
	return (uint64_t)(opcode<<48 | operand1<<32 | operand2<<16 | operand3);
}

//fetch instruction from text segment
void CPU::fetch_step()
{
	//store the fetched instruction in IR
	IR = fetch_instruction(PC);
	//increments the PC
	PC+=4;
}

//fetch the operand of value from IR
uint16_t CPU::fetch_operand(int value)
{
	if(value==1) //operand 1
	{
		return (uint16_t)(IR>>32) & 0xffff;
	}
	else if(value==2) //operand 2
	{
		return (uint16_t)(IR>>16) & 0xffff;
	}
	else if (value==3) //operand3
	{
		return (uint16_t)(IR) & 0xffff;
	}
	else
	{
		return 0;
	}
}

//fetch opcode from IR
uint16_t CPU::fetch_opcode()
{
	return (uint16_t)(IR>>48);
}

//store the opcode in temp_op
void CPU::decode_step()
{
	temp_op = fetch_opcode();
}


//execute instruction based from temp_op
void CPU::execute()
{
	switch(temp_op)
	{
		case undefined:
		{
#ifdef DEBUG
			printf("No command detected\n");
#endif
		}break;
		case CLA:
		{
			AC = 0;
#ifdef DEBUG
			printf("Cleared accumulator, AC = %d\n",AC);
#endif
		}break;
		case LDA:
		{
			AC = fetch(fetch_operand(1));
#ifdef DEBUG
			printf("Fetched Data to AC, AC = %d\n",AC);
#endif
		}break;
		case STA:
		{
			put(fetch_operand(1),AC);
#ifdef DEBUG
			if(fetch_operand(1) == 208)
			{
				if(AC)
				{
					printf("%d is a prime number\n",fetch(224));
				}
				else
				{
					printf("is not a prime number\n");
				}
			}
			printf("Stored value of AC (%d) to memory\n",AC);
#endif
		}break;
		case ADD:
		{
			AC = AC + fetch(fetch_operand(1));
			//increment to next instruction
#ifdef DEBUG
			printf("Add to AC, AC = %d\n",AC);
#endif
		}break;
		case ADI:
		{
			AC = AC + fetch_operand(1);
#ifdef DEBUG
			printf("Add immediate value to AC, AC = %d\n",AC);
#endif
		}break;
		case SUB:
		{
			AC = AC - fetch(fetch_operand(1));
#ifdef DEBUG
			printf("Subtract from AC, AC = %d\n",AC);
#endif
		}break;
		case SBI:
		{
			AC = AC - fetch_operand(1);
#ifdef DEBUG
			printf("Subtract immediate value from AC, AC = %d\n",AC);
#endif
		}break;
		case MUL:
		{
			AC = AC*fetch(fetch_operand(1));
#ifdef DEBUG
			printf("Multiply wtih AC, AC = %d\n",AC);
#endif
		}break;
		case DIV:
		{
#ifdef DEBUG
			printf("%d (before division)\n ",AC);
#endif
			AC = AC / fetch(fetch_operand(1));
#ifdef DEBUG
			printf("%d (after division\n",AC);
#endif
		}break;
		case REM:
		{
			AC = AC % fetch(fetch_operand(1));
#ifdef DEBUG
			printf("REM in AC = %d\n",AC);
#endif
		}break;
		case SLT:
		{
			if(fetch(fetch_operand(2)) < fetch(fetch_operand(3)))
			{
				put(fetch_operand(1),1);
#ifdef DEBUG
				printf("satisfied the SLT condition,setting operand 1 to 1\n");
#endif
			}
			else
			{
				put(fetch_operand(1),0);
#ifdef DEBUG
				printf("did not satisfied the SLT condition, setting operand 1 to 0\n");
#endif
			}
		}break;
		case LET:
		{
			if(fetch(fetch_operand(2)) <= fetch(fetch_operand(3)))
			{
				put(fetch_operand(1),1);
#ifdef DEBUG
				printf("satisfied the LET condition, setting operand 1 to 1\n");
#endif
			}
			else
			{
				put(fetch_operand(1),0);
#ifdef DEBUG
				printf("did not satisfy the LET condition, setting operand 1 to 0\n");
#endif
			}
		}break;
		case SLI:
		{
			if(fetch_operand(2)<fetch_operand(3))
			{
				put(fetch_operand(1),1);
#ifdef DEBUG
				printf("satisfied the SLI condition, setting operand 1 to 1\n");
#endif
			}
			else
			{
				put(fetch_operand(1),0);
#ifdef DEBUG
				printf("did not satisfy the SLI condition, setting operand 1 to 0\n");
#endif
			}
		}break;
		case JMP:
		{
			PC = fetch_operand(1);
#ifdef DEBUG
			printf("Jump to Addr : %d\n",PC);
#endif
		}break;
		case BNE:
		{
			REGS[0] = fetch(fetch_operand(1));
			REGS[1] = fetch(fetch_operand(2));
			if(REGS[0]!=REGS[1])
			{
				PC = fetch_operand(3); //because outside always increment by 1
#ifdef DEBUG
				printf("operand 1 != operand 2, set PC to operand 3\n");
#endif
			}
			else
			{
#ifdef DEBUG
				printf("operand 1 == operand 2, set PC to operand 3\n");
#endif
			}
		}break;
		case BEQ:
		{
			REGS[0] = fetch(fetch_operand(1));
			REGS[1] = fetch(fetch_operand(2));
			if(REGS[0]==REGS[1])
			{
				PC = fetch_operand(3);
#ifdef DEBUG
				printf("operand 1 == operand 2, set PC to operand 3\n");
#endif
			}
			else
			{
#ifdef DEBUG
				printf("operand 1 != operand 2, set PC to operand 3\n");
#endif
			}
		}break;
		case EOP:
		{
			running = false;
#ifdef DEBUG
			printf("End of program reached\n");
#endif
		}break;
	}
}


void CPU::emulate(uint16_t start_addr)
{
	PC = start_addr;
	running = true;

	while(running)
	{
		//fetch steps
		fetch_step();
		//decode
		decode_step();
		//execute
		execute();

	}
	//Write back


}

