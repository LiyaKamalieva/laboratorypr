#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//a b интервал
double func(double x)
{
  return pow(M_E, x) * x - x - 1;
}

double find(double x, double eps)
{
  double x_1, x_2; 
  int iter = 0;
  x_2 = x;
  do {
    x_1 = x_2;
    x_2 = 1 + x_1 / pow(M_E, x_1);
    iter++;
  } while (fabs(x_2 - x_1) > eps && iter < 20);
  cout << "Number of iterations is " << iter << endl;
  return x_2;
}

int main() 
{ 
  double x0 = 1.5, eps = 1e-6, root;
  root = find(x0, eps);
  cout << "Root x = " << fixed << setprecision(16) << root << endl;
  cout << "Function value f(x) = " << func(root) << endl;

  return 0;
}