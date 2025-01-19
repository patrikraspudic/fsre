/*3. Napisati program koji unosi rečenicu i ispisuje riječi te rečenice s barem 4 slova sortirane
po broju samoglasnika u njima, po duljini riječi ako je broj samogalsnika isti, odnosno po
abecedi ako su i broj samoglasnika i duljina riječi isti. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int jelisamoglasnik(char c);
int brojsamoglasnika(char c[]);

int main()
{

    char recenica[100];
    char rijeci[30][100], pom[100];
    char rijeci2[30][100];
    int i, j = 0, k, brojac = 0;
    int br = 0, bs = 0;

    printf("Unesite neku recenicu:\n");
    gets(recenica);

    for (i = 0; i < strlen(recenica) + 1; i++)
    {
        if (recenica[i] == ' ' || recenica[i] == '\0')
        {
            rijeci[br++][bs] = '\0';
            bs = 0;
        }
        else
        {
            rijeci[br][bs++] = recenica[i];
        }
    }

    for (i = 0; i < br; i++)
    {
        if (strlen(rijeci[i]) >= 4)
        {
            strcpy(rijeci2[j++], rijeci[i]);
        }
    }

    for (i = 0; i < j - 1; i++)
    {
        for (int k = i + 1; k < j; k++)
        {

            if ((brojsamoglasnika(rijeci2[i]) > brojsamoglasnika(rijeci2[k])) || (brojsamoglasnika(rijeci2[i]) == brojsamoglasnika(rijeci2[k])) && (strlen(rijeci2[i]) > strlen(rijeci2[k])) ||
                (brojsamoglasnika(rijeci2[i]) == brojsamoglasnika(rijeci2[k])) && (strlen(rijeci2[i]) == strlen(rijeci2[k]) && (strcmp(rijeci2[i], rijeci2[k]) > 0)))
            {
                strcpy(pom, rijeci2[i]);
                strcpy(rijeci2[i], rijeci2[k]);
                strcpy(rijeci2[k], pom);
            }
        }
    }

    for (int i = 0; i < j; i++)
        puts(rijeci2[i]);

    return 0;
}

int jelisamoglasnik(char c)
{
    if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
        return 1;
    else
        return 0;
}

int brojsamoglasnika(char c[])
{
    int brojac = 0;

    for (int i = 0; i < strlen(c); i++)
    {
        if (jelisamoglasnik(c[i]))
            brojac++;
    }

    return brojac;
}