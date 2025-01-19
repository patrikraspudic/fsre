/*Napravi program koji iz datoteke podaci.txt cita sve rijeci i zatim u datoteku rezultat.txt zapisuje
samo one rijeci u kojima su prvo i zadnje slovo samoglasnici te osim njih u rijeci nema drugih
samoglasnika.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int samoglasnici(char c);

int main()
{
    FILE *dat1, *dat2;
    dat1 = fopen("podaci.txt", "r");

    if (dat1 == NULL)
        return 1;

    dat2 = fopen("rezultat.txt", "w");
    if (dat2 == NULL)
        return 1;

    char rijec[32];
    int kontrola, i;
    int duzina;

    while (!feof(dat1))
    {
        fscanf(dat1, "%s", rijec);

        duzina = strlen(rijec);
        if (duzina >= 2)
        {
            if (samoglasnici(rijec[0]) && samoglasnici(rijec[duzina - 1]))
            {
                kontrola = 1;
                for (i = 1; i < duzina - 1; i++)
                {
                    if (samoglasnici(rijec[i]))
                    {
                        kontrola = 0;
                    }
                }
                if (kontrola == 1)
                {
                    fprintf(dat2, "%s\n", rijec);
                }
            }
        }
    }

    fclose(dat1);
    fclose(dat2);
    return 0;
}

int samoglasnici(char c)
{
    char samoglasnici[] = "aeiouAEIOU";
    int i;
    for (i = 0; i < strlen(samoglasnici); i++)
        if (tolower(c) == samoglasnici[i])
            return 1;
    return 0;
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    FILE *dat1, *dat2;
    dat1 = fopen("podaci.txt", "r");
    dat2 = fopen("rezultat.txt", "w");

    char rijec[20];
    int kontrola, i;
    while (!feof(dat1))
    {
        fscanf(dat1, "%s", rijec);

        kontrola = 0;
        if (tolower(rijec[0]) == 'a' || tolower(rijec[0]) == 'e' || tolower(rijec[0]) == 'i' || tolower(rijec[0]) == 'o' || tolower(rijec[0]) == 'u')
            kontrola++;
        else
            continue;
        if (tolower(rijec[strlen(rijec) - 1]) == 'a' || tolower(rijec[strlen(rijec) - 1]) == 'e' || tolower(rijec[strlen(rijec) - 1]) == 'i' || tolower(rijec[strlen(rijec) - 1]) == 'o' || tolower(rijec[strlen(rijec) - 1]) == 'u')
            kontrola++;
        else
            continue;

        for (i = 1; i < strlen(rijec) - 1; i++)
        {
            if (tolower(rijec[i]) == 'a' || tolower(rijec[i]) == 'e' || tolower(rijec[i]) == 'i' || tolower(rijec[i]) == 'o' || tolower(rijec[i]) == 'u')
                kontrola++;
        }
        if (kontrola == 2)
            fprintf(dat2, "%s\n", rijec);
    }

    fclose(dat1);
    fclose(dat2);
    return 0;
}
*/