# CE_CW
Simple computer emulator with a limited instruction set. 16-bit address memory subsystem with 64-bit instruction format.  
Computer Architecture:  
- 16-bit memory subsystem with 16-bit (65535) address
- 64-bit instruction format
- 17 different instructions
- fetch/decode/execute cycle

Instruction set:
⋅⋅* Arithmetic
1. ADD	Add value from memory to AC
2. ADI	Add immediate value to AC
3. SUB	Subtract value from memory from AC
4. SBI	Subtract immediate value from AC
5. MUL	Multiply value from memory with AC
6. DIV	Divide AC by value from memory
7. REM	Remainder of division of AC by value from memory

⋅⋅* Data movement
1. LDA	Load accumulator from memory
2. STA	Store accumulator value to memory

⋅⋅* Program flow control
1. JMP	Jump to target address
2. BNE	Branch to target address if operand 1 != operand 2
3. BEQ	Branch to target address if operand 1 == operand 2

⋅⋅* Others
1. SLT	Set target address to 1 if operand 2 < operand 3
2. SLI	Set target address to 1 if operand 2 (immediate value) < operand 3 (immediate value)
3. LET	Set target address to 1 if operand 2 ≤ operand 3
4. CLA	Clear accumulator 
5. EOP	End of program and stops the computer
6. undefined	When no instruction detected, move on to next instruction

Initial test programs:
- Data movement testing (✓)
- Arithmetic instruction testing (✓)
- Program flow control + miscellaneous testing (✓)

Showcase programs:
- calculates (and print out) the squares of all the integers between 0 and 99 (✓)
- calculates (and print out) all the prime numbers between 1 and 1000 (✓)
