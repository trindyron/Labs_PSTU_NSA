#include <iostream>

using namespace std;

int main() {
    int a[] = {3, 5, 5, 1, 2, 3, 9, 8, 74, 2};
    int n = sizeof(a) / sizeof(a[0]);

    bool F = true;
    while (F) {
        int y = 0;
        F = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                y = a[i];
                a[i] = a[i + 1];
                a[i + 1] = y;
                F = true;
            }
        }
    }

    cout << "buble ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int b[] = {3, 5, 5, 1, 2, 3, 9, 8, 74, 2};
    for (int i = 0; i < n; i++) {
        int y = i;
        int minn = b[i];
        for (int j = i; j < n; j++) {
            if (b[j] <= minn) {
                minn = b[j];
                y = j;
            }
        }
        b[y] = b[i];
        b[i] = minn;
    }

    cout << "selection ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    int c[] = {3, 5, 5, 1, 2, 3, 9, 8, 74, 2};
    for (int i = 1; i < n; i++) {
        int j = i;
        int y = c[i];
        while (j > 0 && c[j - 1] > y) {
            c[j] = c[j - 1];
            j--;
        }
        c[j] = y;
    }

    cout << "insertion ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}
