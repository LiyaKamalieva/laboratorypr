#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
    return -pow(y, 2) - 1/pow(x, 4);
}

void improvedEuler(double x0, double y0, double h, double x_end) {
    double x = x0;
    double y = y0;
    double y_exact;

    while (x <= x_end) {
        y_exact = -(x - tan((-1 + x)/x)/(x*x));
        double y_temp = y + h*f(x, y);
        y += h*(f(x, y) + f(x + h, y_temp))/2;
        
        cout << "x=" << x << " y_exact=" << y_exact << " y=" << y << " abs_error=" << abs(y - y_exact) << endl;

        x += h;
    }
}

int main() {
    double x0 = 1;
    double y0 = 1;
    double h = 0.1;
    double x_end = 2;

    improvedEuler(x0, y0, h, x_end);

    return 0;
}