#include <iostream>
using namespace std;

int main() {
    const int n = 6;
    int A[n] = {2, 5, 8, 12, 19, 25}; 

    bool F = false;
    int i = 0;

    // Цикл идет, пока есть пары для сравнения И пока не найдено нарушение
    while (i < n - 1 && F == false) {
        if (A[i] >= A[i + 1]) {
            F = true; // нашли нарушение, поднимаем флаг
        } else {
            i++;
        }
    }

    if (F == false) {
        cout << "Массив упорядочен по возрастанию" << endl;
    } else {
        cout << "Массив НЕ упорядочен" << endl;
    }

    return 0;
}
