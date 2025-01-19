/*
Napravi program koji definira strukturu za zapis podataka o mostarskim gradskim
kaficima: naziv kafica,adresa,ime vlasnika i kapacitet kafica(broj stolica).
Program unosi podatke za 10 kafica i ispisuje nazive kafica ciji je kapacitet manji od
100 sortirane po imenu vlasnika, odn nazivu kafica kao je vlasnik isti.
*/
#include <stdio.h>
#include <string.h>
struct adresa
{
    char ulica[64];
    int kucniBroj;
};
struct kafici
{
    char naziv[32];
    struct adresa kAdresa;
    char imeVlasnika[32];
    int kapacitet;
};
int main()
{
    struct kafici k[5], pK;
    int i, j;
    puts("Unesite podatke za 10 kafica:");
    for (i = 0; i < 5; i++)
    {
        printf("%d. kafic\n", i + 1);
        printf("Naziv kafica:");
        fflush(stdin);
        gets(k[i].naziv);

        printf("Ulica kafica:");
        fflush(stdin);
        gets(k[i].kAdresa.ulica);

        printf("Kucni broj kafica:");
        scanf("%d", &k[i].kAdresa.kucniBroj);

        printf("Ime vlasnika lokala:");
        fflush(stdin);
        gets(k[i].imeVlasnika);

        printf("Kapacitet kafica:");
        scanf("%d", &k[i].kapacitet);
    }
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if ((stricmp(k[i].imeVlasnika, k[j].imeVlasnika) > 0) ||
                ((stricmp(k[i].imeVlasnika, k[j].imeVlasnika) == 0) && (stricmp(k[i].naziv, k[j].naziv) > 0)))
            {
                pK = k[i];
                k[i] = k[j];
                k[j] = pK;
            }
    puts("Sortirani kafici:");
    for (i = 0; i < 5; i++)
        if (k[i].kapacitet < 100)
            printf("%s\n", k[i].naziv);
    return 0;
}
