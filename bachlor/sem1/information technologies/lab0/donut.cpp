#include <iostream>
#include <cstring>
#include <cmath>
#include <unistd.h>

using namespace std;

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    
    // Очистка экрана
    cout << "\x1b[2J";
    
    for(;;) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        
        for(j = 0; 6.28 > j; j += 0.07) {
            for(i = 0; 6.28 > i; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                
                if(22 > y && y >= 0 && x >= 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[n > 0 ? (int)(n * 8) : 0];
                }
            }
        }
        
        cout << "\x1b[H";
        for(k = 0; 1761 > k; k++) {
            putchar(k % 80 ? b[k] : '\n');
            A += 0.00004;
            B += 0.00002;
        }
        usleep(30000); //Задержка для анимации
    }
    return 0;
}
