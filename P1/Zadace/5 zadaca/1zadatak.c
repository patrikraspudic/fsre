/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>
#define VELICINA_NIZA 8

int unos(int niz[VELICINA_NIZA], int suma);
float statistika(int niz[VELICINA_NIZA], int *max, int *min, int suma);

int main() {
    int niz[VELICINA_NIZA];
    int max, min;
    int suma = 0;
    float prosjek;

    suma = unos(niz, suma);
    prosjek = statistika(niz, &max, &min, suma);

    printf("Maksimum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Prosjek: %.2f\n", prosjek);

    return 0;
}


int unos(int niz[VELICINA_NIZA], int suma) {
    printf("Unesite %d brojeva:\n", VELICINA_NIZA);

    for (int i = 0; i < VELICINA_NIZA; i++) {
        do {
            printf("Unesite broj #%d: ", i + 1);
            scanf("%d", &niz[i]);

            
            if (niz[i] < 0) {
                printf("Uneseni broj mora biti pozitivan. Molimo ponovno unesite.\n");
            }
        } while (niz[i] < 0);

        suma += niz[i];
    }

    return suma;
}


float statistika(int niz[VELICINA_NIZA], int *max, int *min, int suma) {
    *max = niz[0];
    *min = niz[0];

    for (int i = 1; i < VELICINA_NIZA; i++) {
        
        if (*max < niz[i]) {
            *max = niz[i];
        }

       
        if (*min > niz[i]) {
            *min = niz[i];
        }
    }

    return suma / (float)VELICINA_NIZA;
}
