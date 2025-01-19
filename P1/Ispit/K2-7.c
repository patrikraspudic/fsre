/*Napravi program koji unosi brojeve sve dok se ne unese broj nula 
koji se ne pohranjuje u niz unesenih brojeva, 
a nakon toga rekurzivnom funkcijom neparni_dvoznamenkasti() provjerava
jesu li svi uneseni brojevi neparni i dvoznamenkasti, 
te rezultat ispisuje u glavnom programu.*/
#include <stdio.h>
int neparni_dvoznamenkasti(int niz[],int i);
int main() {
    int niz[1000], i = 0;
    printf("Unesite brojeve (0 za kraj): ");
    while(1) {
        scanf("%d", &niz[i]);
        if(niz[i] == 0)
        {
            break;
        }
        i++;
    }
    if(i == 0)
    {
        printf("Nisu uneseni borjevi\n");
    }
    else if(neparni_dvoznamenkasti(niz, i))
    {
        printf("Svi uneseni brojevi su neparni i dvoznamenkasti.\n");
    }
    else
    {
        printf("Nisu svi uneseni brojevi neparni i dvoznamenkasti.\n");
    }
    return 0;
}
int neparni_dvoznamenkasti(int niz[], int i) {
    if(i == 0)
    {
        return 1;
    }
    else 
    {
        if(niz[i - 1] % 2 == 0 || niz[i - 1] < 10 || niz[i - 1] > 99)
        {
           return 0;
        }
        else
        {
            return neparni_dvoznamenkasti(niz, i - 1);
        }
    }
}




/*
KOMPLEKSNIJI ALI DOBAR KOD
#include<stdio.h>

void neparni_dvoznamenkasti(int niz[], int i);

int main() {
    int niz[100];
    printf("Unesite brojeve, za kraj unesite 0:\n");
    int i = 0;
    while (1) {
        scanf("%d", &niz[i]);
        if (niz[i] == 0) // Ako je unesen broj 0, prekidamo unos.
            break;
        if (niz[i] % 2 == 1 && niz[i] >= 10 && niz[i] <= 99) { // Ispisujemo ako je broj neparni i dvoznamenkasti.
            printf("Unesen je neparni i dvoznamenkasti broj: %d\n", niz[i]);
        }
        i++;
    }
    neparni_dvoznamenkasti(niz, i);
    return 0;
}

void neparni_dvoznamenkasti(int niz[], int i) {
    if (i == 0) { // Baza rekurzije: ako je niz prazan, ispisujemo odgovarajuću poruku.
        printf("Niz je prazan.\n");
        return;
    }
    if (niz[i - 1] % 2 == 0 || niz[i - 1] < 10 || niz[i - 1] > 99) { // Provjera neparnosti i broja znamenki.
        printf("Broj %d nije neparni i dvoznamenkasti.\n", niz[i - 1]);
    }
    if (i > 1) // Ako nismo stigli do početka niza, rekurzivno pozivamo funkciju za preostali dio niza.
        neparni_dvoznamenkasti(niz, i - 1);
}
*/