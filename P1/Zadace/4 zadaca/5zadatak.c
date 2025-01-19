#include <stdio.h>

void sortiraj(float niz[], int velicina);
float cetvrti_po_velicini(float niz[], int velicina);
void ispis(float broj);

int main()
{
    float niz[5];
    float cetvrti;

    printf("Unesite pet realnih brojeva:\n");
    for (int i = 0; i < 5; i++)
        scanf_s("%f", &niz[i]);

    sortiraj(niz, 5);
    cetvrti = cetvrti_po_velicini(niz, 5);
    ispis(cetvrti);

    return 0;
}

void sortiraj(float niz[], int velicina)
{
    for (int i = 0; i < velicina - 1; i++)
    {
        for (int j = 0; j < velicina - 1 - i; j++)
        {
            if (niz[j] < niz[j + 1])
            {
                float temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
        }
    }
}

float cetvrti_po_velicini(float niz[], int velicina)
{
    return niz[3];
}

void ispis(float broj)
{
    int cijeli_dio = (int)broj;
    printf("Cetvrti broj po velicini je: %f\n", broj);
    printf("Ispisujem ga %d puta:\n", cijeli_dio);
    for (int i = 0; i < cijeli_dio; i++)
        printf("%f ", broj);
    printf("\n");
}
