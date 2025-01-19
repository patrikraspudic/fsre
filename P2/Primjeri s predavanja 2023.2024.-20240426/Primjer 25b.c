/* primjer unoosi znakove sve dok se ne unese znak isti ko na pocetku
   te ih smje�ta u za to predvidjeni, dinamicki zauzet memorijski prostor optimalne
   velicine, nakon unosa se za svako slovo engleskog alfabeta ispisuje slovo i
   broj njegovih ponavljanja, bez oobzira radi li se o velikim ili malom slovu
   brojeve ponavljanja slova pohraniti u dinamicki zauzet memorijski prostor
   odgovarajuce velicine */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int kontrolaKraja(char *znakovi, int brojZnakova);
int main()
{
    char *znakovi = NULL;
    int *ponavljanja = NULL;
    int brojZnakova = 0, i, j;
    char unos;
    int krajUnosa = 0;

    znakovi = (char *)malloc(sizeof(char));
    ponavljanja = (int *)malloc(sizeof(int) * 26);

    for (i = 0; i < 26; i++)
        ponavljanja[i] = 0;

    puts("Unsoi zankove");
    while (!krajUnosa)
    {
        fflush(stdin);
        scanf("%c", &unos);

        znakovi = (char *)realloc(znakovi, sizeof(char) * (brojZnakova + 1));
        znakovi[brojZnakova] = unos;
        brojZnakova++;

        if (brojZnakova > 1 && unos == znakovi[0])
            krajUnosa = 1;
    }
    for (i = 0; i < brojZnakova; i++)
        ponavljanja[toupper((znakovi[i])) - 'A']++;

    for (i = 0; i < 26; i++)
        if (ponavljanja[i] > 0)
            printf("Slovo %c se ponavlja %d puta\n", 'A' + i, ponavljanja[i]);

    free(znakovi);
    free(ponavljanja);
    return 0;
}