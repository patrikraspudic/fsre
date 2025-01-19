/*Napravi program koji unosi recenice i pohranjuje podatke o njima u definiranu strukturu za zapis
podataka o unesenim recenicama: tekst recenice, broj rijeci u recenici, rijec koja je u toj recenici
prva po abecedi. Ovi podaci se programski odreduju nakon unosa recenice. Unos se prekida kada
se unese rijec kraj koja se ne uzima u obradu. Nakon toga ispisuju se recenice sortirane po broju
rijeci u recenici, silazno, odnosno prema abecedi izdvojene rijeci, ako je broj rijeci u recenici jednak*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 100

struct recenica
{
    char tekst[128];
    int broj_rijeci;
    char prva[32];
};

void rastavljanje(struct recenica r[], int brojac_unosa);

int main()
{

    struct recenica r[N], temp;
    char recenica[128];
    int brojac_unosa = 0;
    int kontrola = 1;
    int i, j;

    while (kontrola)
    {
        printf("Unosite: ");

        gets(recenica);
        recenica[strcspn(recenica, "\n")] = '\0';

        if (stricmp(recenica, "kraj") == 0)
        {
            kontrola = 0;
        }
        else
        {
            strcpy(r[brojac_unosa].tekst, recenica);
            brojac_unosa++;
        }
    }

    rastavljanje(r, brojac_unosa);

    for (i = 0; i < brojac_unosa - 1; i++)
    {
        for (j = i + 1; j < brojac_unosa; j++)
        {
            if ((r[i].broj_rijeci < r[j].broj_rijeci) || ((r[i].broj_rijeci == r[j].broj_rijeci) && (stricmp(r[i].prva, r[j].prva) > 0)))
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }

    for (i = 0; i < brojac_unosa; i++)
    {
        printf("%s - %d - %s \n", r[i].tekst, r[i].broj_rijeci, r[i].prva);
    }

    return 0;
}

void rastavljanje(struct recenica r[], int brojac_unosa)
{

    int i, j, counter = 0;
    char rijeci[32][32];
    int brrijeci = 0;
    int slova = 0;
    char trazena[32];

    for (i = 0; i < brojac_unosa; i++)
    {
        strcpy(r[i].prva, "z");
        r[i].broj_rijeci = 0;
        for (j = 0; j <= strlen(r[i].tekst); j++)
        {

            if ((r[i].tekst[j] == ' ') || (r[i].tekst[j] == '\0'))
            {

                rijeci[brrijeci][slova] = '\0';
                r[i].broj_rijeci++;

                if ((brrijeci == 0) || (stricmp(r[i].prva, rijeci[brrijeci]) > 0))
                {

                    strcpy(r[i].prva, rijeci[brrijeci]);
                }
                brrijeci++;
                slova = 0;
            }
            else
            {

                rijeci[brrijeci][slova] = r[i].tekst[j];
                slova++;
            }
        }
    }
}
