#include <stdio.h>
#include <time.h>
#include <ctype.h>

// 4 dígitos del 0 - 9
// 10^4 o 10*10*10*10 = 10,000 10k combinaciones
//4 dígitos del 0 - 9 y en minúsculas de ascii
// 36^4 o 36*36*36*36 = 1,679,616 combinaciones
// 4 dígitos del 0 - 9 y en minúsculas y mayúsculas de ascii
// 62^4 o 62*62*62*62 = 14,776,336 combinaciones
// 8 dígitos del 0 - 9 y en minúsculas y mayúsculas de ascii
// 62^8 o 62*62*62*62*62*62*62*62 = 92,236,816 combinaciones

int main() {
    char digits[] = "0123456789";
    char ascii_lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char ascii_uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char punctuation[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    
    char characters[100];
    sprintf(characters, "%s%s%s%s", digits, ascii_lowercase, ascii_uppercase, punctuation);
    
    clock_t start = clock(); // Tiempo de inicio

    for (int i = 0; characters[i] != '\0'; i++) {
        for (int j = 0; characters[j] != '\0'; j++) {
            for (int k = 0; characters[k] != '\0'; k++) {
                for (int l = 0; characters[l] != '\0'; l++) {
                    printf("%c%c%c%c\n", characters[i], characters[j], characters[k], characters[l]);
                }
            }
        }
    }

    clock_t end = clock(); // Tiempo de fin
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\n\n El tiempo fue: %f segundos\n", time_spent);

    return 0;
}

