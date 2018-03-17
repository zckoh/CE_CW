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
	a.mem_stack[0] = CLA; //clear the AC
	a.mem_stack[1] = LDA; //Load the AC with data from mem_stack[200]
	a.mem_stack[2] = 0;
	a.mem_stack[3] = 200;
	a.mem_stack[4] = ADI; //add immediate value to AC
	a.mem_stack[5] = 0;
	a.mem_stack[6] = 1;
	a.mem_stack[7] = STA; //Store the value of AC to memory
	a.mem_stack[8] = 0;
	a.mem_stack[9] = 200;


	//set i = 1 (mem_stack[210])
	a.mem_stack[10] = CLA;
	a.mem_stack[11] = ADI;
	a.mem_stack[12] = 0;
	a.mem_stack[13] = 1;
	a.mem_stack[14] = STA;
	a.mem_stack[15] = 0;
	a.mem_stack[16] = 210;
	//set the remainder = 0

	//clear the AC
	a.mem_stack[17] = CLA;
	a.mem_stack[18] = LDA; //load the numerator (mem_stack[200]) into AC
	a.mem_stack[19] = 0;
	a.mem_stack[20] = 200;
	a.mem_stack[21] = REM; //get the remainder of the division by mem_stack[210]
	a.mem_stack[22] = 0;
	a.mem_stack[23] = 210;
	a.mem_stack[24] = STA; //store the remainder to mem_stack[212]
	a.mem_stack[25] = 0;
	a.mem_stack[26] = 212;

	//if remainder == 0
	a.mem_stack[27] = BEQ;
	a.mem_stack[28] = 0;
	a.mem_stack[29] = 212;
	a.mem_stack[30] = 0;
	a.mem_stack[31] = 216; //This is zero
	a.mem_stack[32] = 0;
	a.mem_stack[33] = 37; //branch to 40 to increment the prime counter
	//else //dont increment, move on to
	a.mem_stack[34] = JMP;
	a.mem_stack[35] = 0;
	a.mem_stack[36] = 47;


	//incrementing the prime counter (mem_stack[220])
	a.mem_stack[37] = CLA;
	a.mem_stack[38] = LDA;
	a.mem_stack[39] = 0;
	a.mem_stack[40] = 220;
	a.mem_stack[41] = ADI;
	a.mem_stack[42] = 0;
	a.mem_stack[43] = 1;
	a.mem_stack[44] = STA;
	a.mem_stack[45] = 0;
	a.mem_stack[46] = 220;

	//increment a counter

	a.mem_stack[47] = CLA; //increment i by 1
	a.mem_stack[48] = LDA;
	a.mem_stack[49] = 0;
	a.mem_stack[50] = 210;
	a.mem_stack[51] = ADI;
	a.mem_stack[52] = 0;
	a.mem_stack[53] = 1;
	a.mem_stack[54] = STA;
	a.mem_stack[55] = 0;
	a.mem_stack[56] = 210;

	//loop condition check
	a.mem_stack[57] = LET; //if(i<=n)
	a.mem_stack[58] = 0;
	a.mem_stack[59] = 218;  //flag at mem_stack[218]
	a.mem_stack[60] = 0;
	a.mem_stack[61] = 210;
	a.mem_stack[62] = 0;
	a.mem_stack[63] = 200;
	a.mem_stack[64] = BNE;
	a.mem_stack[65] = 0;
	a.mem_stack[66] = 218;
	a.mem_stack[67] = 0;
	a.mem_stack[68] = 216; //mem_stack[216] is constantly zero
	a.mem_stack[69] = 0;
	a.mem_stack[70] = 17; //go back to compare with other numbers

	//now check the counter if is equal to 2
	a.mem_stack[71] = BNE;
	a.mem_stack[72] = 0;
	a.mem_stack[73] = 220;
	a.mem_stack[74] = 0;
	a.mem_stack[75] = 222;
	a.mem_stack[76] = 0;
	a.mem_stack[77] = 92;

	a.mem_stack[78] = CLA;
	a.mem_stack[79] = LDA;   //Store the current prime number in another memory to be printed out
	a.mem_stack[80] = 0;
	a.mem_stack[81] = 200;
	a.mem_stack[82] = STA;
	a.mem_stack[83] = 0;
	a.mem_stack[84] = 224;

	a.mem_stack[85] = CLA; //if equal to 2, output high at mem_stack[208]
	a.mem_stack[86] = ADI;
	a.mem_stack[87] = 0;
	a.mem_stack[88] = 1;
	a.mem_stack[89] = STA;
	a.mem_stack[90] = 0;
	a.mem_stack[91] = 208;

	//clear the prime counter after determining if is prime number or not
	a.mem_stack[92] = CLA;
	a.mem_stack[93] = STA;
	a.mem_stack[94] = 0;
	a.mem_stack[95] = 220;
	//branching/loop condition check
	a.mem_stack[96] = SLT; //if(mem_stack[200] < mem_stack[202]) -> set the flag @ (204) high
	a.mem_stack[97] = 0;
	a.mem_stack[98] = 204;
	a.mem_stack[99] = 0;
	a.mem_stack[100] = 200;
	a.mem_stack[101] = 0;
	a.mem_stack[102] = 202;
	//while mem_stack[204] != mem_stack[206]
	a.mem_stack[103] = BNE;
	a.mem_stack[104] = 0;
	a.mem_stack[105] = 204;
	a.mem_stack[106] = 0;
	a.mem_stack[107] = 206;
	a.mem_stack[108] = 0;
	a.mem_stack[109] = 0;
	//else go to the end
	a.mem_stack[110] = EOP;

	//static data [200:]
	a.mem_stack[200] = 0;//used to multiply
	a.mem_stack[201] = 1;
	a.mem_stack[202] = 3;
	a.mem_stack[203] = 232;
	a.mem_stack[204] = 0;
	a.mem_stack[205] = 0;
	a.mem_stack[206] = 0;
	a.mem_stack[207] = 0;
	//output data
	a.mem_stack[208] = 0;
	a.mem_stack[209] = 0;


	a.mem_stack[210] = 0; //i for incrementing the inner for loop
	a.mem_stack[211] = 1;
	a.mem_stack[212] = 0; //remainder
	a.mem_stack[213] = 0;
	a.mem_stack[214] = 0; //constantly 1 (to compare with when using beq in finding prime number
	a.mem_stack[215] = 1;
	a.mem_stack[216] = 0; //constantly 0 (to compare with BEQ when finding prime number
	a.mem_stack[217] = 0;
	a.mem_stack[218] = 0; //flag for loop condition (inner)
	a.mem_stack[219] = 0;
	a.mem_stack[220] = 0; //counter for no of remainders which is 0
	a.mem_stack[221] = 0;
	a.mem_stack[222] = 0; //only 2 maximum
	a.mem_stack[223] = 2;
	a.mem_stack[224] = 0; // to store the current prime number (to be printed out)
	a.mem_stack[225] = 0;

	a.emulate(0);
	printf("%02X ",a.mem_stack[208]);
	printf("%02X\n",a.mem_stack[209]);
	return 0;
}
