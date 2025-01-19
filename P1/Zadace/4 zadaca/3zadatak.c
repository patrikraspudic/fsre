#include <stdio.h>
#include<math.h>

int unos(int niz[7]);
float izracunaj_prosjek(int zbroj);
void pronadji_najdalji(int niz[7], float prosjek);

int main()
{
    int niz[7], zbroj = 0;
    float prosjek;

    zbroj = unos(niz);
    prosjek = izracunaj_prosjek(zbroj);
    pronadji_najdalji(niz, prosjek);

    return 0;
}

int unos(int niz[7])
{
    int zbroj = 0;
    for (int i = 0; i < 7; i++)
    {
        printf("Unesite %d. broj: ", i + 1);
        scanf_s("%d", &niz[i]);
        zbroj += niz[i];
    }
    return zbroj;
}

float izracunaj_prosjek(int zbroj)
{
    return zbroj / 7.0;
}

void pronadji_najdalji(int niz[7], float prosjek)
{
    int indeks_najdaljeg = 0;
    float najveca_razlika = fabs(prosjek - niz[0]);

    for (int i = 1; i < 7; i++)
    {
        float razlika = fabs(prosjek - niz[i]);
        if (razlika > najveca_razlika)
        {
            najveca_razlika = razlika;
            indeks_najdaljeg = i;
        }
    }

    printf("Prosjek je %f, najudaljeniji broj je %d, razlika je %f\n", prosjek, niz[indeks_najdaljeg], najveca_razlika);
}
