/*
Napravi program koji unosi stringove sve dok se 3 puta uzastopno ne unesu stringovi sa istim brojem samoglasnika.
Nakog toga stringovi se sortiraju silazno po borju suglasnika i ispisuju na ekran.
*/
#include <stdio.h>
#include <string.h>
int brojSamoglasnika(char rijec[32]);
int brojSuglasnika(char rijec[32]);
void sortiranje(char rijeci[32][32], int n);
int main()
{
    char stringovi[32][32];
    int i = 0, j, brojac = 0;
    int trenutni, prethodni = -1, pretprethodni = -1;

    puts("Unosi stringove:");
    do
    {
        fflush(stdin);
        gets(stringovi[i]);
        trenutni = brojSamoglasnika(stringovi[i]);
        if (i > 0)
            prethodni = brojSamoglasnika(stringovi[i - 1]);
        if (i > 1)
            pretprethodni = brojSamoglasnika(stringovi[i - 2]);

        if (i > 1 && trenutni == prethodni && prethodni == pretprethodni)
            brojac++;
        else
            brojac = 0;
        i++;
    } while (brojac < 1);
    sortiranje(stringovi, i);

    puts("Sortirani stringovi:");
    for (j = 0; j < i; j++)
        puts(stringovi[j]);

    return 0;
}
int brojSamoglasnika(char rijec[32])
{
    char samoglasnici[] = "aeiouAEIOU";
    int i, j, bs = 0;

    for (i = 0; i < strlen(rijec); i++)
        for (j = 0; j < strlen(samoglasnici); j++)
            if (rijec[i] == samoglasnici[j])
                bs++;

    return bs;
}
int brojSuglasnika(char rijec[32])
{
    char samoglasnici[] = "aeiouAEIOU";
    int i, j, bsug = 0;
    for (i = 0; i < strlen(rijec); i++)
        for (j = 0; j < strlen(samoglasnici); j++)
            if (rijec[i] != samoglasnici[j])
                bsug++;

    return bsug;
}
void sortiranje(char rijeci[32][32], int n)
{
    char pom[32];
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (brojSuglasnika(rijeci[i]) < brojSuglasnika(rijeci[j]))
            {
                strcpy(pom, rijeci[i]);
                strcpy(rijeci[i], rijeci[j]);
                strcpy(rijeci[j], pom);
            }
}