#include <stdio.h>
#include <stdint.h>

int main(void)
{
    // Initializing the array of bytes
    uint8_t data[]    = {0x42, 0x00, 0x65, 0xFF, 0x6c, 0x00, 0x6F}; 
    size_t zero_count = 0;    // Set the zero_count variable to '0' for now

    for (size_t i = 0; i < sizeof(data); i++) {
        if (data[i] == 0x00) {
            zero_count += 1;
        }
    }
    
    printf("The size of the array is [ %ld bytes ]\n", sizeof(data));
    printf("Number of 0x00 is [ %zu ]\n", zero_count);

    return 0;
}
