/*
 * main.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: zckoh
 */

#include <iostream>
#include <math.h>
using namespace std;

//since the operand reference is 6 bits (max = 63)
//then limit the stack to 63 arrays


//Initialize the single memory space
//[0-9] for fixed instructions
uint8_t mem_stack[64] = {0};



//Initialize the register stack
//100 16 bits registers
//[0-9] for PC
//[10-30] for IR
//[39-64] for AC
uint8_t reg_stack[64] = {0};
uint8_t *PC_ptr;
uint8_t *IR_ptr;
uint8_t *AC_ptr;


//Returns the fetched instruction from address given by PC
void fetch(uint16_t address)
{

}


int main(void)
{
	//initialize all the pointers for the register stack
	reg_stack[9] = 20;
	PC_ptr = reg_stack;
	IR_ptr = reg_stack+10;
	AC_ptr = reg_stack+39;


	cout<< *PC_ptr<<"\n";
	*PC_ptr = 10;
	cout<< *PC_ptr<<"\n";
	cout<<"Value of IR: "<<*IR_ptr<<"\n";
	cout<<"Address of IR: "<<IR_ptr<<"\n";
	PC_ptr++;
	cout<<"HELLO World\n";
	cout<< *(reg_stack+9);
	return 0;
}
