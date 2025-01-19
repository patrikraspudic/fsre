/*
Napravi program koji unosi recenice i pohranjuje podatke o njima u definiranju strukturu
za zapis podataka o unesenim recenicama: tekst recenice,broj samoglasnika u recenici,
rijec koja je u toj recenici zadnja po abecedi. Ovi podaci se programski odreduju
nakon unosa recenice. Unos se prekida kada se unese rijec kraj koja se ne uzima
u obradu.Nakon toga ispisuju se recenice sortirane po broju samoglasnika u recenici,
uzlazno,odnosno prema abecedi izdvojene rijeci,ako je broj samoglasnika u recenici jednak.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct recenica
{
    char tekst[100];
    int brojs;
    char zadr[100];
};

int brojsf(char input[]);
void abdzr(char output[], char input[]);

int main()
{
    int boolean = 0, i = 0;
    struct recenica recenice[120], temp;
    char input[100], placeholder[100];

    while (!boolean)
    {
        fflush(stdin);
        gets(input);
        if (strcmp(input, "kraj") == 0)
        {
            boolean = 1;
        }
        else
        {
            strcpy(recenice[i].tekst, input);
            recenice[i].brojs = brojsf(recenice[i].tekst);
            abdzr(placeholder, recenice[i].tekst);
            strcpy(recenice[i].zadr, placeholder);
            i++;
        }
    }

    for (int j = 0; j < i - 1; j++)
        for (int k = j + 1; k < i; k++)
            if ((recenice[j].brojs > recenice[k].brojs) || (recenice[j].brojs == recenice[k].brojs && strcmp(recenice[j].zadr, recenice[k].zadr) > 0))
            {
                temp = recenice[j];
                recenice[j] = recenice[k];
                recenice[k] = temp;
            }

    for (int j = 0; j < i; j++)
        printf("\n\n--- %d - %s - %s ---\n\n", recenice[j].brojs, recenice[j].tekst, recenice[j].zadr);

    return 0;
}

int brojsf(char input[])
{
    char samoglasnici[] = "aeiou";
    int x = 0;

    for (int i = 0; i < strlen(input); i++)
        for (int j = 0; j < strlen(samoglasnici); j++)
            if (samoglasnici[j] == tolower(input[i]))
            {
                x++;
                break;
            }

    return x;
}

void abdzr(char output[], char input[])
{
    char rijeci[100][100];
    int br = 0, bs = 0;
    char temp[100];

    for (int i = 0; i < strlen(input) + 1; i++)
    {
        if (input[i] == ' ' || input[i] == '\0')
        {
            rijeci[br++][bs] = '\0';
            bs = 0;
        }
        else
        {
            rijeci[br][bs++] = input[i];
        }
    }

    for (int i = 0; i < br - 1; i++)
        for (int j = i + 1; j < br; j++)
            if (strcmp(rijeci[i], rijeci[j]) > 0)
            {
                strcpy(temp, rijeci[i]);
                strcpy(rijeci[i], rijeci[j]);
                strcpy(rijeci[j], temp);
            }

    strcpy(output, rijeci[br - 1]);
}