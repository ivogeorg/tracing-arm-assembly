| Line | Label | Instruction | Meaning (short) |
| --- | --- | --- | --- |
| 1 |`global_count:`| |
| 2 | |        `.word   13`|  |
| 3 |`times_five:`| |
| 4 | |`sub     sp, sp, #8`| Decrement sp by 8. |
| 5 | |`str     r0, [sp, #4]`| Store r0 at [sp + 4]. |
| 6 | |`ldr     r2, [sp, #4]`| Load value at [sp + 4] into r2. |
| 7 | |`movs    r3, r2`| Copy r2 to r3. |
| 8 | |`lsls    r3, r3, #2`| Shift r3 left by 2. |
| 9 | |`adds    r3, r3, r2`| Add r2 to r3. |
| 10 | |`movs    r0, r3`| Copy r3 to r0. |
| 11 | |`add     sp, sp, #8`| Increment sp by 8. |
| 12 | |`bx      lr`| Branch with exchange. |
| 13 |`main:`| |
| 14 | |`push    {r4, lr}`| Push r4 and `lr` onto the stack. |
| 15 | |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| 16 | |`ldr     r3, [r3]`| Load the value at [r3] into r3. |
| 17 | |`cmp     r3, #13`| Compare r3 with 13. |
| 18 | |`bgt     .L4`| Branch to `.L4` if greater than. |
| 19 | |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| 20 | |`ldr     r3, [r3]`| Load the value at [r3] into r3. |
| 21 | |`movs    r0, r3`| Copy r3 to r0. |
| 22 | |`bl      times_five`| Branch with link to `times_five`. |
| 23 | |`movs    r2, r0`| Copy r0 to r2. |
| 24 | |`ldr     r3, .L6`| Load the address `.L6` into r3. |
| 25 | |`str     r2, [r3]`| Store r2 at [r3]. |
| 26 |`.L4:`| | |
| 27 | |`movs    r3, #0`| Write 0 in r3. |
| 28 | |`movs    r0, r3`| Copy r3 to r0. |
| 29 | |`pop     {r4, pc}`| Pop from the stack into r4 and `pc`.|
| 30 |`.L6:`| |
| 31 | |`.word   global_count`|  |
