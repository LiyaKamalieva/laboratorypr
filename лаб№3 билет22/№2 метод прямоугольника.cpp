#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>

using namespace std;

double f(double x)
{
    return exp(-2*x) * sin(22*x);
}

int main()
{
    double a = 0.0, b = 10.0; // Пределы интегрирования
    double h;
    int n_point = 1000000; // Количество точек
    double sum = 0.0;
    
    h = double((b-a)/n_point);
    
    for (int i = 1; i <= n_point; ++i)
    {
        sum += f(a + i * h - h/2);
    }
    sum *= h;
    
    cout << "Значение определенного интеграла: " << fixed << setprecision(9) << sum << endl;
    
    return 0;
}