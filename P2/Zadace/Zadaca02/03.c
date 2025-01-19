
/*3.
Napisati program koji definira strukturu za zapis podataka o rijecima rečenice koju unosi
korisnik: redni broj riječi u rečenici (int), tekst riječi (string), broj samoglasnika
u riječi (int) i slovo koje se najviše puta ponavlja (char).
Ispisuju se podaci o svim riječima sortirani po broju samoglasnika silazno
*/
#include <stdio.h>
#include <string.h>
#include <stdio.h>
struct rijec
{
    int redniBroj;
    char tekst[32];
    int bs;
    char nps;
};
int bsf(char c[]);
char npsf(char c[]);
int main()
{
    struct rijec r[20], pR;

    int br = 0, bs = 0, i, j;
    char recenica[256];
    puts("Unesi recenicu:");
    gets(recenica);

    for (i = 0; i < strlen(recenica) + 1; i++)
    {
        if (recenica[i] == ' ' || recenica[i] == '\0')
        {
            r[br].redniBroj = br + 1;
            r[br++].tekst[bs] = '\0';
            bs = 0;
        }
        else
        {
            r[br].tekst[bs++] = recenica[i];
        }
    }
    for (i = 0; i < br; i++)
    {
        r[i].bs = bsf(r[i].tekst);
        r[i].nps = npsf(r[i].tekst);
    }
    for (i = 0; i < br - 1; i++)
        for (j = i + 1; j < br; j++)
            if (r[i].bs < r[j].bs)
            {
                pR = r[i];
                r[i] = r[j];
                r[j] = pR;
            }

    printf("Sortirane rijeci:\n");

    for (i = 0; i < br; i++)
    {
        printf("\n%d. rijec\n", i + 1);
        printf("Redni broj: %d\n", r[i].redniBroj);
        printf("Tekst rijeci: %s\n", r[i].tekst);
        printf("Broj samoglasnika: %d\n", r[i].bs);
        printf("Najponavljanije slovo: %c\n", r[i].nps);
    }
    return 0;
}
int bsf(char c[])
{
    int brojSamoglasnika = 0, i, j;
    char samoglasnici[] = "AaEeIiOoUu";
    for (i = 0; i < strlen(c); i++)
        for (j = 0; j < strlen(samoglasnici); j++)
            if (c[i] == samoglasnici[j])
            {
                brojSamoglasnika++;
                break;
            }
    return brojSamoglasnika;
}
char npsf(char c[])
{
    int brojacLista[128] = {0}, max = 1, maxSlovo = c[0];
    int i;
    for (i = 0; i < strlen(c); i++)
    {
        brojacLista[c[i]]++;
    }
    for (i = 64; i < 128; i++)
    {
        if (brojacLista[i] > max && ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')))
        {
            max = brojacLista[i];
            maxSlovo = i;
        }
    }
    return maxSlovo;
}