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
	//initialize all the pointers for the register stack
//	reg_stack[9] = 20;
//	PC_ptr = reg_stack;
//	IR_ptr = reg_stack+10;
//	AC_ptr = reg_stack+39;
//
//
//	cout<< *PC_ptr<<"\n";
//	*PC_ptr = 10;
//	cout<< *PC_ptr<<"\n";
//	cout<<"Value of IR: "<<*IR_ptr<<"\n";
//	cout<<"Address of IR: "<<IR_ptr<<"\n";
//	PC_ptr++;
//	cout<<"HELLO World\n";
//	cout<< *(reg_stack+9);


	CPU a;
	a.mem_stack[0] = add;
	a.mem_stack[1] = 3;
	a.mem_stack[2] = 4;
	a.mem_stack[3] = add;
	a.mem_stack[4] = 3;
	a.mem_stack[5] = 10;
	a.mem_stack[6] = write;
	a.mem_stack[9] = EOP;

	a.emulate(0);
//	printf("%02X\n",a.mem_stack[0]);
//	printf("%02X\n",a.mem_stack[3]);
//	printf("%02X\n",a.mem_stack[4]);
//	printf("%02X\n",a.mem_stack[2]);
//	printf("%02X\n",a.fetch(1));

	printf("%02X\n",a.mem_stack[7]);
	printf("%02X\n",a.mem_stack[8]);

//	a.put(1,1404);
//	printf("%02X\n",1404);
//	printf("%02X\n",a.mem_stack[1]);
//	printf("%02X\n",a.mem_stack[2]);
//	printf("%02X\n",a.fetch(1));
	return 0;
}
