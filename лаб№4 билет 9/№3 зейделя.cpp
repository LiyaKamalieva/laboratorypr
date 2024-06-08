#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a[4][4] = {
        {12, -3, -1, 3},
        {5, 20, 9, 1},
        {6, -3, -21, -7},
        {8, -7, 3, -27}
    };
    float d[4] = {-31, 90, 119, 71};
    float x[4] = {0};
    float b[4][4] = {0};
    float g[4] = {0};
    float x1[4] = {0};
    int k = 0;
    int y = 0;
    float z;
    float xk[4] = {0};
    float e = 0.01;

    for(int j = 0; j < 4; j++) {
        g[j] = d[j];
        x[j] = g[j];
        x1[j] = x[j];
        for(int i = 0; i < 4; i++) {
            if(i == j) b[j][i] = 1 - a[j][i];
            else b[j][i] = -a[j][i];
        }
    }

    do {
        y = 0;
        k++;
        cout << "Number of the iteration " << k << endl;
        for(int j = 0; j < 4; j++) {
            xk[j] = g[j];
            for(int i = 0; i < 4; i++) {
                xk[j] += b[j][i] * x1[i];
            }
            x1[j] = xk[j];
        }

        for(int j = 0; j < 4; j++) {
            z = fabs(xk[j] - x[j]);
            cout << "x[" << j << "]: " << x[j] << ", xk[" << j << "]: " << xk[j] << endl;
            cout << "|x[" << j << "] - xk[" << j << "]| = " << z << endl;
            x[j] = xk[j];
            if(z < e) {
                y++;
            }
        }
        cout << endl;
    } while(y != 4);

    cout << "Number of iterations: " << k << endl;

    cout << "Result with error 0.01:" << endl;
    for(int i = 0; i < 4; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}