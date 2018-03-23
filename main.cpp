/*
 * main.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: zckoh
 */




#include <stdio.h>
#include <math.h>
#include "CPU.h"
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>

//Single memory space (64kB Memory unit)
uint16_t mem_stack[65536] = {0};


int main(void)
{
	CPU A;
	//Define what is inside the memory (flashing in the program)
	//program code

	//multiplication
	mem_stack[0] = CLA;  //clear the AC
	mem_stack[1] = 0;
	mem_stack[2] = 0;
	mem_stack[3] = 0;
	mem_stack[4] = LDA;  //Load AC with data from mem_stack[1000]
	mem_stack[5] = 1000;
	mem_stack[6] = 0;
	mem_stack[7] = 0;
	mem_stack[8] = MUL;  //Multiply AC with data from mem_stack[1000]
	mem_stack[9] = 1000;
	mem_stack[10] = 0;
	mem_stack[11] = 0;
	mem_stack[12] = STA;
	mem_stack[13] = 1008;
	mem_stack[14] = 0;
	mem_stack[15] = 0;

	//incrementing
	mem_stack[16] = CLA;  //clear the AC
	mem_stack[17] = 0;
	mem_stack[18] = 0;
	mem_stack[19] = 0;
	mem_stack[20] = LDA; //Load the AC with data from mem_stack[1000]
	mem_stack[21] = 1000;
	mem_stack[22] = 0;
	mem_stack[23] = 0;
	mem_stack[24] = ADI; //add immediate value to AC
	mem_stack[25] = 1;
	mem_stack[26] = 0;
	mem_stack[27] = 0;
	mem_stack[28] = STA;  //Store the value of AC to memory
	mem_stack[29] = 1000;
	mem_stack[30] = 0;
	mem_stack[31] = 0;

	//branching/loop condition check
	mem_stack[32] = SLT;
	mem_stack[33] = 1002;
	mem_stack[34] = 1000;
	mem_stack[35] = 1001;
	mem_stack[36] = BNE;
	mem_stack[37] = 1002;
	mem_stack[38] = 1003;
	mem_stack[39] = 0;
	//else go to the end
	mem_stack[40] = EOP;
	mem_stack[41] = 0;
	mem_stack[42] = 0;
	mem_stack[43] = 0;


	//static data[1000:]
	mem_stack[1000] = 0;
	mem_stack[1001] = 100;
	mem_stack[1002] = 0;
	mem_stack[1003] = 0;
	//output data
	mem_stack[1008] = 0;

	A.emulate(0);
//	printf("test uint64_t : %" PRIx64 "\n", a.fetch_instruction(0));
//	printf("operand %d = %d\n",2,a.fetch_operand(4));
	//	printf("%" PRIu64 "\n", );


	printf("%02X ",mem_stack[1008]);
	return 0;
}
