//19 билет даны три вектора на плоскости координаты которых определены случайным образом. найти их длины, найти попарно углы между ними, найти попарно сумму и разность векторов, выяснить вопрос о том, что есть ли параллельные среди них
#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x;
    double y;
};

double vectorLength(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double angleBetweenVectors(Vector v1, Vector v2) {
    return acos((v1.x * v2.x + v1.y * v2.y) / (vectorLength(v1) * vectorLength(v2)));
}

Vector sumOfVectors(Vector v1, Vector v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector diffOfVectors(Vector v1, Vector v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

bool areParallel(Vector v1, Vector v2) {
    if (vectorLength(v1) == 0 || vectorLength(v2) == 0) {
        return false;  // векторы не могут быть параллельны, если хотя бы один из них нулевой
    }
    
    
    double lengthV1 = vectorLength(v1);
    double lengthV2 = vectorLength(v2);
    Vector normV1 = {v1.x / lengthV1, v1.y / lengthV1};
    Vector normV2 = {v2.x / lengthV2, v2.y / lengthV2};

    
    return (normV1.x / normV2.x) == (normV1.y / normV2.y);
}

int main() {
    Vector v1 = {1.0, 2.0};
    Vector v2 = {3.0, 4.0};
    Vector v3 = {5.0, 6.0};

    cout << "Length of v1: " << vectorLength(v1) << endl;
    cout << "Length of v2: " << vectorLength(v2) << endl;
    cout << "Length of v3: " << vectorLength(v3) << endl;

    cout << "Angle between v1 and v2: " << angleBetweenVectors(v1, v2) << endl;
    cout << "Angle between v1 and v3: " << angleBetweenVectors(v1, v3) << endl;
    cout << "Angle between v2 and v3: " << angleBetweenVectors(v2, v3) << endl;

    Vector v1v2Sum = sumOfVectors(v1, v2);
    Vector v1v2Diff = diffOfVectors(v1, v2);
    
    if (areParallel(v1, v2)) {
        cout << "Vectors v1 and v2 are parallel." << endl;
    } else {
        cout << "Vectors v1 and v2 are not parallel." << endl;
    }
    
    cout << "Sum of vectors v1 and v2: (" << v1v2Sum.x << ", " << v1v2Sum.y << ")" << endl;
    cout << "Difference of vectors v1 and v2: (" << v1v2Diff.x << ", " << v1v2Diff.y << ")" << endl;

    

    return 0;
}
