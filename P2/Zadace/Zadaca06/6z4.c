/*4. Napisati  program  koji  učitava sva  slova  iz  datoteke  tekst.txt  i nakon svakog učitanog
pohranjuje ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon što
su svi znakovi pročitani, ispisuje se onaj znak koji se ponovio najviše puta, kao i broj
njegovih ponavljanja.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *dat = NULL;
    char *string = NULL, zn;
    int len = 0, max = -1;
    int br['z' - 'A' + 1] = {0};

    dat = fopen("tekst.txt", "r");

    if (!dat)
        return 1;

    while (!feof(dat))
    {
        zn = fgetc(dat);
        if (isalpha(zn))
        {
            string = (char *)realloc(string, sizeof(char) * (len + 2));
            br[zn - 'A']++;
            *(string + (len++)) = zn;
        }
    }

    *(string + len) = '\0';
    fclose(dat);

    for (int i = 0; i < ('z' - 'A' + 1); i++)
        if (max < br[i])
        {
            max = br[i];
            zn = i + 'A';
        }

    printf("%c %d", zn, max);

    free(string);
    return 0;
}
