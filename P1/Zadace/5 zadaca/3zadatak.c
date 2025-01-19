/*Patrik Raspudić 2233/RR*/
#include <stdio.h>
#include <math.h>

void unos (float niz[8]);
void par_najblizih(float niz[8], float *x, float *y);

int main ()
{
    float niz[8];
    float lijevi, desni;

    unos(niz);
    par_najblizih(niz, &lijevi, &desni);

    printf("2 najbliza broja su %f i %f ", lijevi, desni);

}

void unos (float niz[8])
    {
        for (int i=0;i<8;i++)
            scanf(" %f", &niz[i]);
    }

void par_najblizih(float niz[8], float *x, float *y)
    {
        float apsolutnamin = fabs(niz[0] - niz[1]);
        *x = niz[0]; *y = niz[1];

        for (int i = 0; i < 7; i++)
        {
            for (int j = i + 1; j < 8; j++)
            {
                float apsolutna = fabs(niz[i] - niz[j]);
                if (apsolutna < apsolutnamin)
                {
                    apsolutnamin = apsolutna;
                    *x = niz[i]; *y = niz[j];
                }
            }
        }
    }
