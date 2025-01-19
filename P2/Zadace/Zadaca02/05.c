/*5. Napisati program koji definira strukturu za zapis podataka o učenicima: prezime i ime
(string), srednja škola (string), razred (int) i ocjene (niz tipa int). Program unosi podatke
za 5 učenika s tim da srednja škola može biti gimnazija, srednja elektrotehnička škola i
ostale srednje škole, a ocjena može biti najviše 10. Ispisuju se podaci o učenicima,
sortirani po školi i prosjeku (ukoliko je škola ista) te se nakon svih učenika jedne škole (a
prije učenika sljedeće škole) ispisuje pouka o broju učenika iz te škole i razlici najvećeg i
najmanjeg prosjeka ocjena učenika u toj školi.*/

#include <stdio.h>
#include <string.h>

struct ucenik
{
    char ime[50];
    char srednjaskola[50];
    int razred;
    int ocjene[10];
};

float prosjek(int niz[]);
float razlikaprosjeka(struct ucenik niz[], char nazivskole[]);

int main()
{
    struct ucenik ucenici[5], temp;
    int boolean = 0, j = 0, inputi, brojucenika = 0;
    char input[50];

    for (int i = 0; i < 5; i++)
    {
        printf("\n\n---%d. ucenik---\n\n", i + 1);
        fflush(stdin);
        puts("Unesite prezime i ime");
        fflush(stdin);
        gets(ucenici[i].ime);
        fflush(stdin);
        puts("Unesite naziv srednje skole");
        boolean = 0;
        while (!boolean)
        {
            fflush(stdin);
            gets(input);
            if (strcmp(input, "gimnazija") == 0 || strcmp(input, "srednja elektrotehnicka skola") == 0 || strcmp(input, "ostale srednje skole") == 0)
            {
                strcpy(ucenici[i].srednjaskola, input);
                boolean = 1;
            }
            else
                puts("Neispravan unos!");
        }
        puts("Unesite razred");
        scanf("%d", &ucenici[i].razred);
        boolean = 0, j = 0;
        puts("Unesite do 10 ocjena, unosom neispravne ocjene prekidate unos");
        while (!boolean && j != 10)
        {
            scanf("%d", &inputi);
            if (inputi <= 0 || inputi >= 6)
                boolean = 1;
            else
                ucenici[i].ocjene[j++] = inputi;
        }
    }

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
        {
            if ((strcmp(ucenici[i].srednjaskola, ucenici[j].srednjaskola) < 0) || (strcmp(ucenici[i].srednjaskola, ucenici[j].srednjaskola) == 0 && prosjek(ucenici[i].ocjene) < prosjek(ucenici[j].ocjene)))
            {
                temp = ucenici[i];
                ucenici[i] = ucenici[j];
                ucenici[j] = temp;
            }
        }

    puts("----Ispis----");

    for (int i = 0; i < 5; i++)
    {
        printf("\n\n----%d ucenik ----\n\n", i + 1);
        printf("\n Prezime i ime - %s \n", ucenici[i].ime);
        printf("\n Srednja skola - %s \n", ucenici[i].srednjaskola);
        printf("\n Razred - %d \n", ucenici[i].razred);
        printf("\n Ocjene - \n");
        j = 0;
        do
        {
            printf(" %d ", ucenici[i].ocjene[j++]);
        } while (j < 10 && (ucenici[i].ocjene[j] >= 1 && ucenici[i].ocjene[j] <= 5));
        printf("\n Prosjek - %f \n", prosjek(ucenici[i].ocjene));
        brojucenika++;
        if (strcmp(ucenici[i].srednjaskola, ucenici[i + 1].srednjaskola) != 0)
        {
            printf("\n\nBroj ucenika skole (%s) jest %d ", ucenici[i].srednjaskola, brojucenika);
            brojucenika = 0;
            printf("\n\n Razlika izmedju najveceg i najmanjeg prosjeka je %f ", razlikaprosjeka(ucenici, ucenici[i].srednjaskola));
        }
    }

    return 0;
}

float prosjek(int niz[])
{
    int suma = 0, i = 0;

    while (niz[i] >= 1 && niz[i] <= 5)
    {
        suma += niz[i++];
    }

    return (float)suma / i;
}

float razlikaprosjeka(struct ucenik niz[], char nazivskole[])
{
    float max, min;
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(niz[i].srednjaskola, nazivskole) == 0)
        {
            max = prosjek(niz[i].ocjene);
            min = prosjek(niz[i].ocjene);
            break;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(niz[i].srednjaskola, nazivskole) == 0)
        {
            if (prosjek(niz[i].ocjene) > max)
                max = prosjek(niz[i].ocjene);
            if (prosjek(niz[i].ocjene) < min)
                min = prosjek(niz[i].ocjene);
        }
    }

    return max - min;
}
