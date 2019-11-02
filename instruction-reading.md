| Label | Instruction | Meaning |
| --- | --- | --- |
|`global_count:`| |
| |        `.word   13`|
|`times_five:`| |
| |`sub     sp, sp, #8`| |
| |`str     r0, [sp, #4]`| |
| |`ldr     r2, [sp, #4]`| |
| |`movs    r3, r2`| |
| |`lsls    r3, r3, #2`| |
| |`adds    r3, r3, r2`| |
| |`movs    r0, r3`| |
| |`add     sp, sp, #8`| |
| |`bx      lr`| |
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
