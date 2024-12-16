// common_crypto.c
#include <string.h>

void encrypt(const char *input, char *output) {
    // Simple encryption logic (for demonstration purposes)
    for (int i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + 1; // Shift each character by 1
    }
    output[strlen(input)] = '\0'; // Null-terminate the output
}
