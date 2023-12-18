#include <stdio.h>
#include <math.h>

double Integral(double a, double b, int n, double (*f)(double), double* result)
{
    double h = (b - a) / n;
    *result = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; i++) 
        *result += f(a + i * h);
    *result *= h;

    return *result;
}



double function_1(double x)
{
    return (2*x)/(exp(2*x)); 
}

double function_2(double x)
{
    return sqrt(x*x + 1);
}

int main() 
{
    double a = -1; // Нижний предел интегрирования
    double b = 3; // Верхний предел интегрирования
    int n = 1000; // Количество разбиений
    double result;

    double integral_value1 = Integral(a, b, n, function_1, &result);
    printf("Значение первого интеграла: %f\n", result);


    a = -3; // Нижний предел интегрирования
    b = 2; // Верхний предел интегрирования

    double integral_value2 = Integral(a, b, n, function_2, &result);
    printf("Значение второго интеграла: %f\n", result);

    return 0;
}
