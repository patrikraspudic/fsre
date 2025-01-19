/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    float broj, prethodni_broj = 0.0;
    int brojac_negativnih = 0;
    float suma_negativnih = 0.0;
    int prvi_unos = 1;

    printf("Unesite realne brojeve (za kraj unesite dva broja sa istim cijelim dijelom): \n");

    do {
        scanf("%f", &broj);

        if((int)broj == (int)prethodni_broj && prvi_unos == 0) {
            break;
        }

        if(broj < 0) {
            suma_negativnih += broj;
            brojac_negativnih++;
        }

        prethodni_broj = broj;
        prvi_unos = 0;
    } while(1);

    if(brojac_negativnih > 0) {
        printf("Prosjek negativnih unesenih brojeva je: %.2f\n", suma_negativnih / brojac_negativnih);
    } else {
        printf("Nije unesen niti jedan negativan broj.\n");
    }

    return 0;
}
