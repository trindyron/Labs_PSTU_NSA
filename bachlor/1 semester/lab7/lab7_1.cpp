#include <iostream>
using namespace std;

// Функция для массива целых чисел (количество четных)
int process(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Функция для строки (количество слов, начинающихся на 'а' или 'А')
int process(char str[]) {
    int count = 0;
    bool is_new_word = true;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            is_new_word = true;
        } else {
            if (is_new_word) {
                // Проверяем английскую и русскую 'а' (в зависимости от кодировки)
                if (str[i] == 'a' || str[i] == 'A' || str[i] == 'а' || str[i] == 'А') {
                    count++;
                }
                is_new_word = false;
            }
        }
    }
    return count;
}

int main() {
    int my_array[6] = {1, 2, 4, 7, 8, 10};
    char my_string[] = "apple orange апельсин банан";

    cout << "Четных элементов: " << process(my_array, 6) << endl;
    cout << "Слов на букву 'а': " << process(my_string) << endl;

    return 0;
}
