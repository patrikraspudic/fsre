/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    char c;
    int broj_samoglasnika = 0;
    int broj_suglasnika = 0;
    int broj_unesenih_slova = 0;

    printf("Unesite 20 slova engleskog alfabeta: ");

    while (broj_unesenih_slova < 20) {
        scanf(" %c", &c);  

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            broj_unesenih_slova++;

            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                broj_samoglasnika++;
            } else {
                broj_suglasnika++;
            }
        }
    }

    printf("Broj unesenih samoglasnika je: %d\n", broj_samoglasnika);
    printf("Broj unesenih suglasnika je: %d\n", broj_suglasnika);

    return 0;
}
