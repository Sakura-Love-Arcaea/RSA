#include "../headers/fastExponentiation.h"




int fastExponentiation(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1){ result = (result * base) % mod; }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}