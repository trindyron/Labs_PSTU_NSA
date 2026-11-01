#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int matrix[3][4] = {
        {5, -12, 3, 10},
        {100, 4, -5, 0},
        {-2, 8, 15, 7}
    };

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            cout << setw(5) << matrix[i][j]; // выравнивание по правому краю
            sum += matrix[i][j];
        }
        cout << "  | Сумма: " << sum << endl;
    }

    return 0;
}
