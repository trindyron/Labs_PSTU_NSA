#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    int n = 30;
    double eps = 0.0001;
    double step = (b - a) / k;

    cout << "x\tY(x)\tS(n)\tS(eps)\n";

    for (double x = a; x <= b + 0.0001; x += step) {
        // Точное значение
        double y = (x * x / 4.0 + x / 2.0 + 1.0) * exp(x / 2.0);

        // Пункт а) для заданного n
        double sn = 1.0;
        double term = 1.0;
        for (int i = 1; i <= n; i++) {
            term = term * (x / 2.0) / i;
            sn = sn + (i * i + 1.0) * term;
        }

        // Пункт б) по точности eps
        double se = 1.0;
        term = 1.0;
        int i = 1;
        while (true) {
            term = term * (x / 2.0) / i;
            double cur = (i * i + 1.0) * term;
            if (fabs(cur) < eps) {
                break;
            }
            se = se + cur;
            i++;
        }

        // Обычный вывод через табуляцию
        cout << x << "\t" << y << "\t" << sn << "\t" << se << "\n";
    }

   return 0;
}
