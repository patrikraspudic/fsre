/*4.
Napisati program koji definira strukturu za zapis podataka o životinjama: vrsta životinje,
broj noga, boja, očekivana dužina živoota. Program inicijalizira podatke za 10 životinja i
ispisuje ih sortirane po očekivanoj dužini života (uzlazno), odnosno po broju noga
(silazno) ako je očekivana dužina života ista.
*/
#include <stdio.h>
struct zivotinje
{
    char vrsta[32];
    int brojNoga;
    char boja[16];
    float duzinaZivota;
};
int main()
{
    struct zivotinje z[10] =
        {
            {"pas", 4, "smeda", 15},
            {"macka", 4, "bijela", 12},
            {"slon", 4, "siva", 60},
            {"ptica", 2, "crna", 7},
            {"riba", 0, "crvena", 5},
            {"medvjed", 4, "smeda", 25},
            {"kit", 0, "plava", 70},
            {"kornjaca", 4, "zelena", 100},
            {"nilski konj", 4, "siva", 35},
            {"orangutan", 2, "crvenkastosmeda", 40}},
                     pZ;
    int i, j;

    for (i = 0; i < 9; i++)
        for (j = i + 1; j < 10; j++)
            if ((z[i].duzinaZivota > z[j].duzinaZivota) ||
                (z[i].duzinaZivota == z[j].duzinaZivota) && (z[i].brojNoga < z[j].brojNoga))
            {
                pZ = z[i];
                z[i] = z[j];
                z[j] = pZ;
            }

    puts("Sortirane zivotinje:");
    for (i = 0; i < 10; i++)
        printf("%s\n %.2f\n %d\n", z[i].vrsta, z[i].duzinaZivota, z[i].brojNoga);

    return 0;
}