/*1.
Napisati program koji pita korisnika kolika je dimenzija niza realnih brojeva, dinamički
alocira memoriju za taj niz i unosi brojeve, a zatim unosi i dodatni realan broj u također
dinamički alociranu memoriju te na kraju ispisuje, sortirane po veličini, samo one
brojeve iz niza koji su veći od dodatnog broja. Koristiti isključivo sintaksu pokazivača.
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int duljina, i, j;
    float *niz = NULL, *dBroj = NULL;
    float pom;

    puts("Unesite duljinu niza: ");
    scanf("%d", &duljina);
    niz = (float *)malloc(sizeof(float) * duljina);
    for (i = 0; i < duljina; i++)
    {
        printf("%d. broj\n", i + 1);
        scanf("%f", niz + i);
    }
    dBroj = (float *)malloc(sizeof(float));
    puts("Unesite jos jedan broj: ");
    scanf("%f", dBroj);

    for (i = 0; i < duljina - 1; i++)
        for (j = i + 1; j < duljina; j++)
            if (*(niz + i) < *(niz + j))
            {
                pom = *(niz + i);
                *(niz + i) = *(niz + j);
                *(niz + j) = pom;
            }
    printf("Brojevi veci od dodatnog broja\n");
    for (i = 0; i < duljina; i++)
        if (*(niz + i) > *dBroj)
            printf("%f\n", *(niz + i));

    free(niz);
    free(dBroj);

    return 0;
}