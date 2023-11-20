//сортировка выбором и qsort
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 3

int compare(const void * x1, const void * x2)// Функция сравнения элементов массива
{
    return ( *(int*)x1 - *(int*)x2 );// если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int dec_to_oct_first_digit(int n)// Перевод числа из 10сс в 8сс и возращение первой цифры этого числа
{
    int d = 1, m = 0;
    for(; n != 0; n /= 8)
    {
        m += (n % 8) * d;
        d *= 10;
    }

    while (m >= 10) m/=10;

    return m;
}

int dec_to_oct_array(int *array, int size)// Перевод всех элементов массива из 10сс в 8сс и взятие первой цифры восьмиричной записи числа
{
    for (int i = 0; i < size; i++)
    {
        dec_to_oct_first_digit(array[i]);
    }

    return *array;
}
 
void swap_hex_matrix(int matrix[N][M])// Функция сортировки матрицы методом выбора
{
    int j,tmp,i, o,imax;

    // проход по строкам матрицы
    for (o = 0; o < N; o++)
    {
        // сортировка выбором
        for (i = M - 1; i > 0 ; i--)
        {
            imax = 0;
            for(j = 1; j <= i; j++)
            {
                // сравнение первых цифр в восьмиричной записи числа 
                if (dec_to_oct_first_digit(matrix[o][j]) > dec_to_oct_first_digit(matrix[o][imax]))
                    imax = j;
            }
            tmp = matrix[o][i];
            matrix[o][i] = matrix[o][imax];
            matrix[o][imax] = tmp;
        }
    }

    // вывод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%*d", 5, matrix[i][j]);
        }
        printf("\n");
    }

}

void qsort_hex_matrix(int matrix[N][M])// Сортировка матрицы с помощью qsort
{
    int hex_matrix[N][M]; // матрица хранящая первые цифры восьмеричной записи числа исходной матрицы
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            hex_matrix[i][j]= dec_to_oct_array(matrix[i], M);
        }
    }

    //проход по строкам матрицы и сортировка с помощью вспомогательной матрицы
    for (int i = 0; i < N; i++)
    {
        qsort((hex_matrix[i]), M, sizeof(int), compare);
    }


    // Вывод матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%*d", 5, matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int matrix[N][M] = 
    {
        {5,7,3},
        {3,4,8},
        {50,12,4},
        {56,5345,456}
    };

    printf("Исходная матрица\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%*d", 5, matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Матрица после сортировки выбором\n");
    swap_hex_matrix(matrix);

    printf("\n");

    printf("Матрица после qsort\n");
    qsort_hex_matrix(matrix);

    return 0;
}
