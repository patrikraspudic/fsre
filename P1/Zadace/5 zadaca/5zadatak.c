/*Patrik Raspudić 2233/RR*/
#include <stdio.h>

int je_li_sortiran(char niz[10], int index);

int main()
{
    char znak[10];
    int boolean;

    printf("Unesite 10 znakova: ");
    for(int i = 0; i < 10; i++)
        scanf(" %c", &znak[i]);

    boolean = je_li_sortiran(znak, 0);

    if(boolean == 1)
        printf("Niz je sortiran silazno.\n");
    else
        printf("Niz nije sortiran silazno.\n");

    return 0;
}

int je_li_sortiran(char niz[10], int index)
{
    if(index == 9)
        return 1;
    else if(niz[index] < niz[index + 1])
        return 0;
    else
        return je_li_sortiran(niz, index + 1);
}
