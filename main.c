// global data
static int global_count = 13;

// A function that returns its
// argument multiplied by 5
int times_five(int a) {
    return 5 * a;
}

// Every program in the C language always starts in the 'main()' function
int main() {
    // Calling another function will
    // cause a new stack frame to be
    // set up for it on top of the
    // stack frame for main
    if (global_count <= 13)
        global_count = times_five(global_count);

    return 0;
}
