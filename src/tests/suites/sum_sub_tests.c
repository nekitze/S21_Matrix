#include "../tests.h"

START_TEST(sum) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  A.matrix[0][1] = 10;

  int code = s21_sum_matrix(&A, &B, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 12);
}
END_TEST

START_TEST(sub) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  A.matrix[0][1] = 10;

  int code = s21_sub_matrix(&A, &B, &result);
  double res = result.matrix[0][1];

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(res, 8);
}
END_TEST

START_TEST(sub_wrong) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 4, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  int code = s21_sub_matrix(&A, &B, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(sum_wrong) {
  matrix_t A;
  matrix_t B;
  matrix_t result;

  s21_create_matrix(4, 3, &A);
  s21_create_matrix(3, 4, &B);

  fill_matrix(&A);
  fill_matrix(&B);

  int code = s21_sum_matrix(&A, &B, &result);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);

  ck_assert_int_eq(code, 2);
}
END_TEST

Suite *sum_sub_suite() {
  Suite *suite = suite_create("sum_sub_suite");

  TCase *tcase_add = tcase_create("sum_sub");

  tcase_add_test(tcase_add, sum);
  tcase_add_test(tcase_add, sub);
  tcase_add_test(tcase_add, sub_wrong);
  tcase_add_test(tcase_add, sum_wrong);

  suite_add_tcase(suite, tcase_add);

  return suite;
}
