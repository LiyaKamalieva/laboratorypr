#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return pow(M_E, x) * x - x - 1;//pow(M_E, x) вычисляет значение числа e (основание натурального логарифма) в степени x
}

double dfunc(double x)
{
    return pow(M_E, x) * (x + 1);
}

double find(double x, double eps)
{
    double f, df; 
    int iter = 0;
    cout << "x_0 = " << x << " ";
    do {
        f = func(x);
        df = dfunc(x);
        x = x - f / df;
        iter++;
    } while (fabs(f) > eps && iter < 20000);
    cout << "\nNumber of iterations is " << iter << endl;
    return x;
}

int main()
{
    double x0 = 0.0, x, eps = 1e-6;
    x = find(x0, eps);
    cout << "Root x = " << fixed << setprecision(16) << x;
    cout << "\nFunction value f(x) = " << func(x) << endl;

    return 0;
}