#include <stdio.h>
#include <stdint.h>

size_t byteArray(uint8_t data[], size_t size, uint8_t target) {
    size_t HexCount = 0;

    // A loop to walk throght the array
    for(size_t i = 0; i < size; i++) 
    {
        if(data[i] == target)
        {
            HexCount += 1;
        }
    }

    return HexCount;
}

int main(void)
{
    uint8_t data[] = {
        0x55, 0x48, 0x90, 0x90,
        0x89, 0xE5, 0x90, 0xC3
    };
    size_t result  = byteArray(data, sizeof(data), 0x90);
    
    // Results from the HexCount in the function "byteArray" is displayed here
    printf("The selected byte appeared [ %zu ] times in the array.\n", result);

    return 0;
}
