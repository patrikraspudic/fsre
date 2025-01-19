/*5.
Napisati program koji definira strukturu za zapis podataka o motociklima: proizvođač
(string), model (string), snaga motora (int) i cijena (float). Dinamički se alocira memorija
za niz od 10 motocikala i unose se podaci o motociklima, te se sortiraju po proizvođaču,
odnosno modelu (ako je proizvođač isti). Unosi se dodatni realan broj i ispisuju podaci o
motociklima čija je cijena veća od dodatnog broja. Koristiti isključivo sintaksu pokazivača.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct motocikl
{
    char *proizvodac;
    char *model;
    int snaga;
    float cijena;
};
int main()
{
    struct motocikl *m = NULL, pM;
    int niz = 3, i, j;
    float dBroj;

    m = (struct motocikl *)malloc(sizeof(struct motocikl) * niz);

    for (i = 0; i < 3; i++)
    {
        fflush(stdin);
        puts("Proizvodjac: ");
        (m + i)->proizvodac = malloc(sizeof(char) * 32);
        gets((m + i)->proizvodac);
        fflush(stdin);
        puts("Model: ");
        (m + i)->model = malloc(sizeof(char) * 32);
        gets((m + i)->model);
        puts("Snaga motora: ");
        scanf("%d", &(m + i)->snaga);
        puts("Cijena motocikla: ");
        scanf("%f", &(m + i)->cijena);
    }

    for (i = 0; i < 2; i++)
        for (j = i + 1; j < 3; j++)
            if ((stricmp((m + i)->proizvodac, (m + j)->proizvodac) > 0) ||
                ((stricmp((m + i)->proizvodac, (m + j)->proizvodac) == 0) &&
                 (stricmp((m + i)->model, (m + j)->model) > 0)))
            {
                pM = *(m + i);
                *(m + i) = *(m + j);
                *(m + j) = pM;
            }

    puts("Unesite dodatni broj:");
    scanf("%f", &dBroj);

    for (i = 0; i < 3; i++)
        if ((m + i)->cijena > dBroj)
        {
            printf("\n%s\n%s\n%d\n%f\n", (m + i)->proizvodac, (m + i)->model, (m + i)->snaga, (m + i)->cijena);
        }

    for (i = 0; i < 3; i++)
    {
        free((m + i)->proizvodac);
        free((m + i)->model);
    }
    return 0;
}