#include <check.h>

#include "s21_matrix.h"

void run_test(Suite *thesuit) {
  SRunner *therunner = srunner_create(thesuit);

  srunner_set_fork_status(therunner, CK_NOFORK);
  srunner_run_all(therunner, CK_NORMAL);
  srunner_ntests_failed(therunner);
  srunner_free(therunner);

  printf("\n");
}

START_TEST(test_create_1) {
  matrix_t m;
  int result = s21_create_matrix(5, 7, &m);

  ck_assert_int_eq(m.columns, 7);
  ck_assert_int_eq(m.rows, 5);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_2) {
  matrix_t m;
  int result = s21_create_matrix(1, 1, &m);

  ck_assert_int_eq(m.columns, 1);
  ck_assert_int_eq(m.rows, 1);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_3) {
  matrix_t m;
  int result = s21_create_matrix(100, 100, &m);

  ck_assert_int_eq(m.columns, 100);
  ck_assert_int_eq(m.rows, 100);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_create_4) {
  matrix_t m;
  int result = s21_create_matrix(0, 10, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_5) {
  matrix_t m;
  int result = s21_create_matrix(2, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_6) {
  matrix_t m;
  int result = s21_create_matrix(-1, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_7) {
  matrix_t m;
  int result = s21_create_matrix(0, 0, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_create_8) {
  matrix_t m;
  int result = s21_create_matrix(-10, -10, &m);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_remove_1) {
  matrix_t a;
  s21_create_matrix(3, 3, &a);
  s21_remove_matrix(&a);

  ck_assert_int_eq(0, a.rows);
  ck_assert_int_eq(0, a.columns);
  ck_assert_ptr_eq(NULL, a.matrix);
}
END_TEST

START_TEST(test_remove_2) {
  matrix_t a;
  s21_create_matrix(100, 100, &a);
  s21_remove_matrix(&a);

  ck_assert_int_eq(0, a.rows);
  ck_assert_int_eq(0, a.columns);
  ck_assert_ptr_eq(NULL, a.matrix);
}
END_TEST

START_TEST(test_eq_1x1_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 3.0;
  b.matrix[0][0] = 3.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 0.0;
  b.matrix[0][0] = 0.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.5;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_4) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -100;
  b.matrix[0][0] = -100;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_1x1_5) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 666.6;
  b.matrix[0][0] = 666.6;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.0;
  a.matrix[0][1] = 2.0;
  a.matrix[1][0] = 1.0;
  a.matrix[1][1] = 0.0;

  b.matrix[0][0] = 3.0;
  b.matrix[0][1] = 2.0;
  b.matrix[1][0] = 1.0;
  b.matrix[1][1] = 0.0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.5643;
  a.matrix[0][1] = -2.0;
  a.matrix[1][0] = 1.2100001;
  a.matrix[1][1] = 0.31428;

  b.matrix[0][0] = 3.5643;
  b.matrix[0][1] = -2.0;
  b.matrix[1][0] = 1.2100001;
  b.matrix[1][1] = 0.31428;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_2x2_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 33000.5643;
  a.matrix[0][1] = -2.5676897;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;

  b.matrix[0][0] = 33000.5643;
  b.matrix[0][1] = -2.5676897;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_3x3_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 3300.5643;
  a.matrix[0][1] = -2.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = 0.0;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 0.0;
  a.matrix[2][2] = 0.0000456;

  b.matrix[0][0] = 3300.5643;
  b.matrix[0][1] = -2.5676897;
  b.matrix[0][2] = -20000.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = 0.0;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 0.0;
  b.matrix[2][2] = 0.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_eq_3x3_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 330000.5643;
  a.matrix[0][1] = -20054.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = -89070.02357957;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 1000000.0;
  a.matrix[2][2] = 4567783.0000456;

  b.matrix[0][0] = 330000.5643;
  b.matrix[0][1] = -20054.5676897;
  b.matrix[0][2] = -20000.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = -89070.02357957;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 1000000.0;
  b.matrix[2][2] = 4567783.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 0;
  b.matrix[0][0] = 0.000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_3) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = 3;
  b.matrix[0][0] = 1000.0000000001;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_1x1_4) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);

  a.matrix[0][0] = -56;
  b.matrix[0][0] = 1000.0451;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_2x2_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 3.5643;
  a.matrix[0][1] = -2.0;
  a.matrix[1][0] = 1.2;
  a.matrix[1][1] = 0;

  b.matrix[0][0] = 3.5643;
  b.matrix[0][1] = -2.0;
  b.matrix[1][0] = 1.2100001;
  b.matrix[1][1] = 0.31428;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_2x2_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0.000001;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_3x3_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 330000.5643;
  a.matrix[0][1] = -20054.5676897;
  a.matrix[0][2] = -20000.564610;
  a.matrix[1][0] = -1000.2100001;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = -89070.02357957;
  a.matrix[2][0] = 0.0000023;
  a.matrix[2][1] = 10000.0;
  a.matrix[2][2] = 4567783.0000456;

  b.matrix[0][0] = 330000.5643;
  b.matrix[0][1] = -20054.5676895;
  b.matrix[0][2] = -20.564610;
  b.matrix[1][0] = -1000.2100001;
  b.matrix[1][1] = 0.0000001;
  b.matrix[1][2] = -89070.02357957;
  b.matrix[2][0] = 0.0000023;
  b.matrix[2][1] = 1000000.0;
  b.matrix[2][2] = 4567783.0000456;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_noteq_3x3_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = -1;
  a.matrix[0][2] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0.0000001;
  a.matrix[1][2] = 0;
  a.matrix[2][0] = 0;
  a.matrix[2][1] = 0;
  a.matrix[2][2] = 0;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[0][2] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;
  b.matrix[1][2] = 0;
  b.matrix[2][0] = 0;
  b.matrix[2][1] = 0;
  b.matrix[2][2] = 0;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_1) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_2) {
  matrix_t a;
  matrix_t b;
  s21_create_matrix(5, 5, &a);
  s21_create_matrix(2, 2, &b);

  a.matrix[0][0] = -10.5;
  b.matrix[0][0] = -10.49;

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_3) {
  matrix_t a;
  matrix_t b = {NULL, 0, 0};
  s21_create_matrix(5, 5, &a);

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_4) {
  matrix_t a = {NULL, 0, 0};
  matrix_t b = {NULL, 0, 0};

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_err_eq_5) {
  matrix_t a = {NULL, 0, 0};
  matrix_t b;
  s21_create_matrix(5, 5, &b);

  int res = s21_eq_matrix(&a, &b);
  ck_assert_int_eq(FAILURE, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_sum_1) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[1][0] = 3;
  a.matrix[1][1] = 4;

  b.matrix[0][0] = 4;
  b.matrix[0][1] = 3;
  b.matrix[1][0] = 2;
  b.matrix[1][1] = 1;

  res_matrix.matrix[0][0] = 5;
  res_matrix.matrix[0][1] = 5;
  res_matrix.matrix[1][0] = 5;
  res_matrix.matrix[1][1] = 5;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_2) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 0;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0;

  b.matrix[0][0] = 0;
  b.matrix[0][1] = 0;
  b.matrix[1][0] = 0;
  b.matrix[1][1] = 0;

  res_matrix.matrix[0][0] = 0;
  res_matrix.matrix[0][1] = 0;
  res_matrix.matrix[1][0] = 0;
  res_matrix.matrix[1][1] = 0;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_3) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &b);
  s21_create_matrix(2, 2, &res_matrix);

  a.matrix[0][0] = 1.5;
  a.matrix[0][1] = -5;
  a.matrix[1][0] = 3.50001;
  a.matrix[1][1] = -1000;

  b.matrix[0][0] = -100;
  b.matrix[0][1] = 3;
  b.matrix[1][0] = 2.4;
  b.matrix[1][1] = -10;

  res_matrix.matrix[0][0] = -98.5;
  res_matrix.matrix[0][1] = -2;
  res_matrix.matrix[1][0] = 5.90001;
  res_matrix.matrix[1][1] = -1010;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_4) {
  matrix_t a, b, res_matrix, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &res_matrix);

  a.matrix[0][0] = 0;

  b.matrix[0][0] = -100;

  res_matrix.matrix[0][0] = -100;

  s21_sum_matrix(&a, &b, &sum);
  int res = s21_eq_matrix(&sum, &res_matrix);
  ck_assert_int_eq(SUCCESS, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_1) {
  matrix_t a = {NULL, 0, 0}, b, res_matrix, sum;
  s21_create_matrix(1, 1, &b);
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&b);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_2) {
  matrix_t a, b = {NULL, 0, 0}, res_matrix, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_err_3) {
  matrix_t a = {NULL, 0, 0}, b = {NULL, 0, 0}, res_matrix, sum;
  s21_create_matrix(1, 1, &res_matrix);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(ERROR, res);

  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(test_sum_calc_err_1) {
  matrix_t a, b, sum;
  s21_create_matrix(1, 1, &a);
  s21_create_matrix(2, 2, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_sum_calc_err_2) {
  matrix_t a, b, sum;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(2, 2, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(test_sum_calc_err_3) {
  matrix_t a, b, sum;
  s21_create_matrix(10, 10, &a);
  s21_create_matrix(11, 11, &b);

  int res = s21_sum_matrix(&a, &b, &sum);
  ck_assert_int_eq(CALC_ERROR, res);

  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  matrix_t test_matrix_4;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_2);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  test_matrix_2.matrix[0][0] = 1.0;
  test_matrix_2.matrix[0][1] = 0.0;
  test_matrix_2.matrix[0][2] = 0.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 0.0;
  test_matrix_2.matrix[1][2] = 0.0;
  test_matrix_2.matrix[2][0] = 3.0;
  test_matrix_2.matrix[2][1] = 4.0;
  test_matrix_2.matrix[2][2] = 1.0;

  test_matrix_3.matrix[0][0] = 0.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = -2.0;
  test_matrix_3.matrix[1][1] = 4.0;
  test_matrix_3.matrix[1][2] = 5.0;
  test_matrix_3.matrix[2][0] = -3.0;
  test_matrix_3.matrix[2][1] = -4.0;
  test_matrix_3.matrix[2][2] = 5.0;

  int sum_return_value =
      s21_sub_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_4);
  int return_value = s21_eq_matrix(&test_matrix_4, &test_matrix_3);
  ck_assert_int_eq(return_value, SUCCESS);
  ck_assert_int_eq(sum_return_value, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);
  s21_create_matrix(2, 2, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  test_matrix_2.matrix[0][0] = 1.0;
  test_matrix_2.matrix[0][1] = 0.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 0.0;

  int sum_return_value =
      s21_sub_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(sum_return_value, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_number_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  double num = 2.0;
  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 2.0;
  test_matrix_2.matrix[0][1] = 4.0;
  test_matrix_2.matrix[1][0] = 6.0;
  test_matrix_2.matrix[1][1] = 8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);
  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  double num = -2.0;
  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = -2.0;
  test_matrix_2.matrix[0][1] = -4.0;
  test_matrix_2.matrix[1][0] = -6.0;
  test_matrix_2.matrix[1][1] = -8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);
  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_number_3) {
  matrix_t test_matrix_1 = {NULL, 0, 0};
  matrix_t test_matrix_2;
  matrix_t test_matrix_3 = {NULL, 0, 0};
  double num = 2.0;
  s21_create_matrix(2, 2, &test_matrix_2);

  test_matrix_2.matrix[0][0] = -2.0;
  test_matrix_2.matrix[0][1] = -4.0;
  test_matrix_2.matrix[1][0] = -6.0;
  test_matrix_2.matrix[1][1] = -8.0;

  int mult_num_return_value =
      s21_mult_number(&test_matrix_1, num, &test_matrix_3);

  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_2);
  ck_assert_int_eq(mult_num_return_value, ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[2][0] = 0.0;
  test_matrix_1.matrix[2][1] = 0.0;
  test_matrix_1.matrix[2][2] = 6.0;

  int sum_return_value = s21_sub_matrix(&test_matrix_1, NULL, &test_matrix_3);
  ck_assert_int_eq(sum_return_value, ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(mult_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  matrix_t test_matrix_4;

  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(2, 2, &test_matrix_2);
  s21_create_matrix(2, 2, &test_matrix_4);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);

  int eq = s21_eq_matrix(&test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t *test_matrix_3 = NULL;
  matrix_t test_matrix_4;

  s21_create_matrix(2, 2, &test_matrix_1);
  s21_create_matrix(4, 4, &test_matrix_2);
  s21_create_matrix(4, 4, &test_matrix_4);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[1][0] = 3.0;
  test_matrix_1.matrix[1][1] = 4.0;

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(&test_matrix_1, &test_matrix_2, test_matrix_3);

  int eq = s21_eq_matrix(test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, CALC_ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t *test_matrix_1 = NULL;
  matrix_t test_matrix_2;
  matrix_t *test_matrix_3 = NULL;
  matrix_t test_matrix_4;

  s21_create_matrix(4, 4, &test_matrix_2);
  s21_create_matrix(4, 4, &test_matrix_4);

  test_matrix_2.matrix[0][0] = 4.0;
  test_matrix_2.matrix[0][1] = 3.0;
  test_matrix_2.matrix[1][0] = 2.0;
  test_matrix_2.matrix[1][1] = 1.0;

  test_matrix_4.matrix[0][0] = 8.0;
  test_matrix_4.matrix[0][1] = 5.0;
  test_matrix_4.matrix[1][0] = 20.0;
  test_matrix_4.matrix[1][1] = 13.0;

  int res = s21_mult_matrix(test_matrix_1, &test_matrix_2, test_matrix_3);

  int eq = s21_eq_matrix(test_matrix_3, &test_matrix_4);
  ck_assert_int_eq(res, ERROR);
  ck_assert_int_eq(eq, FAILURE);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(transpose_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 2, &test_matrix_1);
  s21_create_matrix(2, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[2][0] = 3.0;
  test_matrix_1.matrix[2][1] = 6.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = 5.0;
  test_matrix_3.matrix[1][2] = 6.0;

  s21_transpose(&test_matrix_1, &test_matrix_2);
  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 2, &test_matrix_1);
  s21_create_matrix(2, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[2][0] = 3.0;
  test_matrix_1.matrix[2][1] = 6.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = 2.0;
  test_matrix_3.matrix[0][2] = 3.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = 5.0;
  test_matrix_3.matrix[1][2] = 6.0;

  int res = s21_transpose(NULL, &test_matrix_2);
  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(calc_complements_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 0.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 2.0;
  test_matrix_1.matrix[2][0] = 5.0;
  test_matrix_1.matrix[2][1] = 2.0;
  test_matrix_1.matrix[2][2] = 1.0;

  test_matrix_3.matrix[0][0] = 0.0;
  test_matrix_3.matrix[0][1] = 10.0;
  test_matrix_3.matrix[0][2] = -20.0;
  test_matrix_3.matrix[1][0] = 4.0;
  test_matrix_3.matrix[1][1] = -14.0;
  test_matrix_3.matrix[1][2] = 8.0;
  test_matrix_3.matrix[2][0] = -8.0;
  test_matrix_3.matrix[2][1] = -2.0;
  test_matrix_3.matrix[2][2] = 4.0;

  int res = s21_calc_complements(&test_matrix_1, &test_matrix_2);
  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t *test_matrix_1 = NULL;
  matrix_t test_matrix_2;
  s21_create_matrix(3, 3, &test_matrix_2);

  int res = s21_calc_complements(test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(res, ERROR);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(determinant_1) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = 0.0;
  s21_create_matrix(3, 3, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 2.0;
  test_matrix_1.matrix[0][2] = 3.0;
  test_matrix_1.matrix[1][0] = 4.0;
  test_matrix_1.matrix[1][1] = 5.0;
  test_matrix_1.matrix[1][2] = 6.0;
  test_matrix_1.matrix[2][0] = 7.0;
  test_matrix_1.matrix[2][1] = 8.0;
  test_matrix_1.matrix[2][2] = 9.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = 89.0;
  s21_create_matrix(2, 2, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = -4.0;
  test_matrix_1.matrix[1][0] = 21.0;
  test_matrix_1.matrix[1][1] = 5.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = -666.0;
  s21_create_matrix(1, 1, &test_matrix_1);

  test_matrix_1.matrix[0][0] = -666.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t test_matrix_1;
  double test_num_1;
  s21_create_matrix(2, 1, &test_matrix_1);

  test_matrix_1.matrix[0][0] = -666.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t test_matrix_1;
  double test_num_1;
  double result_num = -191.0;
  s21_create_matrix(4, 4, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 1.0;
  test_matrix_1.matrix[0][1] = 4.0;
  test_matrix_1.matrix[0][2] = 5.0;
  test_matrix_1.matrix[0][3] = 6.0;
  test_matrix_1.matrix[1][0] = 4.0;
  test_matrix_1.matrix[1][1] = 1.0;
  test_matrix_1.matrix[1][2] = 5.0;
  test_matrix_1.matrix[1][3] = 2.0;
  test_matrix_1.matrix[2][0] = 1.0;
  test_matrix_1.matrix[2][1] = 2.0;
  test_matrix_1.matrix[2][2] = 4.0;
  test_matrix_1.matrix[2][3] = 5.0;
  test_matrix_1.matrix[3][0] = 3.0;
  test_matrix_1.matrix[3][1] = 7.0;
  test_matrix_1.matrix[3][2] = 1.0;
  test_matrix_1.matrix[3][3] = 6.0;

  int res = s21_determinant(&test_matrix_1, &test_num_1);

  ck_assert_double_eq(test_num_1, result_num);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  matrix_t test_matrix_3;
  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_3);

  test_matrix_1.matrix[0][0] = 2.0;
  test_matrix_1.matrix[0][1] = 5.0;
  test_matrix_1.matrix[0][2] = 7.0;
  test_matrix_1.matrix[1][0] = 6.0;
  test_matrix_1.matrix[1][1] = 3.0;
  test_matrix_1.matrix[1][2] = 4.0;
  test_matrix_1.matrix[2][0] = 5.0;
  test_matrix_1.matrix[2][1] = -2.0;
  test_matrix_1.matrix[2][2] = -3.0;

  test_matrix_3.matrix[0][0] = 1.0;
  test_matrix_3.matrix[0][1] = -1.0;
  test_matrix_3.matrix[0][2] = 1.0;
  test_matrix_3.matrix[1][0] = -38.0;
  test_matrix_3.matrix[1][1] = 41.0;
  test_matrix_3.matrix[1][2] = -34.0;
  test_matrix_3.matrix[2][0] = 27.0;
  test_matrix_3.matrix[2][1] = -29.0;
  test_matrix_3.matrix[2][2] = 24.0;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  int eq = s21_eq_matrix(&test_matrix_2, &test_matrix_3);
  ck_assert_int_eq(eq, SUCCESS);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t test_matrix_1 = {NULL, 0, 0};
  matrix_t test_matrix_2;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t test_matrix_1;
  matrix_t test_matrix_2;
  s21_create_matrix(3, 3, &test_matrix_1);

  test_matrix_1.matrix[0][0] = 5.0;
  test_matrix_1.matrix[0][1] = 3.0;
  test_matrix_1.matrix[0][2] = 1.0;
  test_matrix_1.matrix[1][0] = 2.0;
  test_matrix_1.matrix[1][1] = 4.0;
  test_matrix_1.matrix[1][2] = 6.0;
  test_matrix_1.matrix[2][0] = -1.0;
  test_matrix_1.matrix[2][1] = -2.0;
  test_matrix_1.matrix[2][2] = -3.0;

  int res = s21_inverse_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(res, CALC_ERROR);
  s21_remove_matrix(&test_matrix_1);
}
END_TEST

Suite *suite_create_matrix() {
  Suite *s = suite_create("suite_create_matrix");
  TCase *tc1 = tcase_create("tc_create_matrix");
  TCase *tc2 = tcase_create("tc_create_error_matrix");

  tcase_add_test(tc1, test_create_1);
  tcase_add_test(tc1, test_create_2);
  tcase_add_test(tc1, test_create_3);

  tcase_add_test(tc2, test_create_4);
  tcase_add_test(tc2, test_create_5);
  tcase_add_test(tc2, test_create_6);
  tcase_add_test(tc2, test_create_7);
  tcase_add_test(tc2, test_create_8);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);

  return s;
}

Suite *suite_remove_matrix() {
  Suite *s = suite_create("suite_remove_matrix");
  TCase *tc = tcase_create("tc_remove_matrix");

  tcase_add_test(tc, test_remove_1);
  tcase_add_test(tc, test_remove_2);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_equal_matrix() {
  Suite *s = suite_create("suite_equal_matrix");
  TCase *tc1 = tcase_create("tc_iseq_matrix");
  TCase *tc2 = tcase_create("tc_isnoteq_matrix");
  TCase *tc3 = tcase_create("tc_null_matrix");

  tcase_add_test(tc1, test_eq_1x1_1);
  tcase_add_test(tc1, test_eq_1x1_2);
  tcase_add_test(tc1, test_eq_1x1_3);
  tcase_add_test(tc1, test_eq_1x1_4);
  tcase_add_test(tc1, test_eq_1x1_5);
  tcase_add_test(tc1, test_eq_2x2_1);
  tcase_add_test(tc1, test_eq_2x2_2);
  tcase_add_test(tc1, test_eq_2x2_3);
  tcase_add_test(tc1, test_eq_3x3_1);
  tcase_add_test(tc1, test_eq_3x3_2);

  tcase_add_test(tc2, test_noteq_1x1_1);
  tcase_add_test(tc2, test_noteq_1x1_2);
  tcase_add_test(tc2, test_noteq_1x1_3);
  tcase_add_test(tc2, test_noteq_1x1_4);
  tcase_add_test(tc2, test_noteq_2x2_1);
  tcase_add_test(tc2, test_noteq_2x2_2);
  tcase_add_test(tc2, test_noteq_3x3_1);
  tcase_add_test(tc2, test_noteq_3x3_2);

  tcase_add_test(tc3, test_err_eq_1);
  tcase_add_test(tc3, test_err_eq_2);
  tcase_add_test(tc3, test_err_eq_3);
  tcase_add_test(tc3, test_err_eq_4);
  tcase_add_test(tc3, test_err_eq_5);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);
  suite_add_tcase(s, tc3);

  return s;
}

Suite *suite_sum_matrix() {
  Suite *s = suite_create("suite_sum_matrix");
  TCase *tc1 = tcase_create("tc_sum_matrix");
  TCase *tc2 = tcase_create("tc_sum_err_matrix");
  TCase *tc3 = tcase_create("tc_sum_calc_err_matrix");

  tcase_add_test(tc1, test_sum_1);
  tcase_add_test(tc1, test_sum_2);
  tcase_add_test(tc1, test_sum_3);
  tcase_add_test(tc1, test_sum_4);

  tcase_add_test(tc2, test_sum_err_1);
  tcase_add_test(tc2, test_sum_err_2);
  tcase_add_test(tc2, test_sum_err_3);

  tcase_add_test(tc3, test_sum_calc_err_1);
  tcase_add_test(tc3, test_sum_calc_err_2);
  tcase_add_test(tc3, test_sum_calc_err_3);

  suite_add_tcase(s, tc1);
  suite_add_tcase(s, tc2);
  suite_add_tcase(s, tc3);

  return s;
}

Suite *suite_sub_matrix() {
  Suite *s = suite_create("suite_sub_matrix");
  TCase *tc = tcase_create("tc_sub_matrix");

  tcase_add_test(tc, sub_matrix_1);
  tcase_add_test(tc, sub_matrix_2);
  tcase_add_test(tc, sub_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_mult_number_matrix() {
  Suite *s = suite_create("suite_mult_number_matrix");
  TCase *tc = tcase_create("tc_mult_number_matrix");

  tcase_add_test(tc, mult_number_1);
  tcase_add_test(tc, mult_number_2);
  tcase_add_test(tc, mult_number_3);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_mult_matrix() {
  Suite *s = suite_create("suite_mult_matrix");
  TCase *tc = tcase_create("tc_mult_matrix");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_transpose_matrix() {
  Suite *s = suite_create("suite_transpose_matrix");
  TCase *tc = tcase_create("tc_transpose_matrix");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_calc_complements_matrix() {
  Suite *s = suite_create("suite_calc_complements_matrix");
  TCase *tc = tcase_create("tc_calc_complements_matrix");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_determinant_matrix() {
  Suite *s = suite_create("suite_determinant_matrix");
  TCase *tc = tcase_create("tc_determinant_matrix");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);

  suite_add_tcase(s, tc);

  return s;
}

Suite *suite_inverse_matrix() {
  Suite *s = suite_create("suite_inverse_matrix");
  TCase *tc = tcase_create("tc_inverse_matrix");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}

int main() {
  Suite *s_create = suite_create_matrix();
  Suite *s_remove = suite_remove_matrix();
  Suite *s_equal = suite_equal_matrix();
  Suite *s_sum = suite_sum_matrix();
  Suite *s_sub = suite_sub_matrix();
  Suite *s_mult_number = suite_mult_number_matrix();
  Suite *s_mult_matrix = suite_mult_matrix();
  Suite *s_transpose = suite_transpose_matrix();
  Suite *s_calc_complements = suite_calc_complements_matrix();
  Suite *s_determinant = suite_determinant_matrix();
  Suite *s_inverse = suite_inverse_matrix();

  run_test(s_create);
  run_test(s_remove);
  run_test(s_equal);
  run_test(s_sum);
  run_test(s_sub);
  run_test(s_mult_number);
  run_test(s_mult_matrix);
  run_test(s_transpose);
  run_test(s_calc_complements);
  run_test(s_determinant);
  run_test(s_inverse);

  return 0;
}
