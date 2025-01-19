/*Napravi program koji unosi 20 cijelih brojeva i 
koristeći rekurzivnu funkciju jesu_li_pozitivni()
provjerava sastoji li se uneseni niz isključivo od pozitivnih brojeva*/
#include<stdio.h>
int jesu_li_pozitivni(int niz[5],int i);
int main()
{
	int niz[5],i;
	printf("Unesite cijele brojeve\n");
	for(i = 0;i < 5;i++)
	{
		scanf("%d", &niz[i]);
	}
	if(jesu_li_pozitivni(niz,0))
	{
		printf("Pozitivni\n");
	}
	else
	{
		printf("I negativni\n");
	}
	return 0;
}
int jesu_li_pozitivni(int niz[5],int i)
{
	if(i == 5)
	{
		return 1;
	}
	if(niz[i] < 0)
	{
		return 0;
	}
	else
	{
		return jesu_li_pozitivni(niz,i + 1);
	}
}

/*DOLE MENI DRAZI NACIN
#include<stdio.h>
int jesu_li_pozitivni(int niz[7],int i);
int main()
{
    int niz[7],i;
    printf("Unesite 7 cijelih brojeva\n");
    for(i = 0;i < 7;i++)
    {
        scanf("%d",&niz[i]);
    }
    if(jesu_li_pozitivni(niz,i))
    {
        printf("da\n");
    }
    else
    {
        printf("ne\n");
    }
    return 0;
}
int jesu_li_pozitivni(int niz[7],int i)
{
    if(i == 0)
    {
        return 1;
    }
    else
    {
        if(niz[i - 1] < 0)
        {
            return 0;
        }
        else
        {
            return jesu_li_pozitivni(niz,i - 1);
        }
    }
}
*/