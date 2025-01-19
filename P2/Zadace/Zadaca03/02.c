/*2.
Napisati program koji unosi string, rastavlja ga u niz struktura za zapis podataka o
znakovima u stringu: znak (char) i broj njegovih ponavljanja u stringu (int) na način da su
sva ponavljanja istog znaka u stringu predstavljena jednim elementom niza, sortira
znakove stringa po broju pojavljivanja (silazno) te formira i ispisuje novi string sastavljen
od tako sortiranih slova i broja njihovog ponavljanja (navedenog u zagradi). Sve radnje se
obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom programu.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct brojac_znakova
{
    char znak;
    int broj;
};

void inicijaliziraj_brojace(struct brojac_znakova brojevi[128]);
void obradi_string(struct brojac_znakova brojevi[128], char *str);
void sortiraj_brojace(struct brojac_znakova brojevi[128]);
void ispisi_brojace(struct brojac_znakova brojevi[128]);

int main()
{
    struct brojac_znakova brojevi[128];
    char unos[1000];

    inicijaliziraj_brojace(brojevi);

    printf("Unesite string: ");
    fflush(stdin);
    gets(unos);

    obradi_string(brojevi, unos);
    sortiraj_brojace(brojevi);
    ispisi_brojace(brojevi);

    return 0;
}

void inicijaliziraj_brojace(struct brojac_znakova brojevi[128])
{
    for (int i = 0; i < 128; i++)
    {
        brojevi[i].znak = i;
        brojevi[i].broj = 0;
    }
}

void obradi_string(struct brojac_znakova brojevi[128], char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = tolower(str[i]);
        if (isalpha(c))
        {
            brojevi[c].broj++;
        }
    }
}

void sortiraj_brojace(struct brojac_znakova brojevi[128])
{
    struct brojac_znakova temp;
    for (int i = 0; i < 127; i++)
    {
        for (int j = i + 1; j < 128; j++)
        {
            if (brojevi[i].broj < brojevi[j].broj)
            {
                temp = brojevi[i];
                brojevi[i] = brojevi[j];
                brojevi[j] = temp;
            }
        }
    }
}

void ispisi_brojace(struct brojac_znakova brojevi[128])
{
    int prvi = 1;
    for (int i = 0; i < 128; i++)
    {
        if (brojevi[i].broj > 0 && isalpha(brojevi[i].znak))
        {
            if (!prvi)
            {
                printf("-");
            }
            printf("%c(%d)", brojevi[i].znak, brojevi[i].broj);
            prvi = 0;
        }
    }
    printf("\n");
}
