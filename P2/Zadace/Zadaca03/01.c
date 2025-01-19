/* 1. Napisati  program  koji  unosi  stringove  sve  dok  se  ne  unese  kraj  i,  nakon  svakog  unosa
popunjava niz struktura za zapis podataka o znakovima engleskog alfabeta: znak (char) i
broj  njegovih  ponavljanja  u  unesenim  stringovima  (int), pri čemu se zanemaruje razlika
velikih  i  malih  slova,  a  znakovi  koji  nisu  slova  se  ne  uzimaju  u  obzir,  sortira  znakove
stringa po broju ponavljanja te formira i ispisuje novi string sastavljen od tako sortiranih
slova  i brojeva njihovih ponavljanja, razdvojenih zarezom, dok se između dva slova
ispisuje znak - (npr: "a,6-e,5-n,4-..." ).*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct podaci
{
    char znak;
    int brojponavljanja;
};

int main()
{

    struct podaci slova[26], temp;
    int i, j = 0, boolean = 0;
    char string[200], input[100];

    for (int i = 'a'; i <= 'z'; i++)
    {
        slova[j].znak = i;
        slova[j++].brojponavljanja = 0;
    }

    j = 0;

    while (!boolean)
    {
        puts("Unesite string");
        gets(input);

        if (stricmp(input, "kraj") == 0)
        {
            boolean = 1;
        }
        else
        {

            for (i = 0; i < 26; i++)
            {
                slova[i].brojponavljanja = 0;
            }

            for (i = 0; i < 25; i++)
                for (j = i + 1; j < 26; j++)
                    if (slova[i].znak > slova[j].znak)
                    {
                        char temp;
                        temp = slova[i].znak;
                        slova[i].znak = slova[j].znak;
                        slova[j].znak = temp;
                    }

            for (i = 0; i < strlen(input); i++)
            {
                if (isalpha(input[i]))
                {
                    slova[tolower(input[i]) - 'a'].brojponavljanja++;
                }
            }

            for (i = 0; i < 25; i++)
                for (j = i + 1; j < 26; j++)
                    if (slova[i].brojponavljanja < slova[j].brojponavljanja)
                    {
                        temp = slova[i];
                        slova[i] = slova[j];
                        slova[j] = temp;
                    }

            j = 0;

            for (i = 0; i < 26; i++)
            {
                if (slova[i].brojponavljanja != 0)
                {
                    string[j++] = slova[i].znak;
                    string[j++] = ',';
                    string[j++] = slova[i].brojponavljanja + '0';
                    string[j++] = '-';
                }
            }

            string[j - 1] = '\0';

            puts(string);
        }
    }

    return 0;
}