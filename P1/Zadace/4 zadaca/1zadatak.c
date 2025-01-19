#include <stdio.h>

void unos(char niz[5]);
int je_mali_samoglasnik(char znak);
void mali_samoglasnik(char niz[5]);

int main()
{
    char niz[5];

    unos(niz);
    mali_samoglasnik(niz);

    return 0;
}

void unos(char niz[5])
{
    int i = 0;
    char uneseni_znak;

    printf("Unesite 5 slova:\n");

    do
    {
        scanf(" %c", &uneseni_znak);

        if ((uneseni_znak >= 'a' && uneseni_znak <= 'z') || (uneseni_znak >= 'A' && uneseni_znak <= 'Z'))
        {
            niz[i] = uneseni_znak;
            i++;
        }

    } while (i != 5);
}

int je_mali_samoglasnik(char znak)
{
    return (znak == 'a' || znak == 'e' || znak == 'i' || znak == 'o' || znak == 'u');
}

void mali_samoglasnik(char niz[5])
{
    int brojac = 0;

    for (int i = 0; i < 5; i++)
    {
        if (je_mali_samoglasnik(niz[i]))
            brojac++;
    }

    printf("Broj malih samoglasnika: %d\n", brojac);
}
