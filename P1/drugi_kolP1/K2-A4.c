/*Napravi program koji unosi realne brojeve sve dok se dva puta zaredom 
ne unese broj sa istim decimalnim dijelom (npr. 4.55 i 16.55), 
a zatim u funkciji obrada_podataka() izračunava zbroj
svih unesenih brojeva i pronalazi najmanji uneseni broj. 
Rezultati se ispisuju u glavnom programu.*/
#include<stdio.h>
void obrada_podataka(float niz[100],float *zbroj,int i,float *najmanji);
int main()
{
    float niz[100],zbroj,najmanji;
    int i = 0;
    do 
    {
        scanf("%f", &niz[i]);
        i++;
    }while((i < 2)  || ((niz[i - 1] - (int)niz[i - 1]) != (niz[i - 2] - (int)niz[i - 2]))
                    || ((niz[i - 1] - (int)niz[i - 1]) != (niz[i - 2] - (int)niz[i - 2])));
    
    obrada_podataka(niz,&zbroj,i,&najmanji);
    printf("Zbroj:%f\n",zbroj);
    printf("Najmanji:%f\n",najmanji);
    return 0;
}
void obrada_podataka(float niz[100],float *zbroj,int i,float *najmanji)
{
    int j;
    *zbroj = 0;
    *najmanji = niz[0];
    for(j = 0;j < i;j++)
    {
        *zbroj = *zbroj + niz[j];
        if(*najmanji > niz[j])
        {
            *najmanji = niz[j];
        }
    }
}