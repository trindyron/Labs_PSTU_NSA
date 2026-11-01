#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int A[n] = {8, 3, 15, 3, 9, 15, 15, 7, 3, 10};

    int min_val = A[0], max_val = A[0];
    int min_idx = 0, max_idx = 0;
    int min_cnt = 1, max_cnt = 1;

    for (int i = 1; i < n; i++) {
        // Проверка минимума
        if (A[i] < min_val) {
            min_val = A[i];
            min_idx = i;
            min_cnt = 1;
        } else if (A[i] == min_val) {
            min_cnt++;
        }

        // Проверка максимума
        if (A[i] > max_val) {
            max_val = A[i];
            max_idx = i;
            max_cnt = 1;
        } else if (A[i] == max_val) {
            max_cnt++;
        }
    }

    cout << "Min: " << min_val << ", индекс: " << min_idx 
         << ", номер: " << min_idx + 1 << ", кол-во: " << min_cnt << endl;
    cout << "Max: " << max_val << ", индекс: " << max_idx 
         << ", номер: " << max_idx + 1 << ", кол-во: " << max_cnt << endl;

    return 0;
}
