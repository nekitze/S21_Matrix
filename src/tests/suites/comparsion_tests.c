#include "../tests.h"

START_TEST(compare_default) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(3, 4, &matrix1);
  s21_create_matrix(3, 4, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = SUCCESS;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_precision) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = 253.002322;
  matrix2.matrix[3][4] = 253.002321;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_precision2) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = 253.002021;
  matrix2.matrix[3][4] = 253.002022;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_precision3) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = 666.6666661;
  matrix2.matrix[3][4] = 666.6666662;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = SUCCESS;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = -123.123;
  matrix2.matrix[3][4] = 123.123;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero2) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = 0.0001;
  matrix2.matrix[3][4] = -0.0001;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero3) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[3][4] = -0.0001;
  matrix2.matrix[3][4] = -0.0001;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = SUCCESS;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero4) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[5][6] = -0.000001;
  matrix2.matrix[5][6] = 0.000001;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero5) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[5][6] = -0.000001;
  matrix2.matrix[5][6] = -0.000002;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero6) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[5][6] = -0.000001;
  matrix2.matrix[5][6] = -0.000001;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = SUCCESS;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_subzero7) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(7, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  matrix1.matrix[1][2] = -3.003021;
  matrix2.matrix[1][2] = -3.003022;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_size1) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 8, &matrix1);
  s21_create_matrix(7, 8, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_size2) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 8, &matrix1);
  s21_create_matrix(7, 1, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_n1) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);

  fill_matrix(&matrix1);
  fill_matrix(&matrix2);

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = SUCCESS;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(compare_n1_fail) {
  matrix_t matrix1;
  matrix_t matrix2;

  s21_create_matrix(1, 1, &matrix1);
  s21_create_matrix(1, 1, &matrix2);

  fill_matrix(&matrix1);
  matrix2.matrix[0][0] = -1.0;

  int fact = s21_eq_matrix(&matrix1, &matrix2);

  int assert = FAILURE;

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);

  ck_assert_int_eq(fact, assert);
}
END_TEST

Suite *comparsion_suite() {
  Suite *suite = suite_create("comparsion_suite");

  TCase *tcase_add = tcase_create("comparsion");

  tcase_add_test(tcase_add, compare_default);
  tcase_add_test(tcase_add, compare_precision);
  tcase_add_test(tcase_add, compare_precision2);
  tcase_add_test(tcase_add, compare_precision3);
  tcase_add_test(tcase_add, compare_subzero);
  tcase_add_test(tcase_add, compare_subzero2);
  tcase_add_test(tcase_add, compare_subzero3);
  tcase_add_test(tcase_add, compare_subzero4);
  tcase_add_test(tcase_add, compare_subzero5);
  tcase_add_test(tcase_add, compare_subzero6);
  tcase_add_test(tcase_add, compare_subzero7);
  tcase_add_test(tcase_add, compare_size1);
  tcase_add_test(tcase_add, compare_size2);
  tcase_add_test(tcase_add, compare_n1);
  tcase_add_test(tcase_add, compare_n1_fail);

  suite_add_tcase(suite, tcase_add);

  return suite;
}
