/*
 * main.cpp
 *
 *  Created on: Mar 2, 2018
 *      Author: zckoh
 */

#include <stdio.h>
#include <math.h>
#include "CPU.h"

//Single memory space (64kB RAM)

int main(void)
{

	CPU a;

	//Define what is inside the memory (flashing in the program)
	//program code

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


	//set i = 1 (mem_stack[110])
	//set the remainder = 0

	//clear the AC
	a.mem_stack[20] = CLA;
	a.mem_stack[21] = LDA; //load the numerator (mem_stack[100]) into AC
	a.mem_stack[22] = 0;
	a.mem_stack[23] = 100;
	a.mem_stack[24] = REM; //get the remainder of the division by mem_stack[110]
	a.mem_stack[25] = 0;
	a.mem_stack[26] = 110;
	a.mem_stack[27] = STA; //store the remainder to mem_stack[112]
	a.mem_stack[28] = 0;
	a.mem_stack[29] = 112;

	//if remainder == 0
	a.mem_stack[30] = BEQ;
	a.mem_stack[31] = 0;
	a.mem_stack[32] = 112;
	a.mem_stack[33] = 0;
	a.mem_stack[34] = 116; //This is zero
	a.mem_stack[35] = 0;
	a.mem_stack[36] = 40; //branch to 40 to increment the prime counter
	//else //dont increment, move on to
	a.mem_stack[37] = JMP;
	a.mem_stack[38] = 0;
	a.mem_stack[39] = 50;


	//incrementing the prime counter (mem_stack[120])
	a.mem_stack[40] = CLA;
	a.mem_stack[41] = LDA;
	a.mem_stack[42] = 0;
	a.mem_stack[43] = 120;
	a.mem_stack[44] = ADI;
	a.mem_stack[45] = 0;
	a.mem_stack[46] = 1;
	a.mem_stack[47] = STA;
	a.mem_stack[48] = 0;
	a.mem_stack[49] = 120;

	//increment a counter

	a.mem_stack[50] = CLA; //increment i by 1
	a.mem_stack[51] = LDA;
	a.mem_stack[52] = 0;
	a.mem_stack[53] = 110;
	a.mem_stack[54] = ADI;
	a.mem_stack[55] = 0;
	a.mem_stack[56] = 1;
	a.mem_stack[57] = STA;
	a.mem_stack[58] = 0;
	a.mem_stack[59] = 110;

	//loop condition check
	a.mem_stack[60] = LET; //if(i<n)
	a.mem_stack[61] = 0;
	a.mem_stack[62] = 118;  //flag at mem_stack[118]
	a.mem_stack[63] = 0;
	a.mem_stack[64] = 110;
	a.mem_stack[65] = 0;
	a.mem_stack[66] = 100;
	a.mem_stack[67] = BNE;
	a.mem_stack[68] = 0;
	a.mem_stack[69] = 118;
	a.mem_stack[70] = 0;
	a.mem_stack[71] = 116; //mem_stack[116] is constantly zero
	a.mem_stack[72] = 0;
	a.mem_stack[73] = 20; //go back to compare with other numbers

	//now check the counter if is equal to 2
	a.mem_stack[74] = BNE;
	a.mem_stack[75] = 0;
	a.mem_stack[76] = 120;
	a.mem_stack[77] = 0;
	a.mem_stack[78] = 122;
	a.mem_stack[79] = 0;
	a.mem_stack[80] = 88;
	a.mem_stack[81] = CLA;
	a.mem_stack[82] = ADI;
	a.mem_stack[83] = 0;
	a.mem_stack[84] = 1;
	a.mem_stack[85] = STA;
	a.mem_stack[86] = 0;
	a.mem_stack[87] = 108;
	a.mem_stack[88] = EOP;


	//branching/loop condition check
//	a.mem_stack[20] = SLT; //if(mem_stack[100] < mem_stack[102]) -> set the flag @ (104) high
//	a.mem_stack[21] = 0;
//	a.mem_stack[22] = 104;
//	a.mem_stack[23] = 0;
//	a.mem_stack[24] = 100;
//	a.mem_stack[25] = 0;
//	a.mem_stack[26] = 102;
//	//while mem_stack[104] != mem_stack[106]
//	a.mem_stack[27] = BNE;
//	a.mem_stack[28] = 0;
//	a.mem_stack[29] = 104;
//	a.mem_stack[30] = 0;
//	a.mem_stack[31] = 106;
//	a.mem_stack[32] = 0;
//	a.mem_stack[33] = 0;
//	//else go to the end
//	a.mem_stack[34] = EOP;

	//static data [100:]
	a.mem_stack[100] = 0;//used to multiply
	a.mem_stack[101] = 1;
	a.mem_stack[102] = 0;
	a.mem_stack[103] = 7;
	a.mem_stack[104] = 0;
	a.mem_stack[105] = 0;
	a.mem_stack[106] = 0;
	a.mem_stack[107] = 0;
	//output data
	a.mem_stack[108] = 0;
	a.mem_stack[109] = 0;


	a.mem_stack[110] = 0; //i for incrementing the inner for loop
	a.mem_stack[111] = 1;
	a.mem_stack[112] = 0; //remainder
	a.mem_stack[113] = 0;
	a.mem_stack[114] = 0; //constantly 1 (to compare with when using beq in finding prime number
	a.mem_stack[115] = 1;
	a.mem_stack[116] = 0; //constantly 0 (to compare with BEQ when finding prime number
	a.mem_stack[117] = 0;
	a.mem_stack[118] = 0; //flag for loop condition (inner)
	a.mem_stack[119] = 0;
	a.mem_stack[120] = 0;
	a.mem_stack[121] = 0; //counter for no of remainders which is 0
	a.mem_stack[122] = 0;
	a.mem_stack[123] = 2; //only 2 maximum

	a.emulate(0);
	printf("%02X ",a.mem_stack[108]);
	printf("%02X\n",a.mem_stack[109]);
	return 0;
}
