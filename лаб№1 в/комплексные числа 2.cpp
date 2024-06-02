#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    complex<double> z3(-1.0, 2.0);

    complex<double> z4 = pow(z3, 4); // возводим в четвертую степень
    cout << "z4 (z3 в 4 степени): " << z4 << endl;

    complex<double> z5 = pow(z3, 1.0/3.0); // извлекаем корень третьей степени
    cout << "z5 (корень из z3): " << z5 << endl;

    return 0;
}
