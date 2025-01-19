#include <stdio.h>

void ispis_manjih_od_prosjeka(float niz[100], int i, float zbroj);

int main()
{
    float niz[100];
    int i = 0;
    float zbroj = 0;

    printf("Unesite neki broj: ");
    scanf_s(" %f", &niz[i]);
    zbroj += niz[i];
    i++;

    do
    {
        printf("Unesite neki broj: ");
        scanf_s(" %f", &niz[i]);
        zbroj += niz[i];
        i++;
    } while (!(niz[i - 1] > (zbroj - niz[i - 1])));

    ispis_manjih_od_prosjeka(niz, i, zbroj);

    return 0;
}

void ispis_manjih_od_prosjeka(float niz[100], int i, float zbroj)
{
    float prosjek = zbroj / i;
    for (int j = 0;j < i;j++)
    {
        if (niz[j] < prosjek)
            printf("%f ", niz[j]);
    }
}
