#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../headers/fastExponentiation.h"
#include "../headers/inverseElement.h"
#include "../headers/rsa.h"

int** keyGenerator(int p, int q) {
    srand(time(NULL));

    int** keys = (int **) malloc(sizeof(int*) * 2);
    keys[PUBLIC] = (int *) malloc(sizeof(int) * 2);
    keys[PRIVATE] = (int *) malloc(sizeof(int) * 2);
    int phiN = (p-1) * (q-1);
    int N = p * q;
    int e;
    do {
        e = 2 + rand() % (phiN - 1);
    } while (inverseElement(e, phiN) == 0);
    int d = inverseElement(e, phiN);

    keys[PUBLIC][0] = e;
    keys[PUBLIC][1] = N;
    keys[PRIVATE][0] = d;
    keys[PRIVATE][1] = N;

    return keys;
}

int encryption(int P, int* publicKey) {
    return fastExponentiation(P, publicKey[0], publicKey[1]);
}

int decryption(int C, int* privateKey) {
    return fastExponentiation(C, privateKey[0], privateKey[1]);
}
