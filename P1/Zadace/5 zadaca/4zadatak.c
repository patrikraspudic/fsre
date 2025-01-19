/*Patrik Raspudić 2233/RR*/
#include <stdio.h>

int ima_li_5(int a);

int main()
{
    int a;
    printf("Unesite broj: ");
    scanf(" %d",&a);

    if (ima_li_5(a))
        printf("Broj %d sadrzi znamenku 5.\n", a);
    else
        printf("Broj %d ne sadrzi znamenku 5.\n", a);

    return 0;
}

int ima_li_5(int a)
{
    if(a==0)
       {
        return 0;
       } 
       else if(a==5)
       {
        return a;
       }
}
