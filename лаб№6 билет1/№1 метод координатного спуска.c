#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return x * x + 3 * y * y + cos(x + y);
}

double coordinateDescent(double x, double y, double step_size, double tolerance) {
    double dx = 1.0;
    double dy = 1.0;
    
    while (dx > tolerance || dy > tolerance) {
        double prev_x = x;
        double prev_y = y;
        
        // Первый шаг спуска по x
        x = x - step_size * (2 * x - sin(x + y));
        dx = abs(x - prev_x);
        
        // Второй шаг спуска по y
        y = y - step_size * (6 * y - sin(x + y));
        dy = abs(y - prev_y);
    }
    
    return f(x, y);
}

int main() {
    double initial_x = 0.0;
    double initial_y = 0.0;
    double step_size = 0.01;
    double tolerance = 0.0001;
    
    double optimal_value = coordinateDescent(initial_x, initial_y, step_size, tolerance);
    
    cout << "Optimal value of f(x) is: " << optimal_value << endl;
    
    return 0;
}

