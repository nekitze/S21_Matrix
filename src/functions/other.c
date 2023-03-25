#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = OK;

  if (s21_create_matrix(A->columns, A->rows, result)) code = ERROR;

  if (code == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;

  double pow = -1.0;

  if (A->rows != A->columns) code = CALC_ERR;

  if (s21_create_matrix(A->rows, A->rows, result)) code = ERROR;

  if (code == OK && A->rows != 1) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->rows; j++) {
        pow *= -1.0;
        result->matrix[i][j] = pow * calculate_minor(A, i, j);
      }
    }
  } else {
    result->matrix[0][0] = 1.0;
  }

  return code;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  double pow = -1.0;

  if (A->rows != A->columns) code = CALC_ERR;

  if (A->rows > 2) {
    for (int i = 0; i < A->columns; i++) {
      pow *= -1.0;
      *result += pow * A->matrix[0][i] * calculate_minor(A, 0, i);
    }
  } else if (A->rows == 2) {
    *result = calculate_minor(A, 0, 0);
  } else if (A->rows == 1) {
    *result = A->matrix[0][0];
  }

  if (*result<PRECISION && * result> 0.0) *result = 0.0;

  return code;
}

double calculate_minor(matrix_t *A, int row, int column) {
  double result = 0.0;
  double pow = -1.0;

  if (A->rows > 2) {
    matrix_t *minor = create_minor_matrix(A, row, column);

    if (minor && minor->matrix) {
      if (minor->rows > 2) {
        for (int i = row; i < minor->columns; i++) {
          pow *= -1.0;
          result +=
              pow * minor->matrix[row][i] * calculate_minor(minor, row, i);
        }
      } else {
        result = minor->matrix[0][0] * minor->matrix[1][1] -
                 minor->matrix[0][1] * minor->matrix[1][0];
      }
      s21_remove_matrix(minor);
      free(minor);
    }

  } else if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (A->rows == 1) {
    result = A->matrix[0][0];
  }

  return result;
}

matrix_t *create_minor_matrix(matrix_t *A, int row, int column) {
  matrix_t *minor = malloc(sizeof(matrix_t));

  minor->matrix = NULL;
  minor->columns = 0;
  minor->rows = 0;

  int minor_i = 0;
  int minor_j = 0;

  if (s21_create_matrix(A->columns - 1, A->rows - 1, minor)) return NULL;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->rows; j++) {
      if (j != column && i != row) {
        minor->matrix[minor_i][minor_j] = A->matrix[i][j];
        minor_j++;
      }
    }
    if (i != row) {
      minor_i++;
    }
    minor_j = 0;
  }

  return minor;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  double det = 0.0;

  matrix_t complements;
  matrix_t transposed;

  if (A->rows != A->columns) {
    code = CALC_ERR;
  } else {
    s21_determinant(A, &det);
    if (det <= PRECISION && det >= 0.0) code = CALC_ERR;
    if (s21_create_matrix(A->rows, A->rows, result)) code = ERROR;
  }

  if (code == OK) {
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transposed);
    s21_mult_number(&transposed, 1.0 / det, result);
  }

  return code;
}