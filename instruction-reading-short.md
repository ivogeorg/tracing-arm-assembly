| Label | Instruction | Meaning (short) |
| --- | --- | --- |
|`global_count:`| |
| |        `.word   13`|  |
|`times_five:`| |
| |`sub     sp, sp, #8`| Decrement sp by 8. |
| |`str     r0, [sp, #4]`| Store r0 at [sp + 4]. |
| |`ldr     r2, [sp, #4]`| Load value at [sp + 4] into r2. |
| |`movs    r3, r2`| Copy r2 to r3. |
| |`lsls    r3, r3, #2`| Shift r3 left by 2. |
| |`adds    r3, r3, r2`| Add r2 to r3. |
| |`movs    r0, r3`| Copy r3 to r0. |
| |`add     sp, sp, #8`| Increment sp by 8. |
| |`bx      lr`| Branch with exchange. |
|`main:`| |
| |`push    {r4, lr}`| Push r4 and `lr` onto the stack. |
| |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| |`ldr     r3, [r3]`| Load the value at [r3] into r3. |
| |`cmp     r3, #13`| Compare r3 with 13. |
| |`bgt     .L4`| Branch to `.L4` if greater than. |
| |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| |`ldr     r3, [r3]`| Load the value at [r3] into r3. |
| |`movs    r0, r3`| Copy r3 to r0. |
| |`bl      times_five`| Branch with link to `times_five`. |
| |`movs    r2, r0`| Copy r0 to r2. |
| |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| |`str     r2, [r3]`| Store r2 at [r3]. |
|`.L4:`| | |
| |`movs    r3, #0`| Write 0 in r3. |
| |`movs    r0, r3`| Copy r3 to r0. |
| |`pop     {r4, pc}`| Pop from the stack into r4 and `pc`.|
|`.L6:`| |
| |`.word   global_count`|  |
