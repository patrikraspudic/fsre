#include <stdio.h>

void unos_i_ispis();

int main ()
{
    unos_i_ispis();
    return 0;
}

void unos_i_ispis()
{
    char niz[11];
    int brojac[256] = {0};

    printf("Unesite 11 znakova: ");
    for (int i = 0; i < 11; i++)
    {
        scanf(" %c", &niz[i]);
        brojac[niz[i]]++;
    }

    printf("Slova koja se ponavljaju tocno tri puta su: ");
    for (int i = 0; i < 256; i++)
    {
        if (brojac[i] == 3 && ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')))
        {
            printf("%c ", i);
        }
    }
    printf("\n");
}
