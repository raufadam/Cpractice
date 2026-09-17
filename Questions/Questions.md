( C Practice 1: Variables, Arrays and Loops ) [ COMPLETED ]

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



( C Practice 2: Functions and bytes matching ) [ COMPLETED ]

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



( C Practice 3: Reading bytes through a pointer )

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

 

        
