/*5. Napisati program koji iz datoteke rijeke.txt čita podatke o svim rijekama zapisanima u
datoteci: naziv rijeke (string - pretpostaviti da se radi o jednoj riječi), izvor (string -
pretpostaviti da se radi o jednoj riječi), ušće (string - pretpostaviti da se radi o jednoj
riječi), duljina rijeke u kilometrima (float) i svi se podaci smještaju u dinamički alociran
memorijski prostor odgovarajuće duljine Nakon toga ispisuju se podaci o rijekama čiji je
izvor ili ušće u Bosni i Hercegovini, sortirane po duljini rijeke silazno.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct rijeke
{
    char *naziv;
    char *izvor;
    char *usce;
    float duljina;
};

void dodaj_rijeku(FILE *dat, struct rijeke *nova_rijeka);
void spremi_u_datoteku(FILE *dat, struct rijeke *rijeka, int broj_rijeka);
void ispisi_rijeke_bh(struct rijeke *rijeka, int broj_rijeka);

int main()
{
    struct rijeke *rijeka = NULL, nova_rijeka;
    int broj_rijeka = 0;
    char unos[30];
    float duljina;
    FILE *dat;

    dat = fopen("rijeke.txt", "a+");
    if (dat == NULL)
    {
        printf("Greška pri otvaranju datoteke.\n");
        return 1;
    }

    while (fscanf(dat, "%s %s %s %f", unos, unos, unos, &duljina) == 4)
    {
        rijeka = (struct rijeke *)realloc(rijeka, (broj_rijeka + 1) * sizeof(struct rijeke));

        rijeka[broj_rijeka].naziv = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(rijeka[broj_rijeka].naziv, unos);

        rijeka[broj_rijeka].izvor = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(rijeka[broj_rijeka].izvor, unos);

        rijeka[broj_rijeka].usce = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(rijeka[broj_rijeka].usce, unos);

        rijeka[broj_rijeka].duljina = duljina;

        broj_rijeka++;
    }

    dodaj_rijeku(dat, &nova_rijeka);
    if (strlen(nova_rijeka.naziv) > 0)
    {
        rijeka = (struct rijeke *)realloc(rijeka, (broj_rijeka + 1) * sizeof(struct rijeke));
        rijeka[broj_rijeka++] = nova_rijeka;
    }

    spremi_u_datoteku(dat, rijeka, broj_rijeka);

    ispisi_rijeke_bh(rijeka, broj_rijeka);

    for (int i = 0; i < broj_rijeka; i++)
    {
        free(rijeka[i].naziv);
        free(rijeka[i].izvor);
        free(rijeka[i].usce);
    }
    free(rijeka);

    fclose(dat);

    return 0;
}

void dodaj_rijeku(FILE *dat, struct rijeke *nova_rijeka)
{
    char unos[30];

    printf("Unesite naziv rijeke (prazan unos za kraj unosa): ");
    scanf("%s", unos);
    if (strlen(unos) > 0)
    {
        nova_rijeka->naziv = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(nova_rijeka->naziv, unos);

        printf("Unesite izvor rijeke: ");
        scanf("%s", unos);
        nova_rijeka->izvor = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(nova_rijeka->izvor, unos);

        printf("Unesite usce rijeke: ");
        scanf("%s", unos);
        nova_rijeka->usce = (char *)malloc(strlen(unos) * sizeof(char));
        strcpy(nova_rijeka->usce, unos);

        printf("Unesite duljinu rijeke u kilometrima: ");
        scanf("%f", &(nova_rijeka->duljina));

        fprintf(dat, "%s %s %s %.2f\n", nova_rijeka->naziv, nova_rijeka->izvor, nova_rijeka->usce, nova_rijeka->duljina);
    }
}

void spremi_u_datoteku(FILE *dat, struct rijeke *rijeka, int broj_rijeka)
{
    fclose(dat);
    dat = fopen("rijeke.txt", "w");
    for (int i = 0; i < broj_rijeka; i++)
    {
        fprintf(dat, "%s %s %s %.2f\n", rijeka[i].naziv, rijeka[i].izvor, rijeka[i].usce, rijeka[i].duljina);
    }
}

void ispisi_rijeke_bh(struct rijeke *rijeka, int broj_rijeka)
{
    struct rijeke temp;
    for (int i = 0; i < broj_rijeka - 1; i++)
    {
        for (int j = i + 1; j < broj_rijeka; j++)
        {
            if (rijeka[i].duljina < rijeka[j].duljina)
            {
                temp = rijeka[i];
                rijeka[i] = rijeka[j];
                rijeka[j] = temp;
            }
        }
    }

    printf("\nRijeke ciji je izvor ili usce u Bosni i Hercegovini, sortirane po duljini silazno:\n");
    int counter = 0;
    for (int i = 0; i < broj_rijeka; i++)
    {
        if (strcmp(rijeka[i].izvor, "BiH") == 0 || strcmp(rijeka[i].usce, "BiH") == 0)
        {
            printf("%d. rijeka:\n", ++counter);
            printf("Naziv: %s\n", rijeka[i].naziv);
            printf("Izvor: %s\n", rijeka[i].izvor);
            printf("Usce: %s\n", rijeka[i].usce);
            printf("Duljina: %.2f km\n\n", rijeka[i].duljina);
        }
    }
}
