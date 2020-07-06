#include <check.h>               
#include "../src/money.h"        
#include <stdlib.h>

/*
  Test function to check if the library can:
  1. Create a Money type variable
  2. Extract the values from the variable
*/
START_TEST(test_money_create) {
  Money *m;
  extern Money *money_create(int, char*);

  m = money_create(5, "USD");
  ck_assert_int_eq(money_amount(m), 5);
  ck_assert_str_eq(money_currency(m), "USD");
  money_free(&m);
} END_TEST


/*
  Test function to check if the library can:
  1. Create a Money type variable
  2. Extract the values from the variable
  3. Assign the value of the Money type pointer to NULL after it has been freed
*/
START_TEST(test_money_safe_free) {
  Money *m;
  extern Money *money_create(int, char*);

  m = money_create(50, "INR");
  ck_assert_int_eq(money_amount(m), 50);
  ck_assert_str_eq(money_currency(m), "INR");
  money_free(&m);
  ck_assert_ptr_eq(m, NULL);
} END_TEST


Suite *money_suite(void) {
  Suite *s;
  TCase *tc_core, *tc_safety;

  s = suite_create("Money");  // Creating the test suite
  tc_core = tcase_create("Core");  // Creating the test case called "Core"
  tc_safety = tcase_create("Pointer Safety");  // Creating the test case called "Pointer Safety"

  tcase_add_test(tc_core, test_money_create);  // Adding the test function: test_money_create to the test case: tc_core
  tcase_add_test(tc_safety, test_money_safe_free);  // Adding the test function: test_money_safe_free to the test case: tc_safety

  suite_add_tcase(s, tc_core);  // Adding the test case: tc_core to the test suite: s
  suite_add_tcase(s, tc_safety);  // Adding the test case: tc_safety to the test suite: s

  return s;
}

int main(void) {
  int no_failed = 0;                   
  Suite *s;                            
  SRunner *runner;                     

  s = money_suite();       

  /*
    Using the newly created test suite s and passing it to the function 
    srunner_create in order to obtain back a pointer to a test suite runner
  */      
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);  
  no_failed = srunner_ntests_failed(runner);  // Get the number of failed tests from the suite runner
  srunner_free(runner);  // Freeing the suite runner from memory   
                
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;  
}
