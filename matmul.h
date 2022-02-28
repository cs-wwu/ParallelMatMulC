#ifndef MATMUL_H
#define MATMUL_H

// Define a matrix type
typedef struct {
    int rows;
    int cols;
    int* values;
} Matrix;

// Get the ith row and col value
int mat_get(Matrix* mat, int row, int col);

// Set the ith row and col value
void mat_set(Matrix* mat, int row, int col, int value);

// Print the matrix out
void mat_print(Matrix* mat);

// Generate a zero matrix of size rows and cols
Matrix* mat_zero(int rows, int cols);

// Generate an identity square matrix of size rows
Matrix* mat_identity(int rows);

// Generate a random matrix of size rows and cols.
// The values are in the range [minval, maxval]
Matrix* mat_random(int rows, int cols, int minval, int maxval);

// Free the given matrix
void mat_free(Matrix* mat);

// Read the matrix from the file into memory. Alloc and return the matrix.
// If the file can't be read, return NULL
Matrix* mat_read(const char* filename);

// Sequential matrix multiplication. Allocate and return the result.
// Return NULL if the matrices can't be multiplied
Matrix* mat_mul_slow(Matrix* mat1, Matrix* mat2);

// Parallel matrix multiplication. Allocate and return the result.
// Return NULL if the matrices can't be multiplied
Matrix* mat_mul_fast(Matrix* mat1, Matrix* mat2);

#endif // MATMUL_H
