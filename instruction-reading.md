| Label | Instruction | Meaning |
| --- | --- | --- |
|`global_count:`| |
| |        `.word   13`|
|`times_five:`| |
| |`sub     sp, sp, #8`| Decrement the stack pointer by 8, meaning two words (that is, 4-byte memory positions). This effectively creates the _stack frame_ of `times_five` on the stack, right on top of the stack frame of the function that called it, `main`. Note that the stack pointer always points at the word which is **at** the _top_ of the stack, never an _"empty"_ word on top of the stack. |
| |`str     r0, [sp, #4]`| Store (the value of) register r0 to the stack position at stack pointer + 4 (bytes) (that is, the position right below the top of the stack). |
| |`ldr     r2, [sp, #4]`| Load into register r2 the value at the stack memory position right below the top of the stack. Note that this is what was stored in the previous instruction. It is _redundant_ but _correct_. A `mov r2, r0` would have done the job. _The redudancy comes from the generic behavior of the compiler when no compiler optimization options are used. You can see the options at the line right next to the compiler version used, at the top right of the [Compiler Explorer](https://github.com/ivogeorg/tracing-arm-assembly/blob/master/images/compiler-explorer.png) window._ |
| |`movs    r3, r2`| Copy the value of register r2 to register r3. Because there is an `s` at the end of the the `mov`, the instruction may modify the **N (negative)** and **Z (zero)** flags depending on the result of the instruction. The result of the instruction here is the value that is being copied, and so the `movs` instruction will set the **N** and **Z** flags according to this value. In this case, this information, though generated, is not used. |
| |`lsls    r3, r3, #2`| Shift the value of r3 left two positions, effectively multiplying the value by 4. The `s` at the end means that this instruction may set any of the 4 status flags **NZCV**. _Note that a shift left may result in a carry and an overflow._ |
| |`adds    r3, r3, r2`| Add the value of r2 to r3 (and write the result to r3). This effectilvey completes the multiplication by 5 of the `times_five` function. So, `5 * a = a + a<<2`. Note the `s`.|
| |`movs    r0, r3`| Copy the value of r3 to r0. Register r0 is frequently used to pass arguments from a caller function (here, `main`) to the called function (here, `times_five`), and then to "return" the result of the called function to the caller function. Note the `s`.|
| |`add     sp, sp, #8`| Increment the stack pointer by 2 words (that is, 8 bytes), effectively removing the stack frame for `times_five` from the stack. |
| |`bx      lr`| Branch unconditionally by exchanging the link register `lr` and the program counter `pc`. Note that the branch to `times_five` from `main` is `bl`, which means _branch with link_, which in turn means branch to this address and store the address of the next instruction (the instruction right below the branch) in the link register `lr`. |
|`main:`| |
| |`push    {r4, lr}`| |
| |`ldr     r3, .L6`| |
| |`ldr     r3, [r3]`| |
| |`cmp     r3, #13`| |
| |`bgt     .L4`| |
| |`ldr     r3, .L6`| |
| |`ldr     r3, [r3]`| |
| |`movs    r0, r3`| |
| |`bl      times_five`| |
| |`movs    r2, r0`| |
| |`ldr     r3, .L6`| |
| |`str     r2, [r3]`| |
|`.L4:`| |
| |`movs    r3, #0`| |
| |`movs    r0, r3`| |
| |`pop     {r4, pc}`| |
|`.L6:`| |
| |`.word   global_count`|
