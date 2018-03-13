/*
 * main.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: zckoh
 */

#include <stdio.h>
#include <math.h>
#include "CPU.h"


//since the operand reference is 6 bits (max = 63)
//then limit the stack to 63 arrays


//Initialize the single memory space (64kB RAM)
//[0-9] for fixed instructions



//Initialize the register stack (16 bit register)
//100 16 bits registers
//[0-9] for PC
//[10-30] for IR
//[39-64] for AC
//uint8_t reg_stack[64] = {0};
//uint8_t *PC_ptr;
//uint8_t *IR_ptr;
//uint8_t *AC_ptr;








int main(void)
{

	CPU a;

	//Define what is inside the memory (flashing in the program)
	//program code
	a.mem_stack[0] = ADD; //Add 30 to ACC
	a.mem_stack[1] = 0;
	a.mem_stack[2] = 30;
	a.mem_stack[3] = SLT; //set flag(mem_stack[500] if mem_stack[30] < mem_stack[32]
	a.mem_stack[4] = 0;
	a.mem_stack[5] = 200;
	a.mem_stack[6] = 0;
	a.mem_stack[7] = 30;
	a.mem_stack[8] = 0;
	a.mem_stack[9] = 32;
	a.mem_stack[10] = BNE; //compare mem_stack[30] != mem_stack[32]
	a.mem_stack[11] = 0;   //if match then branch to mem_stack[16]
	a.mem_stack[12] = 200;
	a.mem_stack[13] = 0;
	a.mem_stack[14] = 201;
	a.mem_stack[15] = 0;
	a.mem_stack[16] = 23;
	//if branch not match come here
	a.mem_stack[17] = STA; //store ACC value to mem_stack[35]
	a.mem_stack[18] = 0;
	a.mem_stack[19] = 34;
	a.mem_stack[20] = JMP; //Jump to EOP
	a.mem_stack[21] = 0;
	a.mem_stack[22] = 29;
	//if branch match then jump here
	a.mem_stack[23] = ADD;
	a.mem_stack[24] = 0;
	a.mem_stack[25] = 30;
	a.mem_stack[26] = STA;
	a.mem_stack[27] = 0;
	a.mem_stack[28] = 34;
	a.mem_stack[29] = EOP;


	//static data
	a.mem_stack[30] = 0;
	a.mem_stack[31] = 41;
	a.mem_stack[32] = 0;
	a.mem_stack[33] = 40;


	//dynamic data



	a.emulate(0);
	printf("%02X ",a.mem_stack[35]);
	printf("%02X\n",a.mem_stack[34]);
	return 0;
}
