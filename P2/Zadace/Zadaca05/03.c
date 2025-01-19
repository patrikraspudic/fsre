/* 3.
Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
dio (float), inicijalizira niz od 10 kompleksnih brojeva i u datoteku
kompleksni_brojevi.txt upisuju se sortirani po udaljenosti od ishodišta kompleksne
ravnine.
*/
#include <stdio.h>
#include <math.h>
struct kompleksni
{
    float realni;
    float imaginarni;
    float udaljenost;
};
int main()
{
    struct kompleksni pom, broj[10] = {{20, 5}, {12.3, 5.6}, {2.2, 5.7}, {18.35, 35.6}, {2.13, 3.14}, {2.773, 8.4}, {9.33, 4.52}, {14.24, 16.7}, {1.17, 9.23}, {15.7, 1.34}};
    int i, j;
    FILE *dat;
    dat = fopen("kompleksni_brojevi.txt", "w");
    for (i = 0; i < 10; i++)
        broj[i].udaljenost = sqrt(pow(broj[i].realni, 2) + pow(broj[i].imaginarni, 2));

    for (i = 0; i < 9; i++)
        for (j = i + 1; j < 10; j++)
            if (broj[i].udaljenost < broj[j].udaljenost)
            {
                pom = broj[i];
                broj[i] = broj[j];
                broj[j] = pom;
            }

    for (i = 0; i < 10; i++)
    {
        fprintf(dat, "%f ", broj[i].realni);
        fprintf(dat, "%fi\n", broj[i].imaginarni);
    }

    return 0;
}