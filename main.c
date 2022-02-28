#include <stdio.h>
#include "matmul.h"

int main(int argc, char** argv) {
    Matrix* m1 = mat_identity(2);
    mat_print(m1);

    Matrix* m2 = mat_random(2, 2, 0, 100);
    mat_print(m2);

    Matrix* m3 = mat_mul_slow(m1, m2);
    mat_print(m3);
}
