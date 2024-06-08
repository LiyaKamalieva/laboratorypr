#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<double>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<double> gauss(vector<vector<double>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Поиск строки с максимальным элементом
        int max_row = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(matrix[k][i]) > abs(matrix[max_row][i])) {
                max_row = k;
            }
        }

        swap(matrix[i], matrix[max_row]);

        // Приведение матрицы к треугольному виду
        for (int j = i + 1; j < n; j++) {
            double coef = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= coef * matrix[i][k];
            }
        }
    }

    // Обратный ход метода Гаусса
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; j--) {
            matrix[j][n] -= matrix[j][i] * solution[i];
        }
    }

    return solution;
}

int main() {
    vector<vector<double>> matrix = {
        {-7, -9, 1, -9, 29},
        {-6, -8, -5, 2, 42},
        {-3, 6, 5, -9, 11},
        {-2, 0, -5, -9, 75}
    };

    vector<double> solution = gauss(matrix);

    for (int i = 0; i < solution.size(); i++) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
