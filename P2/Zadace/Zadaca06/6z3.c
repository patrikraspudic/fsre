/*
3. Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
dio (float) i iz datoteke kompleksni_brojevi.txt čita podatke za 10 kompleksnih brojeva i
smješta ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon toga
unosi se dodatni kompleksni broj i ispisuje onaj od učitanih kompleksnih brojeva koji je
od dodatnog broja najudaljeniji u kompleksnoj ravnini.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct kompleksni
{
    float realni_dio;
    float imaginarni_dio;
    float udaljenost;
};

int main()
{
    struct kompleksni *broj, pomocni;
    int i = 0, j = 0;
    char pomocna[2];
    float max = 0, temp;
    FILE *dat;
    broj = (struct kompleksni *)malloc(sizeof(struct kompleksni) * 10);
    dat = fopen("kompleksni_brojevi.txt", "r");
    while (!feof(dat))
    {
        fscanf(dat, "%f %f %s", &(broj + i)->realni_dio, &(broj + i)->imaginarni_dio, pomocna);
        i++;
        if (i == 10)
            break;
    }
    for (i = 0; i < 10; i++)
    {
        (broj + i)->udaljenost = sqrt(pow((broj + i)->realni_dio, 2) + pow((broj + i)->imaginarni_dio, 2));
    }
    printf("Unesi realni dio pomocnog broja: ");
    scanf("%f", &pomocni.realni_dio);
    printf("Unesi kompleksni dio pomocnog broja: ");
    scanf("%f", &pomocni.imaginarni_dio);
    pomocni.udaljenost = sqrt(pow(pomocni.realni_dio, 2) + pow(pomocni.imaginarni_dio, 2));
    for (i = 0; i < 10; i++)
    {
        if (pomocni.udaljenost < ((broj + i)->udaljenost))
            temp = (broj + i)->udaljenost - pomocni.udaljenost;
        else
            temp = pomocni.udaljenost - (broj + i)->udaljenost;
        if (temp > max)
        {
            max = temp;
            j = i;
        }
    }
    printf("To je broj %f + %fi\n", (broj + j)->realni_dio, (broj + j)->imaginarni_dio);
    free(broj);
    fclose(dat);
    return 0;
}