/*1.
Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjereni
vodostaji (realni brojevi) na određenom mjernom mjestu tijekom vremena. Pročitati sve
vodostaje i odrediti prosječan vodostaj na tom mjernom mjestu.
*/
#include <stdio.h>
#include <string.h>
int main()
{
    FILE *dat;
    char unos[32], mjesto[32];
    int i = 0;
    float vodostaj[8], zbroj = 0, prosjek;

    printf("Unesite naziv datoteke:\n");
    fflush(stdin);
    scanf("%s", unos);

    dat = fopen(unos, "r");
    if (dat == NULL)
    {
        printf("Pogreska pri otvaranju datoteke.\n");
    }
    else
    {
        fscanf(dat, "%s", mjesto);
        while (!feof(dat))
        {
            fscanf(dat, "%f", &vodostaj[i]);
            i++;
        }
        for (i = 0; i < 8; i++)
            zbroj = zbroj + vodostaj[i];
    }
    prosjek = zbroj / 8;
    printf("Prosjek vodostaja za %s je %f", mjesto, prosjek);
    return 0;
}
