#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

// Функция для вычисления определенного интеграла методом суммирования
double Integral(double *f, double step, int n) {
  int i;
  double sum = 0;
  sum = 0.5 * (f[0] + f[n-1]);
  for (i = 1; i < n-1; i++) 
    sum += f[i];
  sum *= step;
  return sum;
}

int main() {
  setlocale(LC_ALL, "rus");
  double *f;
  double step, x;
  double sum=0.0;
  int i, n_point;
  
  n_point = 1000000; 
  double a = 0.0;
  f = (double*)malloc(n_point * sizeof(double));
  step = 0.000001; 
  
  
  x = 0.0;
  for (i = 0; i < n_point; i++) {
    f[i] = exp(-2*x) * sin(22*x);
    x += step;
  }

  sum = Integral(f, step, n_point); 
  cout << "Значение определенного интеграла: " << fixed << setprecision(6) << sum << endl;
  
  return 0;
}