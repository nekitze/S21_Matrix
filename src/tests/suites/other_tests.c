#include "../tests.h"

START_TEST(transpose) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 2, &A);

  fill_matrix(&A);

  int code = s21_transpose(&A, &result);
  double res = result.matrix[1][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 4);
}
END_TEST

START_TEST(transpose_n1) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(1, 1, &A);

  fill_matrix(&A);

  int code = s21_transpose(&A, &result);
  double res = result.matrix[0][0];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 1);
}
END_TEST

START_TEST(determinant) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(2, 2, &A);

  fill_matrix(&A);

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, -2);
}
END_TEST

START_TEST(determinant_n3) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(3, 3, &A);

  fill_matrix(&A);

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 0);
}
END_TEST

START_TEST(determinant_n4) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(4, 4, &A);

  fill_matrix(&A);

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 0);
}
END_TEST

START_TEST(determinant_n3_notnull) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(3, 3, &A);

  fill_matrix(&A);

  A.matrix[0][2] = 13;

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, -30);
}
END_TEST

START_TEST(determinant_n3_2) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(3, 3, &A);

  fill_matrix(&A);

  A.matrix[0][2] = -13;

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 48);
}
END_TEST

START_TEST(determinant_n1) {
  matrix_t A;
  double res = 0;

  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = -255;

  int code = s21_determinant(&A, &res);

  s21_remove_matrix(&A);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, -255);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t A;
  matrix_t B;
  matrix_t res;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  fill_matrix(&A);

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 10;
  B.matrix[0][2] = -20;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = -14;
  B.matrix[1][2] = 8;
  B.matrix[2][0] = -8;
  B.matrix[2][1] = -2;
  B.matrix[2][2] = 4;

  int code = s21_calc_complements(&A, &res);

  int fact = s21_eq_matrix(&res, &B);

  ck_assert_int_eq(res.matrix[0][2], -20);
  ck_assert_int_eq(res.matrix[1][1], -14);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(fact, SUCCESS);
}
END_TEST

START_TEST(calc_complements_n1) {
  matrix_t A;
  matrix_t res;

  s21_create_matrix(1, 1, &A);

  A.matrix[0][0] = -123;

  int code = s21_calc_complements(&A, &res);

  int fact = res.matrix[0][0];

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(fact, 1);
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t res;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;
  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;

  int code = s21_inverse_matrix(&A, &res);

  int fact = s21_eq_matrix(&res, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(fact, SUCCESS);
}
END_TEST

START_TEST(inverse_matrix_n1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 2;

  B.matrix[0][0] = 0.5;

  int code = s21_inverse_matrix(&A, &res);

  int fact = s21_eq_matrix(&res, &B);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);

  ck_assert_int_eq(code, 0);
  ck_assert_int_eq(fact, SUCCESS);
}
END_TEST

START_TEST(high) {
  matrix_t A;
  matrix_t res;

  s21_create_matrix(10, 10, &A);

  fill_matrix(&A);

  int code = s21_inverse_matrix(&A, &res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);

  ck_assert_int_eq(code, CALC_ERR);
}
END_TEST

Suite *other_suite() {
  Suite *suite = suite_create("other_suite");

  TCase *tcase_add = tcase_create("other");

  tcase_add_test(tcase_add, transpose);
  tcase_add_test(tcase_add, transpose_n1);
  tcase_add_test(tcase_add, determinant);
  tcase_add_test(tcase_add, determinant_n3);
  tcase_add_test(tcase_add, determinant_n4);
  tcase_add_test(tcase_add, determinant_n3_notnull);
  tcase_add_test(tcase_add, determinant_n3_2);
  tcase_add_test(tcase_add, determinant_n1);
  tcase_add_test(tcase_add, calc_complements);
  tcase_add_test(tcase_add, calc_complements_n1);
  tcase_add_test(tcase_add, inverse_matrix);
  tcase_add_test(tcase_add, inverse_matrix_n1);
  tcase_add_test(tcase_add, high);

  suite_add_tcase(suite, tcase_add);

  return suite;
}