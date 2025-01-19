/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    int broj, prethodni_broj = 0, brojac = 0, max_broj = 0, max_brojac = 0;
    int brojac_vece_od_10 = 0;

    while (brojac_vece_od_10 < 4) {
        printf("Unesite broj: ");
        scanf("%d", &broj);

        if (broj > 10) {
            brojac_vece_od_10++;
        } else {
            brojac_vece_od_10 = 0;
        }

        if (broj == prethodni_broj) {
            brojac++;
        } else {
            brojac = 1;
            prethodni_broj = broj;
        }

        if (brojac > max_brojac) {
            max_brojac = brojac;
            max_broj = broj;
        }
    }

    printf("Broj koji je unesen najvise puta je: %d\n", max_broj);

    return 0;
}