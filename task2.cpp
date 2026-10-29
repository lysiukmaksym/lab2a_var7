#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main() {
    double h;
    cout << "Input real number h: ";
    if (!(cin >> h)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    // Контроль виходу за межі діапазону float (згідно з Додатком 1)
    if (fabs(h) > FLT_MAX || (fabs(h) > 0 && fabs(h) < FLT_MIN)) {
        cout << "Overflow or underflow of order. Task is unsolvable." << endl;
        return 1;
    }

    // Перевірка існування дійсного коефіцієнта b (підкореневий вираз 4 + tg(h) >= 0)
    double under_sqrt_b = 4.0 + tan(h);
    if (under_sqrt_b < 0.0 || isnan(under_sqrt_b) || isinf(under_sqrt_b)) {
        cout << "No real coefficient" << endl;
        return 0;
    }

    double a = sqrt( pow(sin(h + 1.0), 2) + 17.0 );
    double b = 10.0 - sqrt(under_sqrt_b);
    double c = a * h * cos(b * h) + b * h * sin(a * h);

    // Перевірка коефіцієнтів і дискримінанта на переповнення порядку
    double d = b * b - 4.0 * a * c;
    if (isinf(c) || isinf(d) || fabs(c) > FLT_MAX || fabs(d) > FLT_MAX) {
        cout << "Overflow of order during calculation. Task is unsolvable." << endl;
        return 1;
    }

    cout << "Coefficients: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Discriminant D = " << d << endl;

    const double EPS = 1e-7;
    if (d < -EPS) {
        cout << "No real roots" << endl;
    } else if (fabs(d) <= EPS) {
        double x = -b / (2.0 * a);
        cout << "One real root: x = " << x << endl;
    } else {
        double sqrt_d = sqrt(d);
        double x1 = (-b + sqrt_d) / (2.0 * a);
        double x2 = (-b - sqrt_d) / (2.0 * a);
        cout << "Two real roots: x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    return 0;
}