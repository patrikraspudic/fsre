/*Napravi program koji u funkciji unos() unosi znakove sve dok 
se sva mala slova engleskog alfabeta ne unesu barem po jednom, 
a zatim u funkciji obrada_podataka() pronalazi broj malih
samoglasnika i broj velikih suglasnika i ispisuje ih u glavnom programu, 
te korištenjem funkcije zbroj_ASCII_znamenki() za svaki zank računa i 
ispisuje zbroj znamenki njegovog ASCII koda tako da najprije ispiše znak, 
a zatim, u zagradama, zbroj znamenki njegovog ASCII koda.*/
#include<stdio.h>
void unos(char *niz);
void obrada_podataka(char *niz,int *samoglasnici,int *suglasnici);
int zbroj_ASCII_znamenki(char znak);
int main()
{
    char niz[1000];
    int samoglasnici = 0,suglasnici = 0;
    int i;
    unos(niz);
    obrada_podataka(niz,&samoglasnici,&suglasnici);
    printf("Mali samoglasnici: %d\n",samoglasnici);
    printf("Veliki suglasnici: %d\n",suglasnici);
    for(i = 0;niz[i] != '\0';i++)
    {
        printf("Znak: %c, Zbroj ASCII znamenki: %d\n",niz[i],zbroj_ASCII_znamenki(niz[i]));
    }
    return 0;
}
void unos(char *niz)
{
    int frekvencija[26] = {0};
    int brojac = 0;
    char znak;
    while(brojac < 26)
    {
        scanf("%c",&znak);
        if(znak >= 'a' && znak <= 'z')
        {
            if(frekvencija[znak - 'a'] == 0)
            {
                brojac++;
            }
            frekvencija[znak - 'a']++;
        }
        *niz++ = znak;
    }
    *niz = '\0';
}
void obrada_podataka(char *niz,int *samoglasnici,int *suglasnici)
{
    char znak;
    while((znak = *niz++) != '\0')
    {
        if(znak >= 'a' && znak <= 'z' && (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u'))
        {
            (*samoglasnici)++;
        }
        else if(znak >= 'A' && znak <= 'Z' && !(znak == 'A' || znak == 'E' || znak == 'I' || znak == 'O' || znak == 'U' ))
        {
            (*suglasnici)++;
        }
    }
}
int zbroj_ASCII_znamenki(char znak)
{
    int zbroj = 0;
    int ascii = (int)znak;
    while(ascii > 0)
    {
        zbroj = zbroj +ascii % 10;
        ascii = ascii / 10;
    }
    return zbroj;
}


/*GOVNO - ne ispisuje velike suglasnike
#include <stdio.h>

int unos(char *unos_slova);
void obrada_podataka(char *unos_slova);
int zbroj_ASCII_znamenki(char znak);

int main()
{
    char unos_slova[26];
    unos(unos_slova);
    obrada_podataka(unos_slova);
    return 0;
}

int unos(char *unos_slova)
{
    char c;
    int index = 0, i;
    printf("Unesite slova engleskog alfabeta:\n");
    for (i = 0; i < 26; i++)
    {
        unos_slova[i] = 0;
    }
    while (index < 26)
    {
        scanf(" %c", &c);
        if ('a' <= c && c <= 'z' && !unos_slova[c - 'a'])
        {
            unos_slova[c - 'a'] = 1;
            index++;
        }
    }
    return 0;
}

void obrada_podataka(char *unos_slova)
{
    int broj_malih_samoglasnika = 0;
    int broj_velikih_suglasnika = 0;
    int i;

    for (i = 0; i < 26; i++)
    {
        char znak = 'a' + i;
        if (unos_slova[i])
        {
            if (znak >= 'a' && znak <= 'z' && (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u'))
            {
                broj_malih_samoglasnika++;
            }
            else if (znak >= 'A' && znak <= 'Z' && !(znak == 'A' || znak == 'E' || znak == 'I' || znak == 'O' || znak == 'U' ))
            {
                broj_velikih_suglasnika++;
            }
        }
    }
    printf("Broj malih samoglasnika: %d\n", broj_malih_samoglasnika);
    printf("Broj velikih suglasnika: %d\n", broj_velikih_suglasnika);

    printf("Zbroj ASCII znamenki:\n");
    for (i = 0; i < 26; i++)
    {
        if (unos_slova[i])
        {
            char znak = 'a' + i;
            printf("%c (%d)\n", znak, zbroj_ASCII_znamenki(znak));
        }
    }
}

int zbroj_ASCII_znamenki(char znak)
{
    int zbroj = 0;

    while (znak != 0)
    {
        zbroj = zbroj + znak % 10;
        znak = znak / 10;
    }
    return zbroj;
}

*/