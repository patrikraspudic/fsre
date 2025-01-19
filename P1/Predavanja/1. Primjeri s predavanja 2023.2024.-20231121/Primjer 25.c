/* Napravi rekurzivnu funkciju koja za proslijedjeni niz cijelih brojeva
provjera radi li se o silazno sortiranom nizu prostih brojeva. */
#include <stdio.h>
int je_li_prost(int broj);
int silazni_niz_prostih_brojeva(int niz[10], int n);

int main() 
{
	int niz[10] = {79, 67, 59, 47, 43, 37, 31, 29, 23, 17};
	
	printf("Proslijedjeni niz ");
	if(silazni_niz_prostih_brojeva(niz, 10) == 1)
	{
		printf("je ");
	}
	else
	{
		printf("nije ");
	}
	printf("silazni niz prostih brojeva.\n");
	

	return 0;
}

int je_li_prost(int broj)
{
	int rezultat = 1, i;
	
	for(i = 2; i < broj; i++)
	{
		if(broj % i == 0)
		{
			rezultat = 0;
		}
	}
	
	return rezultat;
}

int silazni_niz_prostih_brojeva(int niz[10], int n)
{
	if(je_li_prost(niz[n - 1]) == 0)
	{
		return 0;
	}
	else
	{
		if(n == 1)
		{
			return 1;
		}
		else
		{
			if(niz[n - 1] > niz[n - 2])
			{
				return 0;
			}
			else
			{
				return silazni_niz_prostih_brojeva(niz, n - 1);
			}
		}
	}
}
