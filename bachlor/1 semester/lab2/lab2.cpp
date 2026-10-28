#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double eps = 0.0001;
    double sum = 0.0;
    int n = 1;

    double an = exp(n) * pow(100.0, -n * n);

    while (fabs(an) >= eps) {
        sum += an;
        n++;
        an = exp(n) * pow(100.0, -n * n);
    }

    cout << "Сумма ряда:" << endl;
    cout << sum << endl;

    return 0;
}
