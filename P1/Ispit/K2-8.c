/*Napravi program koji u funkciji unos() unosi vrijeme u obliku HHMMSS,
a zatim u funkciji do_podneva() računa koliko je još sekundi preostalo 
do prvog sljedećeg podneva. Rezultat se ispisuje u glavnom programu, 
kao i odbrojavanje sekundi unatrag sve do nule.*/
#include <stdio.h>

int unos(int *h, int *m, int *s);
int do_podneva(int h, int m, int s);

int main()
{
    int h, m, s;
    if (unos(&h, &m, &s))
    {
        do_podneva(h, m, s);
    }
    return 0;
}

int unos(int *h, int *m, int *s)
{
    int vrijeme;
    printf("Unesi vrijeme u obliku HHMMSS: ");
    scanf("%d", &vrijeme);
    *s = vrijeme % 100;
    vrijeme /= 100;
    *m = vrijeme % 100;
    *h = vrijeme / 100;

    if ((*h > 23) || (*m > 59) || (*s > 59))
    {
        printf("Neispravan unos vremena!\n");
        return 0;
    }
    else
    {
        printf("Vrijeme je %02d:%02d:%02d\n", *h, *m, *s);
        return 1;
    }
}

int do_podneva(int h, int m, int s)
{
    int odPodne;
    if (h >= 12)
    {
        odPodne = (36 - h) * 3600 - m * 60 - s;
    }
    else
    {
        odPodne = (12 - h) * 3600 - m * 60 - s;
    }
    printf("Do sljedeceg podneva preostalo je %d sekundi.\n", odPodne);
    return odPodne;
}

/*
AKO TRAZIMO OD PROSLOG PODNEVA
int do_podneva(int h,int m,int s)
{
    int odPodne;
    if(h >= 12)
    {
         odPodne = (h - 12) * 3600 + m * 60 + s;
    }
    else
    {
        odPodne =(12 + h) * 3600 + m * 60 + s;
    }
    printf("Od proslog podneva je proslo %d sekundi",odPodne);
    return odPodne;
}
*/

/*
    printf("Odborjavanje:\n");
    while(odPodne >= 0)
    {
        printf("%d sekundi\n",odPodne);
        odPodne--;
    }
*/

/*----------------------------------------------------------------------*/

/*ZADATAK AKO IMAMO TRI VREMENA
#include <stdio.h>

int unos(int *h, int *m, int *s);
int sekunde_od_pocetka_dana(int h, int m, int s);

int main()
{
    int h[3], m[3], s[3], sekunde[3];
    int i, j, temp;

    for(i = 0; i < 3; i++)
    {
        if (unos(&h[i], &m[i], &s[i]))
        {
            sekunde[i] = sekunde_od_pocetka_dana(h[i], m[i], s[i]);
        }
    }

    // Sortiranje vremena
    for(i = 0; i < 2; i++)
    {
        for(j = i + 1; j < 3; j++)
        {
            if(sekunde[i] > sekunde[j])
            {
                temp = sekunde[i];
                sekunde[i] = sekunde[j];
                sekunde[j] = temp;
            }
        }
    }

    printf("Između najstarijeg i najnovijeg unesenog vremena prošlo je %d sekundi.\n", sekunde[2] - sekunde[0]);

    return 0;
}

int unos(int *h, int *m, int *s)
{
    int vrijeme;
    printf("Unesi vrijeme u obliku HHMMSS: ");
    scanf("%d", &vrijeme);
    *s = vrijeme % 100;
    vrijeme /= 100;
    *m = vrijeme % 100;
    *h = vrijeme / 100;

    if ((*h > 23) || (*m > 59) || (*s > 59))
    {
        printf("Neispravan unos vremena!\n");
        return 0;
    }
    else
    {
        printf("Vrijeme je %02d:%02d:%02d\n", *h, *m, *s);
        return 1;
    }
}

int sekunde_od_pocetka_dana(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}
*/