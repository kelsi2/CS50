# Arrays

4 steps happen when we run "make" (not just compiling the code) --> All these
steps are included in compiling today

1. Preprocessing

   - The #include lines at the top of the file are replaced with the actual code
     from those files (basically copy pasted into the file we are using)

2. Compiling

   - File is compiled into assembly code which includes instructions for the CPU

3. Assembling

   - This assembly code is then turned into machine code (binary) so the CPU can
     understand and execute it

4. Linking

   - Combine all binary from all included files to create one file of binary

### Debugging

- Bug === mistake in the program
- Help50: Prefix make with this for help debugging
- Printf: Can also help with debugging (write what the code is at each step for
  example)
- Debug50: Exists in cs50 ide
  - Create a break point by clicking on the line you want to stop at, then run
    debug50
  - Use step over to run one line at a time and see what happens at each step
- Check50: Help you look for errors in code before submitting
  - Running tests on your code
- Style50: Do you have all the formatting correct?
  - Is it easy to read, look at, and maintain?

* Three aspects of code:
  - Correctness
    - Does your solution work?
  - Design
    - Not only looking for a solution that works but the best solution to the
      problem
  - Style
    - Is your code formatted well?

### Arrays

- Avoid repetitive and limited code by using arrays

  - See scores.c for further notes

- Computer ends a string with \0 (null character), it is using one byte to do
  this so the string is always one byte (8 bites) longer than it would be
  normally
  - ex. string s = "HI!" === H(s[0]) I(s[1]) !(s[2]) \0(s[3])

### String

- See string.c and uppercase.c for notes

### Command Line Arguments

- When setting up the int main(void) function we can pass in arguments like: int
  main(int argc, stringargv[])
  - argv === argument vector, an array of strings
  - argc === argument count, an integer
    - See scores.c for an example of this type of function
  - We enter these values on the command line when running make

* Main has a return value of int, by default this is zero
  - Errors return negative or positive values, anything but 0!
