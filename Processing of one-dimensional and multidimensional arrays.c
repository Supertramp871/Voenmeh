//5.1
//Угол между векторами A(n) и B(n)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int input_array_double(double* array, int size)
{
    int count = 0;
    printf("Введите координаты вектора:\n");
    for (int i = 0; i < size; i++)
    {
        printf("[%d] = ", i + 1);
        scanf("%lf", &array[i]);
        count++;
    }

    return count;
}

double sumv(double *A, double *B, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i] * B[i];
    return sum;
}
 
double GetAngle(double *A, double *B, int n)
{
    return (sumv(A, B, n) / (sqrt(sumv(A, A, n)) * sqrt(sumv(B, B, n))));
}

int main()
{
    char *locale = setlocale(LC_ALL, "");
    int size;
    printf("Введите размерность: ");
    scanf("%d", &size);

    double* A = (double*)malloc(size * sizeof(int));

    input_array_double(A, size);

    double* B = (double*)malloc(size * sizeof(int));

    input_array_double(B, size);

    double ans = GetAngle(A, B, size);
    printf("%lf\n", ans);

    return 0;
}

//5.2
//Дана квадратная матрица.
//Найти сумму элементов в тех столбцах, которые не содержат отрицательные элементы,
//и заменить этой суммой значение элемента, стоящего в этом же столбце на главной диагонали.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define SIZE 4 // Размер квадратной матрицы

int main() 
{
    int matrix[SIZE][SIZE]=
    {{0,-8,3,5},{0,0,2,6},{1,5,0,8},{6,0,2,0}};

    int a,b = 0;
    // Проходимся по столбцам матрицы
    for (int j = 0; j < SIZE; j++) 
    {   
        int sum = 0;//переменные для прохода по главной диагонали
        int flag = 0;//флаг для проверки есть ли отрицательные эл в столбце

        for (int i = 0; i < SIZE && !flag; i++)
            if(matrix[i][j] < 0)
                flag = 1;

        if (flag != 1)
        {
            for (int i = 0; i < SIZE; i++)
                sum += matrix[i][j];
            
            matrix[a][b] = sum;
            a++;
            b++;
        }
        else
        {
            a++;
            b++;
        }
    }



    // Выводим измененную матрицу
    printf("Измененная матрица:\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//5.3
//Поменять местами наибольшие по модулю элементы матрицы А (7х8) и массива В (76).
Если в массиве наибольшее по модулю значение встречается неоднократно, такой массив признается некорректным
#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 4
#define L 6

void swap_max_abs(int matrix[N][M], int array[], int rows, int cols, int size) 
{
    int *pmax;
    int flag;
    int max_index_array;
    int max_abs_matrix = 0;
    int max_abs_array = 0;

    // Находим наибольший по модулю элемент матрицы
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (abs(matrix[i][j]) > max_abs_matrix)
                max_abs_matrix = matrix[i][j];
        }
    }

    // Находим наибольший по модулю элемент массива
    for (int i = 0; i < size; i++) 
    {
        if (abs(array[i]) > max_abs_array)
        {
            max_abs_array = array[i];
            max_index_array = i;
        }
    }

    //Проверка что массив корректен
    pmax = array; flag = 1;
    for (int i = 1; i < L; i++)
	if (array[i] > *pmax)
	{
		pmax = &array[i];
		flag = 1;
	}
	else
		if (array[i] == *pmax)
			flag = 0;



    if(flag !=0)
    {
        //Замена в матрице
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (abs(matrix[i][j]) == max_abs_matrix)
                    matrix[i][j] = max_abs_array;
            }
        }

        //Замена в массиве
        array[max_index_array] = max_abs_matrix;

        printf("\nМатрица после замены:\n");
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                printf("%d ", matrix[i][j]);
            }
        printf("\n");
        }

        printf("\nМассив после замены:\n");
        for (int i = 0; i < L; i++) 
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
        printf("Неккоректный массив\n");

}

int main() 
{
    int matrix[N][M] =
    {
        {1,2,3,5},
        {5,5,3,2},
        {-5,4,3,2}
    };

    int array[L] = {0,2,3,4,8,100};

    printf("Матрица до замены:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
    printf("\n");
    }

    printf("\nМассив до замены:\n");
    for (int i = 0; i < L; i++) 
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    swap_max_abs(matrix, array, N, M, L);

    return 0;
}

//5.4
//В трехмерном массиве K (LxMxN), состоящем из нулей и единиц,
//хранится сеточное изображение некоторого трехмерного тела.
//Получить в двумерных массивах три проекции (тени) этого тела

#include <stdio.h>
#define L 3
#define M 3
#define N 3

void get_projections(int K[L][M][N], int projXY[M][N], int projXZ[L][N], int projYZ[L][M])
{
    // Проекция на плоскость XY
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int max = 0;
            for (int k = 0; k < L; k++)
            {
                if (K[k][i][j] > max)
                    max = K[k][i][j];
            }
            projXY[i][j] = max;
        }
    }

    // Проекция на плоскость XZ
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            int max = 0;
            for (int k = 0; k < M; k++) 
            {
                if (K[i][k][j] > max) 
                    max = K[i][k][j];
            }
            projXZ[i][j] = max;
        }
    }

    // Проекция на плоскость YZ
    for (int i = 0; i < L; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            int max = 0;
            for (int k = 0; k < N; k++) 
            {
                if (K[i][j][k] > max) 
                    max = K[i][j][k];
            }
            projYZ[i][j] = max;
        }
    }
}

int main() 
{
    int K[L][M][N] =
    {
    {{1, 0, 0}, {1, 1, 0}, {0, 0, 0}},
    {{1, 0, 0}, {1, 1, 0}, {0, 0, 0}},
    {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}}
    };

    int projXY[M][N];
    int projXZ[L][N];
    int projYZ[L][M];

    get_projections(K, projXY, projXZ, projYZ);

    printf("Проекция на плоскость XY:\n");
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
            printf("%d ", projXY[i][j]);
    printf("\n");
    }

    printf("\n");

    printf("Проекция на плоскость XZ:\n");
    for (int i = 0; i < L; i++) 
    {
        for (int j = 0; j < N; j++) 
            printf("%d ", projXZ[i][j]);
        printf("\n");
    }

    printf("\n");

    printf("Проекция на плоскость YZ:\n");
    for (int i = 0; i < L; i++) 
    {
        for (int j = 0; j < M; j++) 
            printf("%d ", projYZ[i][j]);
        printf("\n");
    }

    return 0;
}
