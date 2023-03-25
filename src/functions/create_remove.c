#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int code = 0;

  if (rows >= 1 && columns >= 1) {
    result->matrix =
        malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
  } else {
    code = 1;
  }

  if (code == 0 && result->matrix != NULL) {
    double *ptr = (double *)(result->matrix + rows);

    result->rows = rows;
    result->columns = columns;

    for (int i = 0; i < rows; i++) {
      result->matrix[i] = ptr + columns * i;
    }

    zero_matrix(result);

  } else {
    code = 1;
  }

  return code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) free(A->matrix);
}

void zero_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = 0.0;
    }
  }
}