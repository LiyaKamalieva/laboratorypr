#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

typedef double(*pointFunc)(double);

double f(double x) {
    return 1.0 / (x * x * x * x / (22 + x * x)); 
}

double simpson_integral(pointFunc f, double a, double b, int n) {
    const double h = (b-a)/n;
    double k1 = 0, k2 = 0;
    for(int i = 1; i < n; i += 2) {
        k1 += f(a + i*h);
        k2 += f(a + (i+1)*h);
    }
    return h/3*(f(a) + 4*k1 + 2*k2);
}

int main() {
    double a = 1, b = 2, eps = 1e-6; 
    double s1, s;
    int n = 1; 
    
    s1 = simpson_integral(f, a, b, n);
    
    do {
        s = s1;     
        n = 2 * n;  
        
        s1 = simpson_integral(f, a, b, n);
    } while (fabs(s1 - s) > eps);  
    
    cout << "Значение интеграла I = " << fixed << setprecision(12) << s1 << endl;
    cout << "Количество разбиений n = " << n << endl;

    return 0;
}