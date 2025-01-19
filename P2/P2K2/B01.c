#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Napravi program koji dinamicki zauzima memoriju za 20 cijelih brojeva, unosi brojeve i ako je
zbroj parnih unesenih brojeva veci od zbroja neparnih unesenih brojeva ispisuje poruku o
prosjecnoj vrijednosti svih unesenih brojeva, uneseni broj najblizi tom prosjeku i njegovu poziciju
u silazno sortiranom nizu, a u suprotnom ispisuje najmanji i najveci uneseni broj i sve pozitivne
dvoznamenkaste parne unesene brojeve sortirane uzlazno. Program treba koristiti iskljucivo
sintaksu pokazivaca.*/

int main()
{
    int *niz = NULL, *parni = NULL, *neparni = NULL;
    niz = (int *)malloc(sizeof(int) * 20);
    parni = (int *)malloc(sizeof(int) * 20);
    neparni = (int *)malloc(sizeof(int) * 20);
    int *prosjek = (int *)malloc(sizeof(int));
    int *zbroj_parnih = (int *)malloc(sizeof(int));
    int *zbroj_neparnih = (int *)malloc(sizeof(int));
    int *zbroj = (int *)malloc(sizeof(int));
    int *min = (int *)malloc(sizeof(int));
    int *max = (int *)malloc(sizeof(int));
    int *razlika = (int *)malloc(sizeof(int));
    int *najblizi = (int *)malloc(sizeof(int));
    int *pom = (int *)malloc(sizeof(int));
    int *pozicija = (int *)malloc(sizeof(int));

    *zbroj = 0;
    *zbroj_parnih = 0;
    *zbroj_neparnih = 0;
    for (int i = 0; i < 20; i++)
    {
        niz = (int *)realloc(niz, (i + 1) * sizeof(int));
        scanf("%d", niz + i);
        if (niz[i] % 2 == 0)
        {
            *zbroj_parnih += niz[i];
        }
        else
        {
            *zbroj_neparnih += niz[i];
        }
        *zbroj += niz[i];
    }

    *min = niz[0];
    *max = niz[0];
    for (int i = 0; i < 20; i++)
    {
        if (*max < niz[i])
            *max = niz[i];
        else if (*min > niz[i])
            *min = niz[i];
    }

    if (*zbroj_parnih > *zbroj_neparnih)
    {
        *prosjek = *zbroj / 20;
        *razlika = niz[0] - *prosjek;

        for (int i = 0; i < 19; i++)
            for (int j = i + 1; j < 20; j++)
                if (niz[i] < niz[j])
                {
                    *pom = niz[i];
                    niz[i] = niz[j];
                    niz[j] = *pom;
                }

        for (int i = 0; i < 20; i++)
        {
            if (*razlika > abs(niz[i] - *prosjek))
                *razlika = abs(niz[i] - *prosjek);
        }
        for (int i = 0; i < 20; i++)
        {
            if (*razlika == abs(niz[i] - *prosjek))
            {
                *najblizi = niz[i];
                *pozicija = i;
            }
        }

        printf("Prosjek je %d, a najblizi broj je %d i ima poziciju %d u silaznom sortiranom nizu\n", *prosjek, *najblizi, (*pozicija + 1));
    }
    else
    {
        printf("Minimum je %d\nMaksimum je %d\n", *min, *max);
        for (int i = 0; i < 19; i++)
            for (int j = i + 1; j < 20; j++)
                if (niz[i] > niz[j])
                {
                    *pom = niz[i];
                    niz[i] = niz[j];
                    niz[j] = *pom;
                }
        for (int i = 0; i < 20; i++)
        {
            if ((niz[i] > 9 && niz[i] < 100) && (niz[i] % 2 == 0))
                printf("%d\n", niz[i]);
        }
    }
    free(niz);
    free(parni);
    free(neparni);
    free(prosjek);
    free(zbroj_parnih);
    free(zbroj_neparnih);
    free(min);
    free(max);
    free(razlika);
    free(najblizi);
    free(pom);
    free(pozicija);
    return 0;
}
