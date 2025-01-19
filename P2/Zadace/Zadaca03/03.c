/*3. Napisati  program  koji definira  strukturu  za  zapis  podataka  o adresama  koje  unosi
korisnik: ulica (string), kućni broj (int), mjesto (string) i poštanski broj (int), unosi podatke
za 5 adresa, dodatno unosi mjesto i formira dva niza adresa, jedan u dodatno
unesenom mjestu i drugi izvan njega, sortirane po abecedi naziva ulice, odnosno kućnom
broju ako je ulica ista. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u
glavnom programu. */

#include <stdio.h>
#include <string.h>

struct adresa
{
    char ulica[100];
    int kucnibroj;
    char mjesto[100];
    int postanskibroj;
};

void unoseadresa(struct adresa adrese[]);
void raspodjelaadresa(struct adresa adrese[], struct adresa adrese1[], struct adresa adrese2[], char mjesto[], int *br1, int *br2);
void sortiranje(struct adresa adrese[], int br);

int main()
{
    struct adresa adrese[5], adrese1[5], adrese2[5];
    char mjesto[100];
    int br1 = 0, br2 = 0;

    unoseadresa(adrese);
    fflush(stdin);
    gets(mjesto);
    raspodjelaadresa(adrese, adrese1, adrese2, mjesto, &br1, &br2);
    sortiranje(adrese1, br1);
    sortiranje(adrese2, br2);

    for (int i = 0; i < br1; i++)
    {
        puts("Adrese s istim mjestom");
        printf("\n--%s %d %s %d--\n", adrese1[i].ulica, adrese1[i].kucnibroj, adrese1[i].mjesto, adrese1[i].postanskibroj);
    }
    for (int i = 0; i < br2; i++)
    {
        puts("Adrese s razlicitim mjestom");
        printf("\n--%s %d %s %d--\n", adrese2[i].ulica, adrese2[i].kucnibroj, adrese2[i].mjesto, adrese2[i].postanskibroj);
    }

    return 0;
}

void unoseadresa(struct adresa adrese[])
{
    for (int i = 0; i < 5; i++)
    {
        printf("---%d. adresa---", i + 1);
        puts("Unesite ulicu");
        fflush(stdin);
        gets(adrese[i].ulica);
        puts("Unesite kucnibroj");
        scanf("%d", &adrese[i].kucnibroj);
        puts("Unesite mjesto");
        fflush(stdin);
        gets(adrese[i].mjesto);
        puts("Unesite postanskibroj");
        scanf("%d", &adrese[i].postanskibroj);
    }
}

void raspodjelaadresa(struct adresa adrese[], struct adresa adrese1[], struct adresa adrese2[], char mjesto[], int *br1, int *br2)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(mjesto, adrese[i].mjesto) == 0)
        {
            adrese1[(*br1)++] = adrese[i];
        }
        else
        {
            adrese2[(*br2)++] = adrese[i];
        }
    }
}

void sortiranje(struct adresa adrese[], int br)
{
    struct adresa temp;

    for (int i = 0; i < br - 1; i++)
    {
        for (int j = i + 1; j < br; j++)
        {
            if (strcmp(adrese[i].ulica, adrese[j].ulica) > 0 || strcmp(adrese[i].ulica, adrese[j].ulica) == 0 && adrese[i].kucnibroj > adrese[j].kucnibroj)
            {
                temp = adrese[i];
                adrese[i] = adrese[j];
                adrese[j] = temp;
            }
        }
    }
}