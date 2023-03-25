#include "../tests.h"

START_TEST(create) {
  matrix_t matrix;

  int fact = s21_create_matrix(3, 3, &matrix);
  int assert = 0;

  s21_remove_matrix(&matrix);

  ck_assert_int_eq(fact, assert);
}
END_TEST

START_TEST(create_zero) {
  matrix_t matrix;

  int fact = s21_create_matrix(0, 0, &matrix);
  int assert = 1;

  ck_assert_int_eq(fact, assert);
}
END_TEST

Suite *create_remove_suite() {
  Suite *suite = suite_create("create_remove_suite");

  TCase *tcase_add = tcase_create("create_remove");

  tcase_add_test(tcase_add, create);
  tcase_add_test(tcase_add, create_zero);

  suite_add_tcase(suite, tcase_add);

  return suite;
}
