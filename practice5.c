#include <stdio.h>
#include <stdint.h>

size_t bufferFunc(uint8_t buffer[], size_t length) {
     size_t i, firstCounter, secondCounter;

     firstCounter  = 0;
     secondCounter = 0;

     for (i = 0; i < length; i++) {
         // Find printable  bytes
         if (buffer[i] >= 0x20 && buffer[i] <= 0x7E) {
             firstCounter += 1; 

             // Find the longest uninterupted sequence of printable bytes
             if (firstCounter > secondCounter) {
                 secondCounter = firstCounter;
             }
         } else {
             firstCounter = 0;
         }
     }

     return secondCounter;
}

int main(void) {
    size_t result;

    uint8_t buffer[] = {
        0x00, 0x48, 0x65, 0x6C, 0x6C, 0x6F,
        0x90, 0x41, 0x42, 0x43, 0x21,
        0x20, 0x58, 0x00
    };

    result = bufferFunc(buffer, sizeof(buffer));

    printf("the longest uninterupted sequence of printable bytes is [ %zu ] bytes\n", result);

    // printf("The printable byte is [ %zu ] bytes\n", result);

    return 0;
} 
