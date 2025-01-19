/*4.
Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog
znaka ispisuje, sortirane po abecedi sva do tada učitana slova. Na kraju se ispisuje broj
ponavljanja svakog od samoglasnika (ne vodeći računa radi li se o velikim i malim
slovima)
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *dat1;
    int a = 0, e = 0, i = 0, o = 0, u = 0, br = 0;
    char zn, string[128];

    dat1 = fopen("tekst.txt", "r");

    if (!dat1)
        return 1;

    while (!feof(dat1))
    {
        zn = fgetc(dat1);
        if (isalpha(zn))
        {
            switch (tolower(zn))
            {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            }
            string[br++] = zn;
            string[br] = '\0';
            for (int j = 0; j < br - 1; j++)
                for (int k = j + 1; k < br; k++)
                    if (string[j] > string[k])
                    {
                        zn = string[j];
                        string[j] = string[k];
                        string[k] = zn;
                    }

            puts(string);
        }
    }
    printf("\n a(%d) e(%d) i(%d) o(%d) u(%d)\n", a, e, i, o, u);
    fclose(dat1);

    return 0;
}