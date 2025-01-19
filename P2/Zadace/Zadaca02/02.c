
/*2.
Napisati program koji definira strukturu za zapis podataka o plovilima: proizvođač
(string), model (string), snaga u kWh (int) i cijena (float). Program inicijalizira podatke za
10 plovila, od korisnika traži podatke o maksimalnoj snazi i minimalnoj cijeni vozila koje
korisnik traži te mu ispisuje podatke o svim vozilima koja zadovoljavaju unesene
podatke.
*/
#include <stdio.h>
#include <string.h>

struct plovila
{
    char proizvodac[32];
    char model[32];
    int snaga;
    float cijena;
};

void unosPodataka(int maxSnaga, float minCijena, struct plovila p[], int n);

int main()
{
    struct plovila p[5] = {
        {"Bmw", "m5", 200, 30000},
        {"Bentley", "Bentayga", 400, 100000},
        {"Audi", "q8", 90, 20000},
        {"Lamborghini", "Huracan", 300, 200000},
        {"Mercedes", "CLS", 150, 45000}};

    int maxSnaga;
    float minCijena;

    printf("Unesite maksimalnu snagu vozila: ");
    scanf("%d", &maxSnaga);
    printf("Unesite minimalnu cijenu vozila: ");
    scanf("%f", &minCijena);

    unosPodataka(maxSnaga, minCijena, p, 5);

    return 0;
}

void unosPodataka(int maxSnaga, float minCijena, struct plovila p[], int n)
{
    printf("\nVozila sa snagom do %d kW i cijenom vecom od %.2f:\n", maxSnaga, minCijena);
    for (int i = 0; i < n; ++i)
    {
        if (p[i].snaga <= maxSnaga && p[i].cijena >= minCijena)
        {
            printf("Proizvodac: %s, Model: %s, Snaga: %d kW, Cijena: %.2f EUR\n",
                   p[i].proizvodac, p[i].model, p[i].snaga, p[i].cijena);
        }
    }
}
