/*
Napravi program koji definira strukturu za zapis podaataka o internet portalima:
naziv portala,grad u kojem je sjediste,web adresa i broj pretplatnika.
Program unosi podatke za 10 portala i ispisuje nazive mostarskih portala i
njihove web adrese sortirane po broju pretplatnika,odn po abecedi naziva,
ako je broj pretplatnika isti.
*/
#include <stdio.h>
#include <string.h>
struct internetPortali
{
    char naziv[32];
    char grad[32];
    char webAdresa[32];
    int brojPretplatnika;
};
int main()
{
    struct internetPortali p[3], pP;
    int i, j;
    puts("Unosi portale:");
    for (i = 0; i < 3; i++)
    {
        printf("%d. portal\n", i + 1);
        printf("Naziv portala:\n");
        fflush(stdin);
        gets(p[i].naziv);

        printf("Unesi grad:\n");
        fflush(stdin);
        gets(p[i].grad);

        printf("Unesi web adresu:\n");
        fflush(stdin);
        gets(p[i].webAdresa);

        printf("Uneiste broj pretplatnika:\n");
        scanf("%d", &p[i].brojPretplatnika);
    }
    for (i = 0; i < 2; i++)
        for (j = i + 1; j < 3; j++)
            if ((p[i].brojPretplatnika < p[j].brojPretplatnika) ||
                ((p[i].brojPretplatnika == p[j].brojPretplatnika) && (stricmp(p[i].naziv, p[j].naziv) > 0)))
            {
                pP = p[i];
                p[i] = p[j];
                p[j] = pP;
            }

    puts("Sortirani portali:");
    for (i = 0; i < 3; i++)
        printf("%s\n%s\n", p[i].naziv, p[i].webAdresa);

    return 0;
}