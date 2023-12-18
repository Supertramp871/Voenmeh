#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int input_array_int(int* array, int size)
{
    int count = 0;
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = ", i + 1);
        scanf("%d", &array[i]);
        count++;
    }

    return count;
}

int input_array_double(double* array, int size)
{
    int count = 0;
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = ", i + 1);
        scanf("%lf", &array[i]);
        count++;
    }

    return count;
}

int output_array_int(int* array,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return *array;
}

int output_array_double(double* array,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", array[i]);
    }
    printf("\n");
    
    return *array;
}

int output_array_int_table(int* array, int size, int width)
{    
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        if ((i + 1) % width == 0)
        {
            printf("\n");
        }
    }

    printf("\n");

    return *array;
}

int output_array_double_table(double* array, int size, int width)
{    
    for (int i = 0; i < size; i++)
    {
        printf("%lf ", array[i]);
        if ((i + 1) % width == 0)
        {
            printf("\n");
        }
    }

    printf("\n");

    return *array;
}

int main()
{
    char *locale = setlocale(LC_ALL, "");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);

    int width;
    printf("Введите ширину стоблца ");
    scanf("%d", &width);
    
    int* array = (int*)malloc(size * sizeof(int));

    input_array_int(array, size);

    output_array_int_table(array, size, width);

    return 0;

}
