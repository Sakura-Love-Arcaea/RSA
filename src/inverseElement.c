#include <stdio.h>
#include "../headers/inverseElement.h"

int inverseElement(int n, int mod) {
    int q, a = mod, b = n, m, s1 = 0, s2 = 1, s3;
    while (b != 0) {
        m = a % b;
//        printf("m = %d\n", m);

        q = a / b;

        s3 = s1 - q * s2;
//        printf("%3d |%3d %3d %3d |%3d %3d %3d\n", q, a, b, m, s1, s2, s3);

        s1 = s2;
        s2 = s3;

        a = b;
        b = m;

    }
    if (a == 1) {
        return s1 > 0 ? s1 : mod + s1;
    } else {
        return 0;
    }


}
