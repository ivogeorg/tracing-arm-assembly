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

By tracing the execution of the program, we will identify the computer state at three locations in the code:
1. After Line 17, before Line 18. [Sketch.](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/Tracing-example-1-State-after-line-17.png)
2. After Line 9, before Line 10.
3. After Line 28, before Line 29.

### 3.2 Video demo

TODO
