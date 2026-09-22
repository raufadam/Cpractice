#include <stdio.h>
#include <stdint.h>

size_t locateSignature(uint8_t buffer[], size_t length) {
    size_t i, counter = 0;

    for (i = 0; i < length; i++) 
    {
        if (buffer[i] == 0x4D && buffer[i + 1] == 0x5A)
        {
            counter += 1;
        }
    }

    return counter;
}

int main(void) {
    size_t result;

    // Buffer to examine
    uint8_t buffer[] = {
        0x90, 0x00, 0x41, 0x4D,
        0x5A, 0x10, 0xFF, 0xC3
    };

    result = locateSignature(buffer, sizeof(buffer));
    printf("The two consecutive bytes are [ %zu ] bytes\n", result);

    return 0;
}
