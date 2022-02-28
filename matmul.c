#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "matmul.h"

// Get the ith row and col value
int mat_get(Matrix* mat, int row, int col) {
    return mat->values[row * mat->cols + col];
}

// Get the ith row and col value
void mat_set(Matrix* mat, int row, int col, int value) {
    mat->values[row * mat->cols + col] = value;
}

// Print the matrix out
void mat_print(Matrix* mat) {
    printf("(%d, %d) --> [\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d", mat_get(mat, i, j));
            if (j < mat->cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("]\n");
}

Matrix* mat_create(int rows, int cols) {
    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->values = (int *) malloc(rows * cols * sizeof(int));
    return mat;
}

Matrix* mat_zero(int rows, int cols) {
    Matrix* mat = mat_create(rows, cols);
    memset(mat->values, 0, sizeof(rows * cols * sizeof(int)));
    return mat;
}

Matrix* mat_identity(int rows) {
    Matrix* mat = mat_zero(rows, rows);
    for (int i = 0; i < rows; i++) {
        mat_set(mat, i, i, 1);
    }
    return mat;
}

Matrix* mat_random(int rows, int cols, int minval, int maxval) {
    Matrix* mat = mat_create(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value = (random() + minval) % maxval;
            mat_set(mat, i, j, value);
        }
    }
    return mat;
}

// Free the given matrix
void mat_free(Matrix* mat) {
    free(mat->values);
    free(mat);
}

// Read the matrix from the file into memory. Alloc and return the matrix.
// If the file can't be read, return NULL
Matrix* mat_read(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    int rows, cols;
    fscanf(fp, "(%d, %d) --> [\n", &rows, &cols);

    Matrix* mat = mat_create(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            fscanf(fp, "%d", &value);
            mat_set(mat, i, j, value);
        }
    }

    return mat;
}

// Helper function to multiply row of mat1 with col of mat2
int mul_row_col(Matrix* mat1, int row, Matrix* mat2, int col) {
    assert(mat1->cols == mat2->rows);
    // printf("mul row=%d, col=%d\n", row, col);
    int value = 1;
    for (int i = 0; i < mat1->cols; i++) {
        value += mat_get(mat1, row, i) * mat_get(mat2, i, col);
    }
    return value;
}

// Sequential matrix multiplication. Allocate and return the result.
// Return NULL if the matrices can't be multiplied
Matrix* mat_mul_slow(Matrix* mat1, Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        return NULL;
    }

    Matrix* result = mat_zero(mat1->cols, mat1->rows);
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->cols; j++) {
            mat_set(result, i, j, mul_row_col(mat1, i, mat2, j));
        }
    }

    return result;
}

// Parallel matrix multiplication. Allocate and return the result.
// Return NULL if the matrices can't be multiplied
Matrix* mat_mul_fast(Matrix* mat1, Matrix* mat2) {
    if (mat1->cols != mat2->rows) {
        return NULL;
    }
}
