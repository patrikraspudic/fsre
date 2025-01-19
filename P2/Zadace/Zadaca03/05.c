/*5. Napisati program koji  definira strukturu za zapis podataka o  rečenicama:  recenica rečenice
(string), broj riječi u rečenici (int), duljina rečenice (int) i najduža riječ (string - ukoliko je
više riječi iste duljine odabire se ona koja je prva po abecedi). Korisnik unosi rečenice sve
dok  ne  unese  recenica  "kraj", a zatim se unesene rečenice sortiraju po broju riječi, odnosno
po duljini rečenice ako je broj riječi isti te se formira novi string na način da se iz tako
sortiranih rečenica uzmu najdulje riječi i spoje u novi string u kojem će biti odvojene
razmacima.  Sve  radnje  se  obavljaju  u  zasebnim  funkcijama,  a  ispis  rezultata  u  glavnom
programu.*/

#include <stdio.h>
#include <string.h>

struct recenica
{
    char tekst[100];
    int brojrijeci;
    int duljinarecenice;
    char najduzarijec[100];
};

void najduljarijec(char tekst[], char rijec[]);
void formiranjestringa(struct recenica recenice[], char string[], int brojrijeci);
int brojrijeciurecenici(char tekst[]);
void sortiranje(struct recenica recenice[], int brojrecenica);
void unos(struct recenica recenice[], int *i);

int main()
{

    struct recenica recenice[100];
    char nstring[300] = "";
    int i = 0;

    unos(recenice, &i);
    sortiranje(recenice, i);
    formiranjestringa(recenice, nstring, i);
    puts(nstring);

    return 0;
}

void sortiranje(struct recenica recenice[], int brojrecenica)
{
    struct recenica temp;

    for (int i = 0; i < brojrecenica; i++)
    {
        recenice[i].brojrijeci = brojrijeciurecenici(recenice[i].tekst);
        recenice[i].duljinarecenice = strlen(recenice[i].tekst);
    }

    for (int i = 0; i < brojrecenica - 1; i++)
    {
        for (int j = i + 1; j < brojrecenica; j++)
        {
            if (recenice[i].brojrijeci < recenice[j].brojrijeci ||
                (recenice[i].brojrijeci == recenice[j].brojrijeci && recenice[i].duljinarecenice < recenice[j].duljinarecenice))
            {
                temp = recenice[i];
                recenice[i] = recenice[j];
                recenice[j] = temp;
            }
        }
    }
}

int brojrijeciurecenici(char tekst[])
{
    int br = 0;

    for (int i = 0; i < strlen(tekst) + 1; i++)
        if (tekst[i] == ' ' || tekst[i] == '\0')
            br++;

    return br;
}

void najduljarijec(char tekst[], char rijec[])
{
    int bs = 0, br = 0, brojmax;
    char rijeci[100][100];

    for (int i = 0; i < strlen(tekst) + 1; i++)
    {
        if (tekst[i] == ' ' || tekst[i] == '\0')
        {
            rijeci[br][bs] = '\0';
            br++;
            bs = 0;
        }
        else
        {
            rijeci[br][bs++] = tekst[i];
        }
    }

    strcpy(rijec, rijeci[0]);
    brojmax = strlen(rijec);

    for (int i = 1; i < br; i++)
    {
        if (brojmax < strlen(rijeci[i]) || brojmax == strlen(rijeci[i]) && strcmp(rijec, rijeci[i]) > 0)
        {
            brojmax = strlen(rijeci[i]);
            strcpy(rijec, rijeci[i]);
        }
    }
}

void formiranjestringa(struct recenica recenice[], char string[], int brojrijeci)
{

    char najduljerijeci[100][100], rijec[100];
    int bs = 0;

    for (int i = 0; i < brojrijeci; i++)
    {
        najduljarijec(recenice[i].tekst, rijec);
        strcpy(najduljerijeci[i], rijec);
    }

    for (int i = 0; i < brojrijeci; i++)
    {
        for (int j = 0; j < strlen(najduljerijeci[i]) + 1; j++)
        {
            if (najduljerijeci[i][j] == '\0')
                string[bs++] = ' ';
            else
                string[bs++] = najduljerijeci[i][j];
        }
    }
}

void unos(struct recenica recenice[], int *i)
{

    int boolean = 0;
    char input[100];

    while (!boolean)
    {
        fflush(stdin);
        gets(input);
        if (strcmp(input, "kraj") == 0)
            boolean = 1;
        else
        {
            strcpy(recenice[*i].tekst, input);
            (*i)++;
        }
    }
}
