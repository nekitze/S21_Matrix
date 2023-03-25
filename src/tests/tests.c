#include "tests.h"

void run_suite(Suite *suite) {
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    exit(1);
  }
}

int main() {
  const int suites_cnt = 5;
  Suite *suites[] = {comparsion_suite(), create_remove_suite(), sum_sub_suite(),
                     mult_suite(), other_suite()};
  for (int i = 0; i < suites_cnt; i++) {
    run_suite(suites[i]);
  }
}
