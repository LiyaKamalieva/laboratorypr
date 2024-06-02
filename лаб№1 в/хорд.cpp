#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return pow(M_E, x) * x - x - 1;
}

double find(double x0, double x1, double eps)
{
    int iter = 0;
    double x_next = 0;
    double tmp;

    do
    {
        tmp = x_next;
        x_next = x1 - func(x1) * (x0 - x1) / (func(x0) - func(x1));
        x0 = x1;
        x1 = tmp;
        iter++;
    } while (fabs(x_next - x1) > eps && iter < 20000);
    
    cout << "\nNumber of iterations is " << iter << ". " << endl;
    
    return x_next;
}

int main()
{
    double x0, x1, x, eps;
    cout << "a = ";
    cin >> x0;
    cout << "b = ";
    cin >> x1;
    eps = pow(10, -6);
    x = find(x0, x1, eps);
    cout << "Root x = " << fixed << setprecision(16) << x;
    cout << "\nFunction value f(x)=" << func(x) << endl;

    return 0;
}