# Memory

## Hexadecimals

- Using hexadecimal system: count 0-9 than start counting A-F (base 16), don't
  need a second digit this way
  - Count 0-F, similar to decimal counting
  - When we hit 0F (16 column === 0, 1 column === F), carry the 1 to have 10 (16
    column === 1, 1 column === 0) same way we count in decimal except we count
    to 16 before rounding
  - If we count up to FF: 16 _ F[15] + 1 _ 15[F] 240 + 15 255
  - 255 reflects 8 1 bits in binary, e.g. it is a perfect system for
    representing four bits at a time (one hexadecimal digit is equivalent to
    four bits in decimal, so we use 2 hexadecimals to represent eight bits)
  - This is why we use hex to represent colors (each color, rgb, is 2 digits
    each)
    - Prefix with 0x to represent that these numbers are meant to be hex (0x72
      0x73 0x74)
  - #000000 is black (no rgb), #ffffff is white(highest rgb values), #ff0000 is
    red (0 green and blue, high red), #00ff00 is green (0 red and blue, high
    green), #0000ff is blue (0 red and green, high blue)

## Pointers

- Pointer (%p) is a variable that contains the address of some other value
  - References the type of value regardless of what it is (char, bool, int,
    etc.)
- p is also a variable that lives somewhere in your computer memory, they
  actually take up 8 bites of memory

  - It is rarely useful to access this information, we abstract away the details
    and think of the pointer as a literal arrow pointing at the location of the
    value we want rather than an actual address

- When working with strings each char takes up one bit of memory, plus the \0 to
  end the string
  - We can refer to each index of the string like an array, but they can also be
    manipulated by referencing the address of the char
  - The variable storing the string (s) is the address of the first character of
    the string, all the computer needs is this address because we know when the
    string ends (\0, null), we also know the characters are stored back to back
    like an array

* Strings do not officially exist as a data type in C! We are getting these from
  the CS50 library (defined using typedef char \*string). Instead,they actually
  exist as char \*s

  - Represents the address of a character (the first character of the string)

  * We will no longer use string in CS50 because it doesn't exist, use char \*s
    from now on

* We can now do pointer arithmetic, math based on the address (add to the first
  character to display the string, see stringAddress.c)

  - Using square bracket notation is a user friendly syntactic sugar, not the
    official c language

* Segmentation fault error means we are touching memory we shouldn't

  - valgrind is a function that can detect if we forget to clear malloc with
    free (which causes a memory leak) and tell us what we are touching in memory
    that we shouldn't be (see memory.c)

* Memory is stored in the following order:

  - Machine code
  - Globals
  - Heap <-- This is where memory is allocated when we call malloc, this flows
    down
  - Stack <-- This flows up!! When we call functions stack memory is used, not
    heap memory
    - Memory gets used and reused when functions are called, when a function is
      called it is added to the top of the stack then removed when it finishes
      running --> Whatever values are stored here immediately become garbage
      values, they are not accessible to main (see swap.c)
    * Stack overflow is when a function gets called so many times that it
      overflows the heap causing the program to crash
      - Benefit of using iteration is there is no chance of stack overflow, but
        with recursion this is what will happen if we forget the base case

* Buffer overflow: Allocate an array and go further than the end of it (buffer
  is a piece of memory, buffer overflow goes beyond that space)

* File I/O: Taking input and output from files (not depending on memory, this is
  what we need if we want something to be stored permanently)
