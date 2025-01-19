/*2. Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese prost. Nakon
svakog unosa, brojevi se smještaju u dinamički alociran memorijski prostor odgovarajuće
veličine. Nakon  završetka unosa, brojevi se spremaju u datoteku  sortirani_brojevi.txt,
sortirani po veličini silazno.*/
#include <stdio.h>
#include <stdlib.h>

int je_prost(int broj)
{
    if (broj <= 1)
        return 0;
    for (int i = 2; i <= broj / 2; i++)
    {
        if (broj % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int unos, *niz = NULL, br = 0, prost = 0, temp;
    FILE *dat = NULL;
    FILE *dat_parni = NULL;

    dat = fopen("sortirani_brojevi.txt", "w");
    dat_parni = fopen("parni_brojevi.txt", "w");

    if (!dat || !dat_parni)
        return 1;

    while (!prost)
    {
        scanf("%d", &unos);
        niz = (int *)realloc(niz, (br + 1) * sizeof(int));
        *(niz + br++) = unos;
        if (je_prost(unos))
            prost = 1;
    }

    for (int i = 0; i < br - 1; i++)
    {
        for (int j = i + 1; j < br; j++)
        {
            if (*(niz + i) < *(niz + j))
            {
                temp = *(niz + i);
                *(niz + i) = *(niz + j);
                *(niz + j) = temp;
            }
        }
    }

    for (int i = 0; i < br; i++)
    {
        fprintf(dat, "%d\n", *(niz + i));
        if (*(niz + i) % 2 == 0)
        {
            fprintf(dat_parni, "%d\n", *(niz + i));
        }
    }

    fclose(dat);
    fclose(dat_parni);
    free(niz);

    return 0;
}
