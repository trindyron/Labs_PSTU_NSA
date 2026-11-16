#include <iostream>

using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// Функция поиска минимального среди неповторяющихся элементов
void findMinUnique(int a[MAX_ROWS][MAX_COLS], int n, int m) {
    int min_val = 0;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current = a[i][j];
            int count = 0;

            // Считаем, сколько раз current встречается во всей матрице
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (a[r][c] == current) {
                        count++;
                    }
                }
            }

            // Если встретился только 1 раз (не повторяется)
            if (count == 1) {
                if (!found || current < min_val) {
                    min_val = current;
                    found = true;
                }
            }
        }
    }

    if (found) {
        cout << "Минимальный неповторяющийся элемент: " << min_val << endl;
    } else {
        cout << "Неповторяющихся элементов нет." << endl;
    }
}

int main() {
    int n, m;
    int a[MAX_ROWS][MAX_COLS];

    cout << "Введите количество строк и столбцов: ";
    cin >> n >> m;

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    findMinUnique(a, n, m);

    return 0;
}
