/*Patrik Raspudic 2233/rr*/
/*Napisati program koji unosi 5 znakova i rekurzivnom funkcijom jesu_li_mala_slova()
provjerava jesu li svi unesenih znakovi mala slova engleskog alfabeta. Rezultat se ispisuje
u glavnom programu.*/

#include<stdio.h>
int jesu_li_mala_slova(char znak[5],int i);
int main()
{
	char znak[5];
	int i;
	printf("Unesite 5 znakova\n");
	for(i = 0;i < 5;i++)
	{
		fflush(stdin);
		scanf("%c",&znak[i]);
	}
	if(jesu_li_mala_slova(znak,4))
	{
		printf("Unesena su samo mala slova\n");
	}
	else
	{
		printf("Uneseni su i drugi znakovi\n");
	}
	return 0;
}
int jesu_li_mala_slova(char znak[5],int i)
{
	if(i == -1)
	{
		return 1;
	}
	if(znak[i] >= 'a' && znak[i] <= 'z')
	{
		return jesu_li_mala_slova(znak,i - 1);
	}
	else
	{
		return 0;
	}

}	