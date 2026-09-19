#include <stdio.h>
#include <stdint.h>

size_t Printable(uint8_t buffer[], size_t length) {
    size_t byteCount = 0;
    size_t i;

    for (i = 0; i < length; i++)
    {
        if (buffer[i] >= 0x20 && buffer[i] <= 0x7E)
        {
            byteCount += 1;
        }
    }

    return byteCount;
}

int main(void) {
    size_t result;

    uint8_t buffer[] = {
        0x48, 0x69, 0x00, 0x21,
        0xFF, 0x20, 0x7E, 0x0A
    };
    result = Printable(buffer, sizeof(buffer));

    printf("Printable bytes are [ %zu ]\n", result);

    return 0;
}
