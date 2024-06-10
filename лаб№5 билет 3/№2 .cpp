#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


double y(double x) {
    return sin(x);
}


double lagrangeInterpolation(vector<double> x, vector<double> y, double xx) {
    double result = 0;
  
    for (int i = 0; i < x.size(); i++) {
        double term = y[i];
      
        for (int j = 0; j < x.size(); j++) {
            if (j != i) {
                term = term * (xx - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }
    
    return result;
}

int main() {
    vector<double> x = { 0, M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI };
    vector<double> y_vals;

    
    for (int i = 0; i < x.size(); i++) {
        y_vals.push_back(y(x[i]));
    }

    
    double x_star = 0.25 * M_PI;
    double lagrange_value = lagrangeInterpolation(x, y_vals, x_star);

    
    double delta = y(x_star) - lagrange_value;
  
    cout << "Значение интерполяционного многочлена в точке x* = 0.25π: " << lagrange_value << endl;
    cout << "Значение погрешности дельта(y(x*)): " << delta << endl;

    return 0;
}
