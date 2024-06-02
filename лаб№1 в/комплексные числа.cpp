#include <iostream> 
#include <complex>

using namespace std;

int main() { 
complex<double> z1(2.0, 1.0); //комплексное число, составленное из двуух элементов типа double (действительной и мнимой части)
complex<double> z2(2.0, -2.0);

cout << "z1 = 2 + i  " << endl;
cout << "z2 = 2 - 2i  " << endl;
 
complex<double> sum = z1 + z2;
cout << "Sum: " << sum << endl;

complex<double> diff = z1 - z2;
cout << "Difference: " << diff << endl;

complex<double> prod = z1 * z2;
cout << "Product: " << prod << endl;

complex<double> div = z1 / z2;
cout << "Division: " << div << endl;

return 0;
}