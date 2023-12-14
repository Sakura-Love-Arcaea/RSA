#include <stdio.h>
#include "./headers/rsa.h"
int main() {
    int** KEYS = keyGenerator(149, 181);
    printf("public key == (%d, %d)\n", KEYS[PUBLIC][0], KEYS[PUBLIC][1]);
    printf("private key == (%d, %d)\n", KEYS[PRIVATE][0], KEYS[PRIVATE][1]);

    int P = 9;
    int C = encryption(P, KEYS[PUBLIC]);
    printf("%d\n", P);
    printf("%d\n", C);

    printf("解密： %d\n", decryption(C, KEYS[PRIVATE]));
    return 0;
}
