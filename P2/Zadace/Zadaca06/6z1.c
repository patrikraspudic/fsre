
/*1. Napisati  program  koji  od korisnika traži naziv datoteke u kojoj su zapisane izmjerene
dubine  vodostaja  Neretve  na određenom mjernom mjestu tijekom vremena. Pročitati
sve  pomerature, pohraniti ih u dinamički alociran  memorijski prostor odgovarajuće
veličine i odrediti prosječnu dubinu  vodostaja na tom mjernom mjestu.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *dat = NULL;
    float *pomerature = NULL, pom, zbroj = 0, prosjek;
    int br = 0;
    char input[32];
    int dodatni_unos;

    printf("Unesite naziv datoteke: ");
    gets(input);

    dat = fopen(input, "r+");

    if (!dat)
    {
        printf("Greska pri otvaranju datoteke.\n");
        return 1;
    }

    while (fscanf(dat, "%f", &pom) == 1)
    {
        zbroj += pom;
        pomerature = (float *)realloc(pomerature, (br + 1) * sizeof(float));
        *(pomerature + br++) = pom;
    }

    if (br > 0)
    {
        prosjek = zbroj / br;
        printf("Prosjek trenutnih dubina je %f\n", prosjek);
    }
    else
    {
        printf("Nema trenutnih podataka za izracunavanje prosjeka.\n");
    }

    printf("Unesite broj dodatnih dubina koje zelite unijeti: ");
    scanf("%d", &dodatni_unos);

    freopen(input, "a", dat);

    for (int i = 0; i < dodatni_unos; i++)
    {
        printf("Unesite dodatnu dubinu %d: ", i + 1);
        scanf("%f", &pom);
        zbroj += pom;
        pomerature = (float *)realloc(pomerature, (br + 1) * sizeof(float));
        *(pomerature + br++) = pom;
        fprintf(dat, "%f\n", pom);
        br++;
    }

    prosjek = zbroj / br;
    printf("Prosjek svih dubina je %f\n", prosjek);

    fclose(dat);

    free(pomerature);

    return 0;
}
