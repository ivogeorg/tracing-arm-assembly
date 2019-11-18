# Tracing the Execution of an ARM Assembly Program

A short demo of tracing an ARM assembly program.

## 1. C Program Compiled to ARM Cortex-M0 Assembly

You can see both programs side by side in the convenient [Compiler Explorer](https://godbolt.org/z/FLnBlV) with line-by-line highlights. Screenshot shown below.

![alt text](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/compiler-explorer.png "Programs in Compiler Explorer")

## 2. Reading the ARM Instructions

A line-by-line reading of the instructions of the generated ARM code can be seen in the file [instruction-reading](instruction-reading.md).

### 2.1 ARM Cortex-M0 Instruction Set Documentation

1. [Main page](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/CIHJJEIH.html).
2. [Programmer's Model](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0432c/CHDCICDF.html).
3. [Flags and Links to Detailed Descriptions](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/BABIHJGA.html).
4. [Conditional Execution](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/BABEHFEF.html).

## 3. Tracing the Program State

### 3.1 Computer states

The assembly programmer's [model for a computer](images/ARM-Cortex-M0-basic-sketch.png) is very simple: register bank, ALU, data memory, instruction memory, and stack. These are the elements that form the _state_ of the computer as far as we are concerned.

By tracing the execution of the program, we will identify the computer state at three locations in the code:
1. After Line 17, before Line 18. [Sketch.](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/Tracing-example-1-State-after-line-17.png)
2. After Line 9, before Line 10. [Sketch.](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/Tracing-example-2-State-after-line-9.png)
3. After Line 28, before Line 29. [Sketch.](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/Tracing-example-3-State-after-line-28.png)

### 3.2 Things to keep in mind

1. Execution starts with the first instruction of the `main` function (for compiled standalone C programs).
2. Instructions are stored in memory in consecutive _words_ _(this means that instructions are stored in consecutive word-aligned 4-byte memory slots, and their addresses differ by 4)_ and are executed in order, except after a branch. The Program Counter register `pc` holds the address of the currently decoded instruction. Use the [program line numbers, converted to hexadecimal](docs/Assembly-tracing-address-sheet.pdf), as instruction addresses.
3. Upon branching, the Link Register `lr` is assigned the address of the instruction to be executed when returning from the branch. This is called the _return address_. The instruction branch with exchange `bx` swaps the contents of `lr` and `pc`, returning execution to this instruction.
4. The stack grows _down_ from higher to lower addresses. The _top_ of the stack is its lowest address. This address is stored in the Stack Pointer register `sp`. At the start of the program, `sp` holds an invalid address _above_ the top.
5. Conditional statements and loops are implemented with the use of _status bits_ N, Z, C, and V. They are pary of the Application Status Register and are set and cleared automatically by the processor.
6. Comparison instructions _always_ update the status bits. Other instructions do not, unless they have an `S` appended to the opcode.


### 3.3 Video demo

TODO
