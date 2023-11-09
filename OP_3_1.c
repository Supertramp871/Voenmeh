#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void input_array(int size, int* array)
{
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }
    
}

int delete_5_element(int size, int* array)
{
    /*Происходит удаление каждого пятого элемента из исходного массива.
    j используется для индексирования нового массива во время копирования элементов,
    пропуская каждый пятый элемент.*/
    for (int i = 0, j = 0; i < size; i++)
    {
        if ((i + 1) % 5 != 0)
        {
            array[j++] = array[i];
        }
    }

    return *array;
}

int output_array(int new_size, int* new_array)
{
    printf("Результат после удаления каждого пятого элемента:\n");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", new_array[i]);
    }
    
    return *new_array;
}

int main()
{
    char *locale = setlocale(LC_ALL, "");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    if(size<=0)
    {
        printf("Неккоректный размер массива\n");
        return 1;
    }

    int* array = (int*)malloc(size * sizeof(int)); // Выделение памяти для массива

    input_array(size, array);//Функция ввода массива

    int new_size = size - (size / 5); // Размер массива после удаления каждого пятого элемента

    delete_5_element(size, array);

    int* new_array = (int*)realloc(array, new_size * sizeof(int)); // Перевыделение памяти для нового размера массива

    output_array(new_size, new_array);
    printf("\n");

    free(new_array); // Освобождение памяти нового массива

    return 0;
}
