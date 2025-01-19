/*Napravi program koji unosi realne brojeve i smjesta ih u dinamicki alocirani prostor
odgovarajuce velicine (realocirati za svaki unos) sve dok se ne unese broj ciji je decimalni
dio manji od 0.05, a zatim ispisuje one brojeve broj ciji je suma znamenaka cijelog dijela parna,
sortirane silazno. Program treba koristiti iskljucivo sintaksu pokazivaca.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float *niz = NULL, pom;
    float broj, cijeliDio, decimalniDio;
    int i = 0, j, zbroj;
    int kontrola = 0, brojUnesenih;

    while (!kontrola)
    {
        niz = (float *)realloc(niz, sizeof(float) * (i + 1));
        scanf("%f", &broj);

        decimalniDio = fabs(broj - (int)broj);
        *(niz + i) = broj;

        if (decimalniDio < 0.05)
            kontrola = 1;
        else
            i++;
    }
    brojUnesenih = i;

    for (i = 0; i < brojUnesenih - 1; i++)
        for (j = i + 1; j < brojUnesenih; j++)
            if (*(niz + i) < *(niz + j))
            {
                pom = *(niz + i);
                *(niz + i) = *(niz + j);
                *(niz + j) = pom;
            }

    for (i = 0; i < brojUnesenih; i++)
    {
        cijeliDio = (int)fabs(*(niz + i));
        zbroj = 0;
        while (cijeliDio > 0)
        {
            zbroj = zbroj + (int)cijeliDio % 10;
            cijeliDio = cijeliDio / 10;
        }

        if (zbroj % 2 == 0)
            printf("%f\n", *(niz + i));
    }
    free(niz);

    return 0;
}