( C Practice 1: Variables, Arrays and Loops ) [ COMPLETED (1)]

Malware analysts often inspect files as raw bytes. In C, uint8_t represents one unsigned bytes
with values from 0 to 255. An array stores several such values together, while a loop lets you 
inspect them individually.

Exercise:
         Write a C program that examines this byte array:
         uint8_t data[] = {0x8, 0x00, 0x65, 0xFF, 0x6C, 0x00, 0x6F};

    Your program should:
    - Count the total number of bytes.
    - Count how many bytes equal 0x00.
    - Print both results.
    - Use a loop, do not count them manually.
    - Include <stdint.h> and calculate the array length with sizeof.

    Compile with warnings enabled:
         gcc -Wall practice.c -o practice -Wextra -Wpedantic



( C Practice 2: Functions and bytes matching ) [ COMPLETED (2)]

In defensive analysis, you often need to search raw data for a particular byte. A reusable function
is better than rewriting the same loop each time.

Repeated 0x90 bytes can sometimes appear as padding or x86 NOP instructions. Their presence alone 
does not prove that data is malicious.

Exercise:
         Write a function that recieves:
         - A byte array
         - The array's lenght
         - A target bytes

         The function must examine the array and 'return how many times the target occurs.'

         Test it using:
         
                     uint8_t data[] = {
                         0x55, 0x48, 0x90, 0x90,
                         0x89, 0xE5, 0x90, 0xC3
                     };

        Search for 0x90 and print the returned count.

        Important: calculate the array length inside main() and pass it to the function. Do not
        use sizeof inside the function to determine the length.



( C Practice 3: Reading bytes through a pointer ) [ COMPLETED (3) ]

Todays reinforces Practice 2 while introducing only one major idea: pointer-based array traversal.

When an array is passed to a function, the function recieves the address of its first element.
A pointer can move throught that memory one element at a time. This is fundamental when examining
file buffers, packet contents, and memory during defensive analysis.

Exercise:
        Create a reusable function that counts how many times a target byte appears, just like 
        Practice 2, but this time:
        
        - Receive the data throught a pointer.
        - Read each byte using pointer dereferencing and pointer arithmetic.
        - Do 'not' use array indexing such as data[i] inside the function.
        - Recieve the buffer lenght and target byte as separate parameters.
        - Return the count to main().
        - Calculate the number of elements in main().
        - Print the returned result from main().

        Use this test data:
            
            uint8_t buffer[] = {
                0x48, 0xCC, 0x31, 0xCC,
                0xC0, 0x90, 0xCC, 0xC3
            };

Search for 0xCC.

  Pointer hint:
              adding an ofset to the data pointer produces the address of that element;
              dereferencing that address reads the byte stored there.

Compile with the usual flags. GOOD LUCK!!!



( C Pratice 4: Printable bytes in a buffer ) [ COMPLETED (4) ]

A binary file can contain readable text mixed eith other bytes. A 'pritable ASCII byte' has a value
from 0x20 through 0x7E, inclusive. A 0x00 bytes is not printable, but it does 'not' mean you should
stop examining a binary buffer.

Execrise:
        Write a function that recieves a buffer and its length, then returns how many bytes are
        printable ASCII. Calculate the length in main() and print the returned count there. You 
        may use array indexing this time.

            uint8_t buffer[] = {
                0x48, 0x69, 0x00, 0x21,
                0xFF, 0x20, 0x7E, 0x0A
            };

        Check every byte, including those after 0x00. Compile with your usual warnig flags.



( CPractice 5: Find the longest printable sequence ) [ COMPLETED (5) ]

Defensive analysts often search binanry data for consecutive printable characters because they may
reveal filename, commands, URLs, or other readable clues.

Exercise:
        Examine this byte buffer:
            
            uint8_t buffer[] = {
                0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F,
                0x90, 0x41, 0x42, 0x43, 0x21,
                0x20, 0x58, 0x00
            };

Write one function: 
    - That Receives the buffer and it's length.
    - That Uses a loop to examine every byte.
    - That Treats bytes from 0x20 throught 0x7E as printable.
    - That Finds the length of the 'longest uninterrupted sequence' of printable bytes.
    - That Returns that length as a size_t.
    - That Does not print from inside the function.

In main(),- calculate the buffer length with sizeof, - call the function, and - print its returned 
result using %zu.

Think about keeping two counters:
    - One for the printable sequence currently being examined.
    - One for the longest sequence encountered so far.
