/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    int broj, i, zbroj = 0;
    printf("Unesite prirodni broj: ");
    scanf("%d", &broj);

    for(i = 1; i <= broj; i++) {
        if(broj % i == 0) {
            zbroj += i;
        }
    }
     if(broj == 1)
    {
        printf("Unijeli ste broj 1. \n");
        return 0;
    }
    if(zbroj > broj + 1) {
        printf("Broj %d je slozeni broj.\n", broj);
        printf("Zbroj svih njegovih djelitelja je %d.\n", zbroj);
    } else {
        printf("Broj %d nije slozeni broj.\n", broj);
    }

    return 0;
}