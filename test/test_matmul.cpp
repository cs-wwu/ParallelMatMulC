#define CATCH_CONFIG_MAIN
#include "catch.hpp"

extern "C" {
#include "../matmul.h"
}

/*
TEST_CASE("Create zero", "[zero]") {
    Matrix* m1 = mat_zero(5, 6);
    REQUIRE(m1 != NULL);
    REQUIRE(m1->rows == 5);
    REQUIRE(m1->cols == 6);
    REQUIRE(m1->values != NULL);
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            REQUIRE(mat_get(m1, i, j) == 0);
        }
    }
    mat_free(m1);
}
*/

TEST_CASE("Create identity", "[identity]") {
    Matrix* m2 = mat_identity(4);
    mat_print(m2);

    REQUIRE(m2 != NULL);
    REQUIRE(m2->rows == m2->rows);
    REQUIRE(m2->values != NULL);

    for (int i = 0; i < m2->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            if (i != j) {
                REQUIRE(mat_get(m2, i, j) == 0);
            } else {
                REQUIRE(mat_get(m2, i, j) == 1);
            }
        }
    }
    mat_free(m2);
}

/*
TEST_CASE("Matrix duplication", "[dup]") {
    Matrix* m1 = mat_random(10, 20, 0, 100);
    Matrix* m2 = mat_dup(m1);
    REQUIRE(m1 != m2);
    REQUIRE(mat_equal(m1, m2));
}
*/
