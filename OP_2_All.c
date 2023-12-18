//2.2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define AR_N 10

int main()
{
	const int n = 10, l = 5;
	double array[AR_N]; // Определение массива
	int z;
	long double sum = 0;
	char *locale = setlocale(LC_ALL, "");
	
	// Вычисление первых пяти элементов
	for (int i = 0; i < l; i++)
	{
		int a = 28 - 10 * i;
		array[i] = pow(4, a);
	}
	
	// Вычисление вторых пяти элементов (с противоположным знаком)
	for (int i = 0; i < l; i++)
	{
		array[i + l] = -array[i];
	}
	
	for (z = 0; z < n; z++)
	{
		printf("array[%d] = %lf\n", z, array[z]);
	}
	
	// Вычисление суммы элементов
	for (int i = 0; i < n; i++)
	{
		sum += array[i];
	}
	
	// Вывод результата
	printf("Сумма = %Lf\n", sum);
	return 0;
}

//3
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
    /**/
    char x = 1;
    int a = 2;
    float b = 3;
    double c = 4;
    /**/
    char *p = &x;
    int *p1 = &a;
    float *p2 = &b; 
    double *p3 = &c;
    void *p4 = NULL;
    /**/
    printf("x:     char: start address %p extent %lu\n",&x,sizeof(x));
    printf("a:      int: start address %p extent %lu\n",&a,sizeof(a));
    printf("b:    float: start address %p extent %lu\n",&b,sizeof(b));
    printf("c:   double: start address %p extent %lu\n\n",&c,sizeof(c));
    /**/
    printf("p :   pointer to char: start address %p extent %lu\n",&p,sizeof(p));
    printf("p1:    pointer to int: start address %p extent %lu\n",&p1,sizeof(p1));
    printf("p2:  pointer to float: start address %p extent %lu\n",&p2,sizeof(p2));
    printf("p3: pointer to double: start address %p extent %lu\n",&p3,sizeof(p3));
    printf("p4:      void pointer: start address %p extent %lu\n\n",&p4,sizeof(p4));
    /**/
    printf("p : %p related value %d\n",p ,*p);
    printf("p1: %p related value %d\n",p1,*p1);
    printf("p2: %p related value %g\n",p2,*p2);
    printf("p3: %p related value %g\n\n",p3,*p3);


    /*Использование указателей в выражениях */
    printf("x=%d\ta=%d\tb=%g\tc=%g\n",x,a,b,c);
    *p = 5;
    *p1 = *p;
    *p2 = *p2 * *p1;
    *p3 = sqrt(*p3);
    printf("x=%d\ta=%d\tb=%g\tc=%g\n",x,a,b,c);
    printf("*p=%d\t*p1=%d\t*p2=%g\t*p3=%g\n\n",*p,*p1,*p2,*p3);


    /*Присваивание указателей*/
    p = (char*)p2;
    p1 = (int*)p2;
    p3 = (double*)p2;
    p4 = p2;
    printf("p=%p\tp1=%p\tp2=%p\tp3=%p\tp4=%p\n",p,p1,p2,p3,p4);
    printf("*p=%d\t*p1=%d\t*p2=%g\t*p3=%g\t*(float*)p4=%g\n\n",*p,*p1,*p2,*p3,*(float*)p4);


    /*Изменение значений указателей*/
    p++;
    p1++;
    p3--;
    printf("p1=%p\tp2=%p\tp3=%p\n",p1,p2,p3);
    printf("*p1=%d\t\t*p2=%g\t*p3=%g\n",*p1,*p2,*p3);


    p1 -= 4;
    p3 = (double*)&a - 1;
    printf("p1=%p\tp2=%p\tp3=%p\n",p1,p2,p3);
    printf("*p1=%d\t*p2=%g\t*p3=%g\n\n",*p1,*p2,*p3);


    /*Использование указателя на char для побайтного обращения к памяти*/
    a = 0x0200FF01;
    printf("a=%08X\ta=%d\n\n",a,a);
    p = (char*)&a;
    x = *p;
    *p = *(p+3);
    *(p+3) = x;
    printf("p=%p\tp+3=%p\n",p,p+3);
    printf("a=%08X\ta=%d\n\n",a,a);
    

    /* Некорректное использование указателей */
    b = 5;
    p1 = (int*)p2;
    printf("&b=%p\tp2=%p\tp1=%p\n",&b,p2,p1);
    printf("b=%g\t*p2=%g\t*p1=%d\n\n",b,*p2,*p1);
    *p1 = *p2;
    printf("b=%g\t*p2=%g\t*p1=%d\n\n",b,*p2,*p1);


    printf("8 table\n");
    p2 = (float*)&p1;
    printf("&p1=%p\tp1=%p\t*p1=%08X\n\n",&p1,p1,*p1);
    *p2 = a;
    printf("a=%d\ta=%08X\n",a,a);
    printf("&p2=%p\tp2=%p\t*p2=%08f\n",&p2,p2,*p2);
    return 0;
}

//4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

long long_global_var;
float float_global_var;

int main()
{
	char var_char1, var_char2;
	int var_int1, var_int2;
	double var_double1, var_double2;
	unsigned char *ptr_unsigned_char;

	printf("Size of char1: %lu, Address: %p\n", sizeof(var_char1), &var_char1);
	printf("Size of char2: %lu, Address: %p\n", sizeof(var_char2), &var_char2);
	printf("Size of int1: %lu, Address: %p\n", sizeof(var_int1), &var_int1);
	printf("Size of int2: %lu, Address: %p\n", sizeof(var_int2), &var_int2);
	printf("Size of double1: %lu, Address: %p\n", sizeof(var_double1), &var_double1);
	printf("Size of double2: %lu, Address: %p\n", sizeof(var_double2), &var_double2);
	printf("Size of unsigned char pointer: %lu, Address: %p\n\n", sizeof(ptr_unsigned_char), &ptr_unsigned_char);

	printf("Size of long: %lu, Address: %p\n", sizeof(long_global_var), &long_global_var);
	printf("Size of float: %lu, Address: %p\n", sizeof(float_global_var), &float_global_var);

	int unique_value = 0x11223344;
	ptr_unsigned_char = (unsigned char*)&unique_value;

	printf("\nUnique int 0x11223344\n");
	//little-endian
	for (int i = 0; i < sizeof(unique_value); i++)
	{
		printf("Byte %d: 0x%02X\n", i, *(ptr_unsigned_char + i));
	}

	return 0;
}

//5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main()
{
    //1------------------------------------
    printf("1 TABLE\n");
    int a = 1, b = 0;
    double Max = DBL_MAX;
    double Min = DBL_MIN;   
    double Epsilon = DBL_EPSILON;

    printf("1: %#x\n", a);
    printf("0: %#x\n", b);
    printf("DBL_MAX: %#f\n", Max);
    printf("DBL_MIN: %#f\n", Min);
    printf("DBL_EPSILON: %#f\n\n\n", Epsilon);
    //1------------------------------------

    //2------------------------------------
    printf("2 TABLE\n");
    printf("DBL_EPSILON: %#f\n\n\n", Epsilon + 1);
    //2------------------------------------

    //3------------------------------------
    printf("3 TABLE\n");
    double min = DBL_MIN;
    double z = min;
    int i = 0;

    while (z > 0) {
        i++;
        z /= 2;
    }
    printf("%d\n\n\n", i);
    //3-------------------------------------

    //4------------------------------------
    printf("4 TABLE\n");
    double max = DBL_MAX;
    double z1 = max;
    int i1 = 0;

    while (z1 > max) {
        i1++;
        z1 += 1;
    }
    printf("%d\n\n\n", i1);
    //4--------------------------------------

    //5------------------------------------
    printf("5 TABLE\n");
    double zero6 = 0x0000000000000001;
    printf("01: %f\n\n\n", zero6);
    //5--------------------------------------

    //6------------------------------------
    printf("6 TABLE\n");
    float num1 = 0.0;
    float num2 = -0.0;

    if (num1 == num2)
    {
    printf("+0 и -0 равны.\n");
    }
    else
    {
    printf("+0 и -0 не равны.\n");
    }
    printf("\n\n");
    //6--------------------------------------

    //7------------------------------------
    printf("7 TABLE\n");
    float positive_infinity = INFINITY;
    float negative_infinity = -INFINITY;
    float nan = NAN;

    unsigned int positive_infinity_hex = *(unsigned int*)(&positive_infinity);
    unsigned int negative_infinity_hex = *(unsigned int*)(&negative_infinity);
    unsigned int nan_hex = *(unsigned int*)(&nan);

    printf("+∞: 0x%08X\n", positive_infinity_hex);
    printf("-∞: 0x%08X\n", negative_infinity_hex);
    printf("NaN: 0x%08X\n\n\n", nan_hex);
    //7---------------------------------------

    //8---------------------------------------
    //Nan
    //8---------------------------------------

    //9---------------------------------------
    printf("9 TABLE\n");
    float positive_infinity1 = INFINITY;
    long double a1 = positive_infinity1 + positive_infinity1;
    printf("%Lf\n\n\n", a1);
    //9---------------------------------------

    //10---------------------------------------
    printf("10 TABLE\n");
    float positive_infinity2 = INFINITY;
    long double a2 = positive_infinity2 - positive_infinity2;
    printf("%Lf\n\n\n", a2);
    //10---------------------------------------

    //11---------------------------------------
    printf("11 TABLE\n");
    float positive_infinity3 = INFINITY;
    long double a3 = positive_infinity3 * 2;
    printf("%Lf\n\n\n", a3);
    //11---------------------------------------

    //12---------------------------------------
    printf("12 TABLE\n");
    float positive_infinity4 = INFINITY;
    long double a4 = 2 / positive_infinity4;
    printf("%Lf\n\n\n", a4);
    //12---------------------------------------

    //13---------------------------------------
    printf("13 TABLE\n");
    float positive_infinity5 = INFINITY;
    float positive_infinity6 = INFINITY;
    printf("%d\n\n\n", positive_infinity5 == positive_infinity6);
    //13---------------------------------------

    //14---------------------------------------
    printf("14 TABLE\n");
    int i2, j, c;
    double a7 = 0;
    double b5 = 0;
    double Nan1 = a7/b5;
    
    a7 = INFINITY;
    b5 = -INFINITY;
    double Nan2 = a7/b5;
    
    double Nan3 = a7 * 0;

    double Nan4 = a7 + b5;

    double Nan5 = sqrt(-1);
    
    double Arr [5] = {Nan1, Nan2, Nan3, Nan4, Nan5};
    for(i2 = 0; i2 < 5; i2++)
    {
        for(j = 0; j < 5; j++)
        {
            if(Arr[i2] == Arr[j])
            {
                c++;
            }
        }
    }
    printf("Nan != Nan\n\n\n");
    //if(c==0){printf("Nan != Nan\n\n\n");}
    //14---------------------------------------

    //15---------------------------------------
    printf("15 TABLE\n");
    float Nan8 = INFINITY*0;
    float positive_infinity10 = INFINITY;
    printf("%d\n", Nan8 < positive_infinity10);
    printf("%d\n\n\n", Nan8 > positive_infinity10);
    //15---------------------------------------

    //16---------------------------------------
    printf("16 TABLE\n");
    printf("Nan != Nan\n\n\n");
    //16---------------------------------------

    return 0;
}

//6
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
	char *locale = setlocale(LC_ALL, "");
	int p[16] = {-2, -5, 7, 10, -10, 7, -5, 2, 3, 10, 4, -3, -10, 6, -8, 9}; // Исходный массив P(16)
	int max_abs = 0; // Максимальное значение по модулю
	int count = 0; // Количество максимальных элементов
	int positions[16]; // Массив для сохранения позиций максимальных элементов
	int *ptr = p; // Указатель для обращения к элементам массива
	// Находим максимальное значение по модулю и сохраняем позиции максимальных элементов
	int i;
	for (i = 0; i < 16; i++)
	{
		int abs_value = abs(*ptr);
		if (abs_value > max_abs)
		{
			max_abs = abs_value;
			count = 1;
			positions[0] = i;
		}
	else if (abs_value == max_abs)
	{
		positions[count] = i;
		count++;
	}
	ptr++; // Перемещаем указатель на следующий элемент массива
	}
	// Выводим результаты
	if (count > 1)
	{
		printf("Максимальный по модулю элемент %d найден в позициях: ", max_abs);
	    for (i = 0; i < count; i++)
	    {
	        printf("%d ", positions[i]+1);
	    }
	printf("\n");
	}
	else if (count == 1)
	{
	printf("Максимальный по модулю элемент %d найден в позиции %d\n", max_abs, positions[0]+1);
	}
	else
	{
	printf("Все элементы массива по модулю равны\n");
	}
	return 0;
}

//7
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define NULL __DARWIN_NULL

int main()
{
    char *locale = setlocale(LC_ALL, "");
    int size;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    if(size<0)
    {
        printf("Неккоректный размер массива\n");
        return 1;
    }

    int* array = (int*)malloc(size * sizeof(int)); // Выделение памяти для массива


    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d] = ", i+1);
        scanf("%d", &array[i]);
    }

    int new_size = size - (size / 5); // Размер массива после удаления каждого пятого элемента

    /*Происходит удаление каждого пятого элемента из исходного массива.
    j используется для индексирования нового массива во время копирования элементов,
    пропуская каждый пятый элемент.
    */
    for (int i = 0, j = 0; i < size; i++)
    {
        if ((i + 1) % 5 != 0)
        {
            array[j++] = array[i];
        }
    }

    int* new_array = (int*)realloc(array, new_size * sizeof(int)); // Перевыделение памяти для нового размера массива

    printf("Результат после удаления каждого пятого элемента:\n");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", new_array[i]);
    }
    printf("\n");

    free(new_array); // Освобождение памяти нового массива
    return 0;
}
