//дано уравнение параболы и точка на плоскости где параметры параболы и координаты точки определены случайным образом. исследовать вопрос принадлежит ли точка переболею найти координату фокуса параболы, найти расстояние от директрисы параболы до ее фокуса
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

struct Point {
    double x, y;
};

struct Parabola {
    double a, b, c;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-10.0, 10.0);

    Point point = {dis(gen), dis(gen)};
    Parabola parabola = {dis(gen), dis(gen), dis(gen)};

    cout << "Point coordinates: (" << point.x << ", " << point.y << ")" << endl;
    cout << "Parabola equation: y = " << parabola.a << "x^2 + " << parabola.b << "x + " << parabola.c << endl;

    
    double y = parabola.a * pow(point.x, 2) + parabola.b * point.x + parabola.c;
    if (y == point.y) {
        cout << "The point belongs to the parabola." << endl;
    } else {
        cout << "The point does not belong to the parabola." << endl;
    }

    
    double focus_x = -parabola.b / (2 * parabola.a);
    double focus_y = parabola.a * pow(focus_x, 2) + parabola.b * focus_x + parabola.c;
    Point focus = {focus_x, focus_y};
    cout << "Focus coordinates: (" << focus_x << ", " << focus_y << ")" << endl;

    
    double p = 1 / (4 * parabola.a);
    double distance_to_focus = abs(p - focus_x);
    cout << "Distance from the directrix to the focus: " << distance_to_focus << endl;

    return 0;
}
