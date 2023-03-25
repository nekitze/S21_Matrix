#include "../s21_matrix.h"

void print_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      printf("%lf ", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}

void fill_matrix(matrix_t *matrix) {
  int count = 0;

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = ++count;
    }
  }
}