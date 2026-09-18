#include <stdio.h>
#include <stdint.h>

int byteCounter(uint8_t *data, int length, uint8_t target) {
    int countBytes = 0;

    uint8_t *walk = data;
    for (walk = data; walk < (data + length); walk++)
    {
        uint8_t compare = *walk;
        if (compare == target)
        {
            countBytes += 1;
        }
    }

    return countBytes;
}

int main(void) {
    int result;
  
    uint8_t buffer[] = {
        0x48, 0xCC, 0x31, 0xCC,
        0xC0, 0x90, 0xCC, 0xC3
    };
    result = byteCounter(buffer, sizeof(buffer), 0xCC);

    printf("The number of the target byte in the array is [ %d ]\n", result);
  
    return 0;
}
