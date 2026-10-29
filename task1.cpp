#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main() {
    double x, y, u;
    cout << "Input x and y: ";
    if (!(cin >> x >> y)) {
        cout << "Invalid input." << endl;
        return 1;
    }

    // Перевірка належності точки (x, y) кожній з фігур області D
    bool in_ellipse = (pow(x - 3.0, 2) / 4.0 + pow(y - 1.0, 2) <= 1.0);
    bool in_circle1 = (pow(x - 2.0, 2) + pow(y + 1.0, 2) <= 1.0);
    bool in_circle2 = (pow(x - 4.0, 2) + pow(y + 1.0, 2) <= 1.0);

    bool in_sq_top_left  = (x >= 1.0 && x <= 2.0 && y >= 2.0 && y <= 3.0);
    bool in_sq_top_right = (x >= 4.0 && x <= 5.0 && y >= 2.0 && y <= 3.0);
    bool in_sq_mid_left  = (x >= 0.0 && x <= 1.0 && y >= 1.0 && y <= 2.0);
    bool in_sq_mid_right = (x >= 5.0 && x <= 6.0 && y >= 1.0 && y <= 2.0);
    bool in_sq_bot_left  = (x >= 0.0 && x <= 1.0 && y >= -2.0 && y <= -1.0);
    bool in_sq_bot_right = (x >= 5.0 && x <= 6.0 && y >= -2.0 && y <= -1.0);
    bool in_rect_bottom  = (x >= 2.0 && x <= 4.0 && y >= -3.0 && y <= -2.0);

    bool in_D = in_ellipse || in_circle1 || in_circle2 ||
                in_sq_top_left || in_sq_top_right ||
                in_sq_mid_left || in_sq_mid_right ||
                in_sq_bot_left || in_sq_bot_right || in_rect_bottom;

    if (in_D) {
        cout << "YES: ";
        u = x * x * y - sqrt(fabs(y));
    } else {
        cout << "NO: ";
        u = y * y * x - sqrt(fabs(x));
    }

    // Перевірка на переповнення або некоректне значення
    if (isnan(u) || isinf(u) || fabs(u) > DBL_MAX) {
        cout << "x=" << x << " y=" << y << ". It is impossible to calculate u." << endl;
    } else {
        cout << "x=" << x << " y=" << y << " u=" << u << endl;
    }

    return 0;
}