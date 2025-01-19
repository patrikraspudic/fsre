/*4. Napisati  program  koji unosi  stringove do se ne ponove tri stringa iste duljine, ne nužno
zaredom  te  ispisuje  sortirane  po  broju  suglasnika  uzlazno  one  stringove  koji  se,  ne
vodeći računa o razlici velikih i malih slova, u abecednom poretku nalaze između prvog i
zadnjeg stringa (tj. oni koji nisu ni prvi ni zadnji po abecedi).*/
#include <stdio.h>
#include <string.h>

int jelisuglasnik(char c);
int brojsuglasnika(char c[]);

int main()
{

    char stringovi1[20][30], pom[30];
    char stringovi2[20][30];
    int brojaclista[31] = {0};
    int i = 0, k = 0, prekid = 0, brojac = 0;

    printf("Unosite recenice:\n");
    do
    {
        gets(stringovi1[i]);
        brojaclista[strlen(stringovi1[i])]++;
        if (i >= 2)
        {
            for (int j = 0; j < 31; j++)
            {
                if (brojaclista[j] == 3)
                    prekid = 1;
            }
        }
        i++;
    } while (!prekid);

    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (stricmp(stringovi1[j], stringovi1[k]) < 0)
            {
                strcpy(pom, stringovi1[j]);
                strcpy(stringovi1[j], stringovi1[k]);
                strcpy(stringovi1[k], pom);
            }
        }
    }

    for (int j = 1; j < i - 1; j++)
        strcpy(stringovi2[k++], stringovi1[j]);

    for (int j = 0; j < k - 1; j++)
    {
        for (int l = j + 1; l < k; l++)
        {
            if (brojsuglasnika(stringovi2[j]) > brojsuglasnika(stringovi2[l]))
            {
                strcpy(pom, stringovi2[j]);
                strcpy(stringovi2[j], stringovi2[l]);
                strcpy(stringovi2[l], pom);
            }
        }
    }

    printf("\nFormirani string:\n");

    for (int j = 0; j < k; j++)
        puts(stringovi2[j]);

    return 0;
}

int jelisuglasnik(char c)
{
    if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        return 1;
    else
        return 0;
}

int brojsuglasnika(char c[])
{
    int brojac = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (jelisuglasnik(c[i]))
            brojac++;
    }

    return brojac;
}