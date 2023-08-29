#include "s21_matrix.h"

void _find_minor(matrix_t *A, int rows, int columns, matrix_t *minor);

/**
 * @brief Функция создает матрицу
 * @return если функция вернула 0 - все хорошо, а иначе ошибка при создании
 *матрицы матрицы
 **/
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows < 1 || columns < 1) {
    flag = ERROR;
  } else {
    result->matrix = (double **)malloc(rows * columns * sizeof(double) +
                                       rows * sizeof(double *));
    if (result->matrix != NULL) {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = ptr + columns * i;
      }
      result->rows = rows;
      result->columns = columns;
    } else {
      flag = ERROR;
    }
  }
  return flag;
}

/**
 * @brief Функция очищает матрицу
 **/
void s21_remove_matrix(matrix_t *A) {
  A->rows = 0;
  A->columns = 0;
  free(A->matrix);
  A->matrix = NULL;
}

/**
 * @brief Функция сравнивае 2е матрицы и их эелементы
 * @return если функция вернула 1 - значит a == b, а иначе 0
 **/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows && flag == SUCCESS; i++) {
        for (int j = 0; j < A->columns && flag == SUCCESS; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
            flag = FAILURE;
          }
        }
      }
    } else {
      flag = FAILURE;
    }
  } else {
    flag = FAILURE;
  }
  return flag;
}

/**
 * @brief Функция сложение 2х матриц
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - сложение прошло успешно;
 **/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      if (s21_create_matrix(A->rows, A->columns, result) == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      } else {
        flag = ERROR;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция вычитание 2х матриц
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      if (s21_create_matrix(A->rows, A->columns, result) == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else {
        flag = ERROR;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция умножение чило на матрицу;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;
  if (A != NULL && A->matrix != NULL) {
    if (s21_create_matrix(A->rows, A->columns, result) == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = number * A->matrix[i][j];
        }
      }
    } else {
      flag = ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция умножение 2х матриц
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (A != NULL && B != NULL && A->matrix != NULL && B->matrix != NULL) {
    if (A->columns == B->rows) {
      if (s21_create_matrix(A->rows, B->columns, result) == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else {
        flag = ERROR;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция транспонирование матрицы, замена строк на столбцы;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A != NULL && A->matrix != NULL) {
    if (s21_create_matrix(A->columns, A->rows, result) == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      flag = ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция высчитывает матрицу миноров;
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A != NULL && A->matrix != NULL) {
    if (A->rows == A->columns) {
      int square = A->rows;
      if (s21_create_matrix(square, square, result) == 0) {
        for (int i = 0; i < square; i++) {
          for (int j = 0; j < square; j++) {
            matrix_t minor;
            if (s21_create_matrix(square - 1, square - 1, &minor) == 0) {
              _find_minor(A, i, j, &minor);
              double m_determinant = 0.0;
              s21_determinant(&minor, &m_determinant);
              result->matrix[i][j] = m_determinant * pow(-1, i + j);
              s21_remove_matrix(&minor);
            } else {
              flag = ERROR;
              break;
            }
          }
        }
      } else {
        flag = ERROR;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция определитель матрицы
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (A != NULL && A->matrix != NULL) {
    if (A->rows == A->columns) {
      int square = A->rows;
      if (square == 1) {
        *result = A->matrix[0][0];
      } else if (square == 2) {
        *result = (A->matrix[0][0] * A->matrix[1][1]) -
                  (A->matrix[1][0] * A->matrix[0][1]);
      } else {
        *result = 0.0;
        for (int j = 0; j < square; j++) {
          matrix_t minor;
          if (s21_create_matrix(square - 1, square - 1, &minor) == 0) {
            _find_minor(A, 0, j, &minor);
            double m_determinant = 0.0;
            s21_determinant(&minor, &m_determinant);
            *result += pow(-1, j) * A->matrix[0][j] * m_determinant;
            s21_remove_matrix(&minor);
          } else {
            flag = ERROR;
            break;
          }
        }
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Обратная матрица
 * @return если функция вернула 2 - ошибка вычисления;
 * @return если функция вернула 1 - ошибка;
 * @return если функция вернула 0 - вычитание прошло успешно;
 **/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (A != NULL && A->matrix != NULL) {
    if (A->rows == A->columns) {
      int square = A->rows;
      double determinant = 0.0;
      if (s21_determinant(A, &determinant) == OK && determinant != 0.0) {
        matrix_t complements;
        if (s21_calc_complements(A, &complements) == OK) {
          if (s21_transpose(&complements, result) == OK) {
            s21_remove_matrix(&complements);
            for (int i = 0; i < square; i++) {
              for (int j = 0; j < square; j++) {
                result->matrix[i][j] = result->matrix[i][j] / determinant;
              }
            }
          } else {
            flag = ERROR;
          }
        } else {
          flag = ERROR;
        }
      } else {
        flag = CALC_ERROR;
      }
    } else {
      flag = CALC_ERROR;
    }
  } else {
    flag = ERROR;
  }
  return flag;
}

/**
 * @brief Функция находит минор и записывает в структуру, где M-i,j;
 **/
void _find_minor(matrix_t *A, int rows, int columns, matrix_t *minor) {
  int m_rows = 0;
  int m_columns = 0;
  int square = A->rows;
  for (int i = 0; i < square; i++) {
    for (int j = 0; j < square; j++) {
      if (i != rows && j != columns) {
        minor->matrix[m_rows][m_columns] = A->matrix[i][j];
        if (m_columns != square - 2) {
          m_columns++;
        } else {
          m_columns = 0;
          m_rows++;
        }
      }
    }
  }
}