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

	//Multiplication
	a.mem_stack[0] = CLA; //clear the AC
	a.mem_stack[1] = LDA; //Load AC with data from mem_stack[100]
	a.mem_stack[2] = 0;
	a.mem_stack[3] = 100;
	a.mem_stack[4] = MUL; //Multiply AC with data from mem_stack[100]
	a.mem_stack[5] = 0;
	a.mem_stack[6] = 100;
	a.mem_stack[7] = STA; //store it into another memory
	a.mem_stack[8] = 0;
	a.mem_stack[9] = 108; //108 is output

	//incrementing
	a.mem_stack[10] = CLA; //clear the AC
	a.mem_stack[11] = LDA; //Load the AC with data from mem_stack[100]
	a.mem_stack[12] = 0;
	a.mem_stack[13] = 100;
	a.mem_stack[14] = ADI; //add immediate value to AC
	a.mem_stack[15] = 0;
	a.mem_stack[16] = 1;
	a.mem_stack[17] = STA; //Store the value of AC to memory
	a.mem_stack[18] = 0;
	a.mem_stack[19] = 100;


	//branching/loop condition check
	a.mem_stack[20] = SLT; //if(mem_stack[100] < mem_stack[102]) -> set the flag @ (104) high
	a.mem_stack[21] = 0;
	a.mem_stack[22] = 104;
	a.mem_stack[23] = 0;
	a.mem_stack[24] = 100;
	a.mem_stack[25] = 0;
	a.mem_stack[26] = 102;
	//while mem_stack[104] != mem_stack[106]
	a.mem_stack[27] = BNE;
	a.mem_stack[28] = 0;
	a.mem_stack[29] = 104;
	a.mem_stack[30] = 0;
	a.mem_stack[31] = 106;
	a.mem_stack[32] = 0;
	a.mem_stack[33] = 0;
//	//else go to the end
	a.mem_stack[34] = EOP;

	//static data [100:]
	a.mem_stack[100] = 0;//used to multiply
	a.mem_stack[101] = 0;
	a.mem_stack[102] = 0;
	a.mem_stack[103] = 14;
	a.mem_stack[104] = 0;
	a.mem_stack[105] = 0;
	a.mem_stack[106] = 0;
	a.mem_stack[107] = 0;
	//output data
	a.mem_stack[108] = 0;
	a.mem_stack[109] = 0;


	a.emulate(0);
	printf("%02X ",a.mem_stack[108]);
	printf("%02X\n",a.mem_stack[109]);
	return 0;
}
