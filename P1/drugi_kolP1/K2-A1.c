/*Napravi program koji unosi cijele brojeve sve dok se ne unese broj 0,
a zatim u funkciji broj_prostih() računa koliko je uneseno prostih brojeva. 
Rezultat se ispisuje u glavnom programu.*/
#include <stdio.h>

int broj_prostih(int niz[100], int i);

int main() 
{
	int niz[100], i = 0;
	
	printf("Unosi cijele brojeve (0 za kraj):\n");
	do
	{
		scanf("%d", &niz[i]);
		i++;
	}
	while(niz[i - 1] != 0);
	
	printf("Uneseno je %d prostih brojeva.\n", broj_prostih(niz, i));
	
	/* kraj */
	return 0;
}

int broj_prostih(int niz[100], int i)
{
	int j, k, brojac = 0, prost;
	
	for(j = 0; j < i - 1; j++)		/* zadnji broj je 0 kojeg ne uzimamo u obzir */
	{
		prost = 1;
		for(k = 2; k < niz[j]; k++)
		{
			if(niz[j] % k == 0)
			{
				prost = 0;
			}
		}
		if(prost == 1 && niz[j] > 1)
		{
			brojac++;
		}
	}
	return brojac;
}
