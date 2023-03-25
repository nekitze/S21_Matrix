#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (!compare_size(A, B)) code = CALC_ERR;

  if (s21_create_matrix(A->rows, A->columns, result)) code = ERROR;

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }

  return code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (!compare_size(A, B)) code = CALC_ERR;

  if (s21_create_matrix(A->rows, A->columns, result)) code = ERROR;

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = OK;

  if (s21_create_matrix(A->rows, A->columns, result)) code = ERROR;

  if (code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;

  if (A->columns != B->rows) code = CALC_ERR;

  if (s21_create_matrix(A->rows, B->columns, result)) code = ERROR;

  if (code == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        double c = 0.0;

        for (int k = 0; k < A->columns; k++) {
          c += A->matrix[i][k] * B->matrix[k][j];
        }

        result->matrix[i][j] = c;
      }
    }
  }

  return code;
}