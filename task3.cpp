#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, d, x, y, z;
    cout << "Input a, b, c, d: ";
    if (!(cin >> a >> b >> c >> d)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    double expr = a * a * (c + 1.0);
    int algorithm_num;

    // Вибір алгоритму обчислення x та y залежно від умови d < a^2(c + 1)
    if (d < expr) {
        algorithm_num = 1;
        x = sqrt(expr - d);
        y = b - c * sqrt(4.0 + exp(d));
    } else {
        algorithm_num = 2;
        // У випадку d >= a^2(c + 1) беремо корінь з (d - expr) зі знаком мінус,
        // щоб x <= 0 та спрацювала друга гілка формули для z
        x = -sqrt(d - expr);
        y = b - c * sqrt(4.0 + exp(d));
    }

    // Обчислення z
    if (x > 0) {
        z = y * x * x - 1.0 / x;
    } else {
        z = pow(y, 3) - pow(x, 4) + 1.0;
    }

    // Виведення результату у форматі, який вимагає умова
    cout << "Algorithm " << algorithm_num << ": z=" << z << endl;

    return 0;
}