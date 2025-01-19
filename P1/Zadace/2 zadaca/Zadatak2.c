/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    char c;
    int broj_samoglasnika = 0;

    printf("Unosite znakove, na kraju unesite znak (*): ");

    while (scanf("%c", &c), ! (c == '*')) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            broj_samoglasnika++;
        }
    }
   
    printf("Broj unesenih samoglasnika je: %d\n", broj_samoglasnika);

    return 0;
}

