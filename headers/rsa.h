#ifndef RSA_RSA_H
#define RSA_RSA_H
#define PUBLIC 0
#define PRIVATE 1

int** keyGenerator(int p, int q);
int encryption(int P, int* publicKey);
int decryption(int C, int* privateKey);
#endif //RSA_RSA_H
