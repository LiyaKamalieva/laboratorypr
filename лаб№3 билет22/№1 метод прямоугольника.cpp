#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>

using namespace std;
 
double f(double x)
{
    return 1.0 / (x * x * x * x / (22 + x * x)); 
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    double a = 1, b = 2;
    int n_point = 1000000; 
    double h = double((b - a) / n_point);
    double sum = 0.0;
    
    for (double x = a; x <= b; x += h)
        sum += f(x - h / 2);
    sum *= h;
    
    cout << "Численное значение определенного интеграла с точностью до 10^(-6) равно: I=" << fixed << setprecision(12) << sum << endl;

    return 0;
}