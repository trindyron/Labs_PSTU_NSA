#include <iostream>
#include <vector>
#include <string>

using namespace std;

int total_disks;
vector<int> pegs[3];
int step = 0;

const string RESET = "\033[0m";
const string GRAY  = "\033[90m";

// Набор ANSI-цветов для дисков
const vector<string> DISK_COLORS = {
    "\033[31m", // Красный
    "\033[33m", // Жёлтый
    "\033[32m", // Зелёный
    "\033[36m", // Циан
    "\033[34m", // Синий
    "\033[35m", // Пурпурный
    "\033[91m", // Светло-красный
    "\033[92m"  // Светло-зелёный
};

string get_color(int disk_size) {
    return DISK_COLORS[(disk_size - 1) % DISK_COLORS.size()];
}

void print_towers() {
    int max_width = total_disks * 2 - 1;

    for (int lvl = total_disks - 1; lvl >= 0; --lvl) {
        for (int p = 0; p < 3; ++p) {
            int disk_size = (lvl < (int)pegs[p].size()) ? pegs[p][lvl] : 0;

            if (disk_size == 0) {
                int spaces = total_disks - 1;
                cout << string(spaces, ' ') 
                     << GRAY << "│" << RESET 
                     << string(spaces, ' ');
            } else {
                int disk_chars = disk_size * 2 - 1;
                int spaces = (max_width - disk_chars) / 2;
                
                cout << string(spaces, ' ') << get_color(disk_size);
                for (int i = 0; i < disk_chars; ++i) cout << "█";
                cout << RESET << string(spaces, ' ');
            }
            cout << "   ";
        }
        cout << "\n";
    }

    for (int p = 0; p < 3; ++p) {
        cout << GRAY << string(max_width, '═') << RESET << "   ";
    }
    cout << "\n";

    for (int p = 0; p < 3; ++p) {
        int spaces = total_disks - 1;
        cout << string(spaces, ' ') << (char)('A' + p) << string(spaces, ' ') << "   ";
    }
    cout << "\n\n";
}

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;

    hanoi(n - 1, from, aux, to);

    int disk = pegs[from].back();
    pegs[from].pop_back();
    pegs[to].push_back(disk);

    step++;
    cout << "Шаг " << step << ": Переместить диск " 
         << get_color(disk) << disk << RESET 
         << " со стержня " << (char)('A' + from) 
         << " на " << (char)('A' + to) << "\n\n";

    print_towers();

    hanoi(n - 1, aux, to, from);
}

int main() {
    cout << "Введите число слоёв (n): ";
    if (!(cin >> total_disks) || total_disks <= 0) return 0;

    for (int i = total_disks; i >= 1; --i) {
        pegs[0].push_back(i);
    }

    cout << "\nНачальное состояние:\n\n";
    print_towers();

    hanoi(total_disks, 0, 2, 1);

    return 0;
}

