/*
Napravi program koji u funkciji unos() unosi 7 realnih brojeva, 
zatim u funkciji racun() pronalazi najmanji i najveći uneseni broj i 
ispisuje ih u glavnom programu,
a u funkciji ispis() ispisuje sve unesene brojeve 
koji su od prosjeka udaljeni za manje od 2.
*/
#include<stdio.h>
void unos(float niz[7],int *i);
void racun(float niz[7],int i, float *najmanji, float *najveci);
void ispis(float niz[7],int i);
int main()
{
    float niz[7],najmanji,najveci;
    int i;
    unos(niz,&i);
    racun(niz,i,&najmanji,&najveci);
    printf("Najmanji broj:%f\n",najmanji);
    printf("Najveci broj:%f\n",najveci);
    ispis(niz,i);
    return 0;
}
void unos(float niz[7],int *i)
{
    printf("Unesite 7 brojeva\n");
    for(*i = 0;*i < 7;(*i)++)
    {
        scanf("%f", &niz[*i]);
    }
}
void racun(float niz[7],int i, float *najmanji, float *najveci)
{
    int j;
    *najmanji = niz[0];
    *najveci = niz[0];
    for(j = 1;j < i;j++)
    {
        if(*najmanji > niz[j])
        {
            *najmanji = niz[j];
        }
        if(*najveci < niz[j])
        {
            *najveci = niz[j];
        }
    }
}
void ispis(float niz[7],int i)
{
    float prosjek = 0;
    float zbroj = 0;
    int brojac = 0,j;
    for(j = 0;j < i;j++)
    {
        zbroj = zbroj + niz[j];
    }
    prosjek = zbroj / i;
    printf("Brojevi su od prosjeka udaljeni za mnaje od 2:\n");
    for(j = 0;j < i;j++)
    {
        if(prosjek - niz[j] < 2 && niz[j] - prosjek < 2)
        {
            printf("%.2f\n",niz[j]);
        }
    }
}   

