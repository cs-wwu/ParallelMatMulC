#include <stdio.h>
#include "matmul.h"

int main(int argc, char** argv) {
    Matrix* m1 = mat_identity(6);
    mat_print(m1);

    Matrix* m2 = mat_random(5, 10, 0, 100);
    mat_print(m2);

    Matrix* m3 = mat_read("test/mat-5-10");
    mat_print(m3);
}
