#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return ((3 * sin(sqrt(x))) + 0.35 * x - 3.8);
}

int main() {
    double a, b, e, x;
    int k;
    setlocale(LC_ALL, "Russian");
    a = 2; b = 3; e = 0.00001;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "e=" << e << endl;

    if (f(a) * f(b) < 0) {
        cout << "Условие сходимости выполнено" << endl;
        k = 0;
        while (1) {
            x = (a + b) / 2.0;
            k = k + 1;
            if (fabs(f(x)) < e) break;
            if (f(a) * f(x) < 0) {
                b = x; // Fix: Update b to x
            } else {
                a = x; // Fix: Update a to x
            }
        }
        cout << "Корень x=" << x << endl;
        cout << "Количество итераций k=" << k << endl;
    } else {
        cout << "Условие сходимости не выполнено" << endl;
    }

    return 0;
}

