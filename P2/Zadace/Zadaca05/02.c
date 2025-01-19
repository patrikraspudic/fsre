/*2.
Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese broj 0. Nakon
svakog unosa broj se smješta u datoteku uneseni_brojevi.txt. Nakon toga u datoteku
sortirani_parni_brojevi.txt pohranjuju se uneseni parni brojevi sortirani po veličini.
*/

#include <stdio.h>

int main()
{
    int broj, parnibrojevi[64], boolean = 0, br = 0;
    FILE *dat1, *dat2;

    dat1 = fopen("uneseni_brojevi.txt", "w");
    dat2 = fopen("sortirani_parni_brojevi.txt", "w");

    if (!dat1 || !dat2)
        return 1;

    puts("Unesite brojeve, 0 za kraj");
    while (!boolean)
    {
        scanf("%d", &broj);
        if (broj % 2 == 0)
            parnibrojevi[br++] = broj;
        if (!broj)
            boolean = 1;
    }

    fclose(dat1);

    for (int i = 0; i < br - 1; i++)
        for (int j = i + 1; j < br; j++)
            if (parnibrojevi[i] > parnibrojevi[j])
            {
                broj = parnibrojevi[i];
                parnibrojevi[i] = parnibrojevi[j];
                parnibrojevi[j] = broj;
            }

    for (int i = 0; i < br; i++)
        fprintf(dat2, "%d ", parnibrojevi[i]);

    fclose(dat2);

    return 0;
}