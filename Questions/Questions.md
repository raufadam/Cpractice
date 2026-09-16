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
                                                                                                                                                                                                                                                                                                                                                        
