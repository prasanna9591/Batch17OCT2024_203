#include <stdio.h>
#include <string.h>
#include "common_crypto.h"

// XOR cipher encryption (same function can be used for decryption)
void encrypt(const char *input, char *output) {
    int i;
    char key = 'K'; // A simple key for XOR (can be any character)

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key;  // XOR each character with the key
    }
    output[i] = '\0'; // Null-terminate the string
}

// XOR cipher decryption (same as encryption for XOR)
void decrypt(const char *input, char *output) {
    int i;
    char key = 'K'; // Same key used for XOR (decryption is identical to encryption)

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key;  // XOR each character with the key
    }
    output[i] = '\0'; // Null-terminate the string
}

