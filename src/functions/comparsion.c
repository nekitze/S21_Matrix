#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  double diff = 0;

  code = compare_size(A, B);

  for (int i = 0; i < A->rows && code; i++) {
    for (int j = 0; j < A->columns; j++) {
      diff = A->matrix[i][j] - B->matrix[i][j];

      if (fabs(diff) > PRECISION) {
        code = FAILURE;
        break;
      }
    }
  }

  return code;
}

int compare_size(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;

  if (A->rows != B->rows || A->columns != B->columns) {
    code = FAILURE;
  }

  if (!(A->matrix && B->matrix)) {
    code = FAILURE;
  }

  return code;
}