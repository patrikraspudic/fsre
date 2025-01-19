/*Patrik Raspudić 2233/RR*/
#include <stdio.h>

void obrada(char znakovi[50], char *znak, int *brojPon, int i);

int main() {
    char znakovi[50];
    int brojac = 0;
    int i = 0;
    char znak;
    int brojPon;

    do {
        scanf(" %c", &znakovi[i]);

        if (znakovi[i] == 'a' || znakovi[i] == 'e' || znakovi[i] == 'i' || znakovi[i] == 'o' || znakovi[i] == 'u' ||  znakovi[i] == 'A' || znakovi[i] == 'E' || znakovi[i] == 'I' || znakovi[i] == 'O' || znakovi[i] == 'U') 
		{
            brojac++;
        } 
		else 
		{
            brojac = 0;
        }

        i++;

    } while (brojac != 3);

    obrada(znakovi, &znak, &brojPon, i);

    printf("Najponavljaniji znak je: %c\n", znak);
    printf("Broj ponavljanja je: %d\n", brojPon);

    return 0;
}

void obrada(char znakovi[50], char *znak, int *brojPon, int i) {
    int maxFrekv = 1;

    for (int j = 0; j < i - 1; j++) {
        int trenutnaFrekv = 1;

        for (int k = j + 1; k < i; k++) {
            if (znakovi[j] == znakovi[k]) {
                trenutnaFrekv++;
            }
        }

        if (trenutnaFrekv > maxFrekv) {
            maxFrekv = trenutnaFrekv;
            *znak = znakovi[j];
            *brojPon = maxFrekv;
        }
    }
}
