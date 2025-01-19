/*
Napravi program koji unosi stringove sve dok se 4 puta uzastopno ne unesu
stringovi sa istim brojem suglasnika.Nakog toga strignovi se sortiraju uzlazno
po broju samoglasnika i ispisuju na ekran.
*/
#include <stdio.h>
#include <string.h>
int brojSamoglasnika(char rijec[32]);
int brojSuglasnika(char rijec[32]);
void sortiranje(char rijeci[32][32], int n);
int main()
{
    char stringovi[32][128];
    int i = 0, j, brojac = 0;
    int trenutni, prethodni = -1, pretprethodini = -1, cetvrti = -1;
    puts("Unosi stringove:");
    do
    {
        fflush(stdin);
        gets(stringovi[i]);
        trenutni = brojSuglasnika(stringovi[i]);
        if (i > 0)
            prethodni = brojSuglasnika(stringovi[i - 1]);
        if (i > 1)
            pretprethodini = brojSuglasnika(stringovi[i - 2]);
        if (i > 2)
            cetvrti = brojSuglasnika(stringovi[i - 3]);

        if (i > 2 && trenutni == prethodni && prethodni == pretprethodini && pretprethodini == cetvrti)
            brojac++;
        else
            brojac = 0;
        i++;
    } while (brojac < 1);
    sortiranje(stringovi, i);

    puts("Sortirani stringovi:");
    for (j = 0; j < i; j++)
        puts(stringovi[i]);

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
int brojSuglasnka(char rijec[32])
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
            if (brojSamoglasnika(rijeci[i]) > brojSamoglasnika(rijeci[j]))
            {
                strcpy(pom, rijeci[i]);
                strcpy(rijeci[i], rijeci[j]);
                strcpy(rijeci[j], pom);
            }
}