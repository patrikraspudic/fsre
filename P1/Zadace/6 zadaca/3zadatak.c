/*Patrik Raspudic 2233/rr*/
/*Napisati program koji u funkciji unos() unosi 5 cijelih brojeva, u funkciji plus_minus()
raspoređuje ih u dva niza brojeva, tj. pozitivne smješta u jedan, a negativne u drugi niz.
Oba niza ispisuju se u glavnom programu*/
#include<stdio.h>
void unos(int niz[5]);
void plus_minus(int niz[5],int pozitivni[5], int negativni[5], int *broj_pozitivnih, int *broj_negativnih);
int main()
{
	int niz[5],i;
	int pozitivni[5],negativni[5];
	int broj_pozitivnih, broj_negativnih;
	
	unos(niz);
	plus_minus(niz,pozitivni,negativni,&broj_negativnih,&broj_pozitivnih);

	printf("Pozitivni brojevi: ");
	for(i = 0;i < broj_pozitivnih;i++)
	{
		printf("%d ", pozitivni[i]);
	}

	printf("\nNegativni brojevi: ");
	for(i = 0;i < broj_negativnih; i++)
	{
		printf("%d ", negativni[i]);
	}
	return 0;
}
void unos(int niz[5])
{
	int i;
	printf("Unesite 5 brojeva\n");
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&niz[i]);
	}
}
void plus_minus(int niz[5],int pozitivni[5], int negativni[5], int *broj_pozitivnih, int *broj_negativnih)
{
	int i;
	*broj_pozitivnih = 0;
	*broj_negativnih = 0;
	for(i = 0;i < 5; i++)
	{
		if(niz[i] > 0)
		{
			pozitivni[*broj_pozitivnih] = niz[i];
			(*broj_pozitivnih)++;
		}
		else
		{
			negativni[*broj_negativnih] = niz[i];
			(*broj_negativnih)++;
		}
	}
}