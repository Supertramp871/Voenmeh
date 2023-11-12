#include <stdio.h>
#include <stdlib.h>

void input_matrix_int(int** matrix, int lines, int columns) 
{
    for (int i = 0; i < lines; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            printf("Введите элемент [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void output_matrix_int(int** matrix,int lines, int columns)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%*d", 5, matrix[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(void** matrix, int lines) 
{
    for (int i = 0; i < lines; i++)
    { 
        free(matrix[i]);
    }
    free(matrix);
}

void* allocate_matrix(int lines, int columns, size_t element_size)
{
    // Вычисляем общий размер матрицы
    size_t total_size = lines * columns * element_size;

    // Выделяем память для блока указателей
    void** matrix = (void**)malloc(lines * sizeof(void*)); //!!!!!!!!! Why void*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    if (matrix == NULL)
    {
    printf("Ошибка выделения памяти для блока указателей.\n");
    return NULL;
    }

    // Выделяем память для каждого блока данных
    for (int i = 0; i < lines; i++)
    {
        matrix[i] = malloc(columns * element_size);

        if (matrix[i] == NULL) 
        {
            printf("Ошибка выделения памяти для блока данных %d.\n", i);
            // Освобождаем ранее выделенную память
        for (int j = 0; j < i; j++) 
        {
            free(matrix[j]);
        }
        free(matrix);
        return NULL;
        }
    }

    // Возвращаем адрес начала блока указателей
    return (void*)matrix;
}



int main() 
{
    int lines, columns;
    size_t element_size;

    printf("Введите количество строк: ");
    scanf("%d", &lines);

    printf("Введите количество столбцов: ");
    scanf("%d", &columns);

    printf("Введите размер элемента в байтах: ");
    scanf("%zu", &element_size);

    void* matrix = allocate_matrix(lines, columns, element_size);
    if (matrix == NULL) 
    {
    printf("Ошибка выделения памяти для матрицы.\n");
    return 1;
    }

    printf("Адрес начала блока указателей: %p\n", matrix);

    // Вводим элементы матрицы
    input_matrix_int(matrix, lines, columns);

    // Выводим элементы матрицы
    output_matrix_int(matrix,lines,columns);

    // Освобождаем память матрицы
    free_matrix(matrix, lines);

    return 0;
}
