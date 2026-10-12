#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // 1 задание
    float af = 100.0f;
    float bf = 0.001f;

    float ch1 = pow(af + bf, 4);
    float ch2 = pow(af, 4) + 4 * pow(af, 3) * bf;
    float chisl = ch1 - ch2;

    float znam = 6 * pow(af, 2) * pow(bf, 2) + 4 * af * pow(bf, 3) + pow(bf, 4);
    float res1 = chisl / znam;

    double ad = 100.0;
    double bd = 0.001;
    double d_ch1 = pow(ad + bd, 4);
    double d_ch2 = pow(ad, 4) + 4 * pow(ad, 3) * bd;
    double d_chisl = d_ch1 - d_ch2;
    double d_znam = 6 * pow(ad, 2) * pow(bd, 2) + 4 * ad * pow(bd, 3) + pow(bd, 4);
    double res2 = d_chisl / d_znam;
    cout << "float res = " << res1 << endl;
    cout << "double res = " << res2 << endl;
    // 2 задание
    int m = 10;
    int n = 5;

    int r1 = m - ++n;
    cout << "1) " << r1 << " m=" << m << " n=" << n << endl;

    bool r2 = ++m > --n;
    cout << "2) " << r2 << " m=" << m << " n=" << n << endl;

    bool r3 = --n < ++m;
    cout << "3) " << r3 << " m=" << m << " n=" << n << endl;

    return 0;
}
