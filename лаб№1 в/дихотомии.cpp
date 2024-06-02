#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
double func(double x)
{
    return pow(M_E, x) * x - x - 1;
}

int main()
{
    int iter = 0;
	double eps = 1e-6;
    double a = -2.0, b = 2.0, t, f1, f2, x; //начальные значения интервала

    do
    {
        f1 = func(a);
        t = (a + b) / 2.0;
        f2 = func(t);
        if (f1 * f2 <= 0) 
            b = t;
        else 
            a = t;
        iter++;
	} while (fabs(b - a) > eps);
    
    x = (a + b) / 2.0;
    f1 = func(x);

    if (fabs(f1) <= eps)
    {
        cout <<"\nThe root of the equation with error ";
	    cout << fixed << setprecision(16) <<"eps = "<< eps <<" is x = " << x; //задает количество знаков после запятой при выводе десятичных чисел
        cout <<"\nFunction value f(x) = "<< func(x) <<".";
        cout <<"\nNumber of iterations is "<< iter <<".";
    }
    else 
    {
        cout <<"On this segment the equation has no roots!!!";
    }

    return 0;
}