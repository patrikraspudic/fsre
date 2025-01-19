/*4.
Napisati program koji definira strukturu za zapis podataka o gradovima: ime grada
(string), država u kojoj se nalazi (string), broj stanovnika (int), najbliža rijeka (string) i
najbliža planina (string). Program inicijalizira podatke za 10 gradova, unosi ime rijeke i
planine i pronalazi onaj grad kojima je to najbliža rijeka, odnosno planina (po jedan grad
za svaki zemljopisni pojam), a ako ima više takvih gradova ispisuje se onaj koji ima
najveći broj stanovnika. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata
u glavnom programu.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Grad
{
    char ime[100];
    char drzava[100];
    int broj_stanovnika;
    char najbliza_rijeka[100];
    char najbliza_planina[100];
};

void najblizaRijeka(struct Grad gradovi[5], char trazena_rijeka[100]);
void najblizaPlanina(struct Grad gradovi[5], char trazena_planina[100]);

int main()
{
    struct Grad gradovi[5] = {
        {"Mostar", "BiH", 120000, "Neretva", "Velez"},
        {"Zagreb", "Hrvatska", 800000, "Sava", "Medvednica"},
        {"Beograd", "Srbija", 1200000, "Sava", "Avala"},
        {"Citluk", "BiH", 6000, "Neretva", "Cabulja"},
        {"Podgorca", "Crna Gora", 180000, "Moraca", "Gorica"},
    };
    char trazena_rijeka[100];
    char trazena_planina[100];

    printf("Unesite ime najblize rijeke: ");
    fflush(stdin);
    gets(trazena_rijeka);
    najblizaRijeka(gradovi, trazena_rijeka);

    printf("Unesite ime najblize planine: ");
    fflush(stdin);
    gets(trazena_planina);
    najblizaPlanina(gradovi, trazena_planina);

    return 0;
}
void najblizaRijeka(struct Grad gradovi[5], char trazena_rijeka[100])
{
    int max_stanovnika = -1;
    struct Grad najblizi_grad;

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(gradovi[i].najbliza_rijeka, trazena_rijeka) == 0)
        {
            if (gradovi[i].broj_stanovnika > max_stanovnika)
            {
                max_stanovnika = gradovi[i].broj_stanovnika;
                najblizi_grad = gradovi[i];
            }
        }
    }

    printf("\nGrad najblizi rijeci %s sa najvecim brojem stanovnika:\n", trazena_rijeka);
    printf(" - Ime grada: %s\n", najblizi_grad.ime);
    printf(" - Drzava: %s\n", najblizi_grad.drzava);
    printf(" - Broj stanovnika: %d\n", najblizi_grad.broj_stanovnika);
    printf(" - Najbliza planina: %s\n", najblizi_grad.najbliza_planina);
}

void najblizaPlanina(struct Grad gradovi[5], char trazena_planina[100])
{
    int max_stanovnika = -1;
    struct Grad najblizi_grad;

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(gradovi[i].najbliza_planina, trazena_planina) == 0)
        {
            if (gradovi[i].broj_stanovnika > max_stanovnika)
            {
                max_stanovnika = gradovi[i].broj_stanovnika;
                najblizi_grad = gradovi[i];
            }
        }
    }

    printf("\nGrad najblizi planini %s sa najvecim brojem stanovnika:\n", trazena_planina);
    printf(" - Ime grada: %s\n", najblizi_grad.ime);
    printf(" - Drzava: %s\n", najblizi_grad.drzava);
    printf(" - Broj stanovnika: %d\n", najblizi_grad.broj_stanovnika);
    printf(" - Najbliza rijeka: %s\n", najblizi_grad.najbliza_rijeka);
}
