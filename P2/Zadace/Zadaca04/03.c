/*3.
Napisati program koji dinamički alocira memoriju za niz cijelih brojeva koji se unose sve
dok neki od unesenih brojeva ne bude identičan prvom unesenom broju. Memorija se
realocira prije svakog unosa broja tako da se koristi optimalno. Brojevi se ispisuju,
sortirani silazno po veličini zadnje znamenke. Koristiti isključivo sintaksu pokazivača.
*/
#include <stdio.h>
#include <stdlib.h>

int zz(int c);
int main()
{
    int *niz = NULL;
    int unos, pom, i = 0, j, k, boolean = 0;
    puts("Unosite cijele brojeve(za kraj isti ko na pocetku):");
    while (!boolean)
    {
        niz = (int *)realloc(niz, sizeof(int) * (i + 1));
        printf("%d. broj\n", i + 1);
        scanf("%d", niz + i);
        if (i >= 1)
            boolean = (*(niz) == *(niz + i));
        i++;
    }

    for (j = 0; j < i - 1; j++)
        for (k = j + 1; k < i; k++)
            if (zz(*(niz + j)) < zz(*(niz + k)))
            {
                pom = *(niz + j);
                *(niz + j) = *(niz + k);
                *(niz + k) = pom;
            }
    puts("\nIspis: ");
    for (j = 0; j < i; j++)
        printf("%d ", *(niz + j));

    free(niz);
    return 0;
}
int zz(int c)
{
    if (c < 0)
        c = c * -1;
    return c % 10;
}