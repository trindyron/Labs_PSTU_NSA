#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Проверка: является ли слово корректным идентификатором
bool is_identifier(char s[]) {
    int len = strlen(s);
    if (len == 0) return false;

    // Первый символ: только буква или подчеркивание
    if (!isalpha(s[0]) && s[0] != '_') {
        return false;
    }

    // Остальные символы: буквы, цифры или подчеркивания
    for (int i = 1; i < len; i++) {
        if (!isalnum(s[i]) && s[i] != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    char str[256];
    char result[256] = "";
    char word[256];

    cout << "Vvedite stroku (s tochkoy na konce):\n";
    cin.getline(str, 256);

    int i = 0;
    while (str[i] != '\0' && str[i] != '.') {
        // Пропускаем пробелы
        while (str[i] == ' ') {
            i++;
        }

        if (str[i] == '\0' || str[i] == '.') break;

        // Считываем очередное слово
        int k = 0;
        while (str[i] != ' ' && str[i] != '.' && str[i] != '\0') {
            word[k] = str[i];
            k++;
            i++;
        }
        word[k] = '\0';

        // Если слово — идентификатор, добавляем его в результат
        if (is_identifier(word)) {
            if (strlen(result) > 0) {
                strcat(result, " ");
            }
            strcat(result, word);
        }
    }

    // Возвращаем точку в конец текста
    strcat(result, ".");

    cout << "\nRezultat:\n";
    cout << result << endl;

    return 0;
}
