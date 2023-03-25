#include "../tests.h"

START_TEST(mult_num) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 4, &A);

  fill_matrix(&A);

  int code = s21_mult_number(&A, 10., &result);
  double res = result.matrix[0][2];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 30.);
}
END_TEST

START_TEST(mult_zero) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 4, &A);

  fill_matrix(&A);

  int code = s21_mult_number(&A, 0, &result);
  double res = result.matrix[2][3];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 0);
}
END_TEST

START_TEST(mult_one) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 4, &A);

  fill_matrix(&A);

  int code = s21_mult_number(&A, 1, &result);
  double res = result.matrix[0][0];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 1);
}
END_TEST

START_TEST(mult_subzero) {
  matrix_t A;
  matrix_t result;

  s21_create_matrix(3, 4, &A);

  fill_matrix(&A);

  int code = s21_mult_number(&A, -1, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, -2);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 6, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  int code = s21_mult_matrix(&A, &B, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 140);
}
END_TEST

START_TEST(mult_matrix_wrong) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(5, 6, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  int code = s21_mult_matrix(&A, &B, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(mult_matrix_zero) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 6, &B);

  fill_matrix(&A);

  int code = s21_mult_matrix(&A, &B, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 0);
}
END_TEST

START_TEST(mult_matrix_subzero) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 4, &A);
  s21_create_matrix(4, 6, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  A.matrix[0][1] = -100.;

  int code = s21_mult_matrix(&A, &B, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, -676.);
}
END_TEST

START_TEST(mult_matrix_n1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 1, &A);
  s21_create_matrix(1, 6, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  int code = s21_mult_matrix(&A, &B, &result);
  double res = result.matrix[1][3];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 8);
}
END_TEST

START_TEST(mult_matrix_n1_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = 2;
  B.matrix[0][0] = 3;

  int code = s21_mult_matrix(&A, &B, &result);
  double res = result.matrix[0][0];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 6);
}
END_TEST

Suite *mult_suite() {
  Suite *suite = suite_create("mult_suite");

  TCase *tcase_add = tcase_create("mult");

  tcase_add_test(tcase_add, mult_num);
  tcase_add_test(tcase_add, mult_zero);
  tcase_add_test(tcase_add, mult_one);
  tcase_add_test(tcase_add, mult_subzero);
  tcase_add_test(tcase_add, mult_matrix);
  tcase_add_test(tcase_add, mult_matrix_wrong);
  tcase_add_test(tcase_add, mult_matrix_zero);
  tcase_add_test(tcase_add, mult_matrix_subzero);
  tcase_add_test(tcase_add, mult_matrix_n1);
  tcase_add_test(tcase_add, mult_matrix_n1_1);

  suite_add_tcase(suite, tcase_add);

  return suite;
}