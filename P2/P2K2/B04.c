/*4
Napravi program koji iz datoteke brojevi.txt cita sve brojeve i pohranjuje ih u dinamicki
alocirani prostor odgovarajuce duljine, a zatim u datoteku prosti-troznamenkasti.txt upisuje
sve ucitane brojeve cija je apsolutna vrijednost prost broj silazno.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *dat1, *dat2;
    dat1 = fopen("brojevi.txt", "r");
    if (dat1 == NULL)
        return 1;
    dat2 = fopen("prosti_troznamenkasti.txt", "w");
    if (dat2 == NULL)
        return 1;
    int kontrola;
    int *niz = NULL, pom;
    int i, j, k = 0;

    while (!feof(dat1))
    {
        niz = (int *)realloc(niz, (k + 1) * sizeof(int));
        fscanf(dat1, "%d", &niz[k]);
        k++;
    }

    for (i = 0; i < k - 1; i++)
        for (j = i + 1; j < k; j++)
            if (niz[i] < niz[j])
            {
                pom = niz[i];
                niz[i] = niz[j];
                niz[j] = pom;
            }

    for (i = 0; i < k; i++)
    {
        kontrola = 1;
        for (j = 2; j <= sqrt(niz[i]); j++)
            if (niz[i] % j == 0)
            {
                kontrola = 0;
            }

        if (niz[i] < 0)
            niz[i] = abs(niz[i]);

        if (niz[i] > 99 && niz[i] < 1000 && kontrola == 1)
        {
            fprintf(dat2, "%d\n", niz[i]);
        }
    }
    free(niz);
    fclose(dat1);
    fclose(dat2);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *dat1, *dat2;
    dat1 = fopen("brojevi.txt", "r");
    dat2 = fopen("prosti_troznamenkasti.txt", "w");
    int kontrola;
    int *niz = NULL, pom;
    int i = 0, j, i_max;
    while (!feof(dat1))
    {
        niz = (int *)realloc(niz, (i + 1) * sizeof(int));
        fscanf(dat1, "%d", (niz + i));
        i++;
    }
    i_max = i;

    for (i = 0; i < i_max - 1; i++)
        for (j = i + 1; j < i_max; j++)
            if (niz[i] < niz[j])
            {
                pom = *(niz + i);
                *(niz + i) = *(niz + j);
                *(niz + j) = pom;
            }

    for (i = 0; i < i_max; i++)
    {
        kontrola = 0;
        for (j = 2; j <= (niz[i] / 2); j++)
            if (niz[i] % j == 0)
                kontrola = 1;

        if (niz[i] < 0)
            niz[i] = abs(niz[i]);

        if (niz[i] > 99 && niz[i] < 1000 && kontrola == 0)
        {
            fprintf(dat2, "%d\n", niz[i]);
        }
    }
    free(niz);
    fclose(dat1);
    fclose(dat2);
    return 0;
}
*/