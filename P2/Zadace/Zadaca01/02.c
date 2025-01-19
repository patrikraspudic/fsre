/* 2. Napisati program koji unosi riječi sve dok se ne unese riječ u kojoj se neko slovo ponavlja
barem  tri  puta  i,  nakon  toga,  ispisuje sve unesene riječi koje počinju i završavaju itim
slovom, ne vodeći računa o razlici velikih i malih slova, sortirane silazno po abecedi.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char rijeci[30][40], pom[30];
    char rijeci2[30][40];
    int i = 0, j, k = 0, prekid = 0, asciibrojac[200] = {0};

    printf("Unosite rijei:\n");
    do
    {
        gets(rijeci[i]);

        for (j = 'A'; j <= 'z'; j++)
        {
            asciibrojac[j] = 0;
        }

        for (j = 0; j < strlen(rijeci[i]); j++)
        {
            asciibrojac[rijeci[i][j]]++;
        }

        for (j = 'A'; j <= 'z'; j++)
        {
            if (asciibrojac[j] >= 3 && isalpha(j))
            {
                prekid = 1;
                break;
            }
        }
        i++;
    } while (!prekid);
    for (j = 0; j < i; j++)
    {
        if (tolower(rijeci[j][0]) == tolower(rijeci[j][strlen(rijeci[j]) - 1]))
        {
            strcpy(rijeci2[k++], rijeci[j]);
        }
    }
    for (j = 0; j < k - 1; j++)
    {
        for (int l = j + 1; l < k; l++)
        {
            if (stricmp(rijeci2[j], rijeci2[l]) < 0)
            {
                strcpy(pom, rijeci2[j]);
                strcpy(rijeci2[j], rijeci2[l]);
                strcpy(rijeci2[l], pom);
            }
        }
    }
    printf("Ispis:\n");
    for (j = 0; j < k; j++)
        puts(rijeci2[j]);
    return 0;
}