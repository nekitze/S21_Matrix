#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"

Suite *comparsion_suite();
Suite *create_remove_suite();
Suite *sum_sub_suite();
Suite *mult_suite();
Suite *other_suite();

#endif
