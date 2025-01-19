/*Napravi program koji unosi cijele brojeve sve dok se dva puta zaredom 
ne unese isti broj, a zatim u funkciji broj_slozenih() 
računa koliko je uneseno složenih brojeva (onih koji nisu prosti).
Rezultat se ispisuje u glavnom programu.*/

#include <stdio.h>

int broj_slozenih(int niz[100], int i);

int main() 
{
	int niz[100], i = 0;
	
	printf("Unosi cijele brojeve (dva ista za kraj):\n");
	do
	{
		scanf("%d", &niz[i]);
		i++;
	}
	while(niz[i - 1] != niz[i - 2]);
	
	printf("Uneseno je %d slozenih brojeva.\n", broj_slozenih(niz, i));
	
	/* kraj */
	return 0;
}

int broj_slozenih(int niz[100], int i)
{
	int j, k, brojac = 0, prost;
	
	for(j = 0; j < i; j++)
	{
		prost = 1;
		for(k = 2; k < niz[j]; k++)
		{
			if(niz[j] % k == 0)
			{
				prost = 0;
			}
		}
		if(prost == 0 && niz[j] > 2)
		{
			brojac++;
		}
	}
	return brojac;
}
