#include <iostream>
using namespace std;

int main() {
    int matrix[3][4] = 
    {
        {12, 45, 7, 3},
        {9, 88, 24, 15},
        {61, 0, -5, 42}
    };

    int max_val = matrix[0][0];
    int max_row = 0;
    int max_col = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "Максимум: " << max_val << endl;
    cout << "Индекс строки: " << max_row << ", индекс столбца: " << max_col << endl;

    return 0;
}
