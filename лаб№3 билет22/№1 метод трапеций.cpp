#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

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
  double a = 1, b = 2; 
  double step, x;
  double sum=0.0;
  int i, n_point;

  n_point = 100000; // Увеличиваем количество точек для получения нужной точности
  f = (double*)malloc(n_point * sizeof(double));
  step = (b-a) / n_point;
  
  x = a;
  for (i = 0; i < n_point; i++) {
    f[i] = 1.0 / (x * x * x * x / (22 + x * x));
    x += step;
  }

  sum = Integral(f, step, n_point);
  cout<<"Значение определенного интеграла I = "<<sum<<endl;

  return 0;
}