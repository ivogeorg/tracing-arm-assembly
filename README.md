# Tracing the Execution of an ARM Assembly Program

A short demo of tracing an ARM assembly program.

## 1. C Program Compiled to ARM Cortex-M0 Assembly

You can see both programs side by side in the convenient [Compiler Explorer](https://godbolt.org/z/FLnBlV), shown below for convenience.

![alt text](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/compiler-explorer.png "Programs in Compiler Explorer")

## 2. Reading the ARM Instructions

A line-by-line reading of the instructions of the generated ARM code can be seen in the file [instruction-reading](instruction-reading.md).

### 2.1 ARM Cortex-M0 Instruction Set Documentation

1. [Main page](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/CIHJJEIH.html).
2. [Programmer's Model](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ddi0432c/CHDCICDF.html).
3. [Flags and Links to Detailed Descriptions](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/BABIHJGA.html).
4. [Conditional Execution](http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/BABEHFEF.html).

## 3. Tracing the Program State

TODO
