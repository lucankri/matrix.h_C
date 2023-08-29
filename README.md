# s21_matrix

## Введение

В данном проекте реализована библиотека для обработки числовых матриц на языке программирования Си. Матрицы являются одной из базовых структур данных в программировании, например, они применяются для представления табличных значений, для вычислительных задач и нейронных сетей.


### Структура матрицы на языке C:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
```

## Основные операции над матрицами

Все операции (кроме сравнения матриц) возвращают результирующий код:  
- 0 - OK
- 1 - Ошибка, некорректная матрица   
- 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)

### Создание матриц (create_matrix)

```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Очистка матриц (remove_matrix)

```c
void s21_remove_matrix(matrix_t *A);
```

### Сравнение матриц (eq_matrix)
#### операция вовращает:
- 0 - FAILURE
- 1 - SUCCESS
```c
int s21_eq_matrix(matrix_t *A, matrix_t *B);
```

### Сложение (sum_matrix) и вычитание матриц (sub_matrix)

```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Умножение матрицы на число (mult_number). Умножение двух матриц (mult_matrix)

```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```

### Транспонирование матрицы (transpose)

```c
int s21_transpose(matrix_t *A, matrix_t *result);
```

### Минор матрицы и матрица алгебраических дополнений (calc_complements)

```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```

### Определитель матрицы (determinant)

```c
int s21_determinant(matrix_t *A, double *result);
```

### Обратная матрица (inverse_matrix)

```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```


### Для быстрой сборки библиотеки достаточно запустить Makefile команда:
- `make s21_matrix.a`
