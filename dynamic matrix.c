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

//Код хирьянова
#include <stdio.h>
// #include <stdlib.h>

// void dynamic_array_print(int **A, size_t N, size_t M)
// {
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; j < M; j++)
//         {
//             printf("%*d", 5, A[i][j]); //* и 5 ширина поля
//         }
//         printf("\n");
//     }
// }

// int ** dynamic_array_alloc(size_t N, size_t M)
// {
//     int **A = (int **)malloc(N*sizeof(int *));
//     for(int i = 0; i < N; i++)
//     {
//         A[i] = (int *)malloc(M*sizeof(int));
//     }
//     return A;
// }

// void dynamic_array_free(int **A, size_t N)
// {
//     for(int i = 0; i < N; i++)
//     {
//         free(A[i]);
//     }
//     free(A);
// }

// void dynamic_array_test(size_t N, size_t M)
// {
//     int **A = dynamic_array_alloc(N, M);
//     int x = 1;
//     for(int i = 0; i < N; i++)
//     {
//         for(int j = 0; j < M; j++)
//         {
//             A[i][j] = x;
//             x+=1;
//         }
//     }

//     dynamic_array_print(A, N, M);

//     /*memory investigation*/
//     printf("\n Pointers to lines: ");
//     for(int **p = A; p < A + 3; p++)
//         printf("10%ld ", (long int)*p);
    
//     printf("\n");

//     for(int *p = (int*)*A; p < (int*)*A + 32; p++)
//         printf("%*d ", 5, *p);

//     dynamic_array_free(A, N);
// }

// int main()
// {
//     int matrix_height = 4;
//     int matrix_width = 5;

//     dynamic_array_test(matrix_height, matrix_width);

//     return 0;
// }
