/*Napravi program koji unosi 20 znakova i koristeći rekurzivnu funkciju 
jesu_li_suglasnici() provjerava sastoji li se uneseni niz 
isključivo od suglasnika (velikih i malih)*/
#include <stdio.h>

int jesu_li_suglasnici(char znak[], int i);

int main() {
    char znak[20];
    int i;
    
    printf("Unesite 20 znakova:\n");
    for(i = 0; i < 20; i++) {
        fflush(stdin);
        scanf("%c", &znak[i]);
    } 
    
    if(jesu_li_suglasnici(znak, 0)) {
        printf("U niz znak[] uneseni su samo suglasnici!\n");
    }
    else {
        printf("U nizu znak[] postoje znakovi koji nisu suglasnici!\n");
    }

    return 0;
}

int jesu_li_suglasnici(char znak[], int i) {
    if (i == 20) {
        return 1;
    }

    if (znak[i] == 'A' || znak[i] == 'E' || znak[i] == 'I' || znak[i] == 'O' || znak[i] == 'U' ||
        znak[i] == 'a' || znak[i] == 'e' || znak[i] == 'i' || znak[i] == 'o' || znak[i] == 'u') {
        return 0;
    }

    
    return jesu_li_suglasnici(znak, i + 1);
}

/*DOLE MENI DRAZI NACIN
#include<stdio.h>
int jesu_li_suglasnici(char znak[7],int i);
int main()
{
    char znak[7];
    int i;
    printf("Unesite 7 znakova\n");
    for(i = 0;i < 7;i++)
    {
        fflush(stdin);
        scanf("%c",&znak[i]);
    }
    if(jesu_li_suglasnici(znak,i))
    {
        printf("Da\n");
    }
    else
    {
        printf("Ne\n");
    }
    return 0;
}
int jesu_li_suglasnici(char znak[7],int i)
{
    if(i == 0)
    {
        return 1;
    }
    else
    {
        if(znak[i - 1] == 'A' || znak[i - 1] == 'E' || znak[i - 1] == 'I' || znak[i - 1] == 'O' || znak[i - 1] == 'U' 
        || znak[i - 1] == 'a' || znak[i - 1] == 'e' || znak[i - 1] == 'i' || znak[i - 1] == 'o' || znak[i - 1] == 'u')
        {
            return 0;
        }
        else
        {
            return jesu_li_suglasnici(znak,i - 1);
        }
    }
}
*/