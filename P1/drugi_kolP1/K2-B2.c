/* Napravi program koji unosi 30 realnih brojeva, a zatim u funkciji
broj_manjih_od_zadnjeg_broja() računa koliko je unesenih realnih brojeva 
manjih od zadnjeg unesenog broja. 
Rezultat se ispisuje u glavnom programu. */
#include <stdio.h>

int broj_manjih_od_zadnjeg_broja(float niz[30]);

int main() 
{
	float niz[30];
	int i;
	
	printf("Unesi 30 realnih brojeva:\n");
	for(i = 0; i < 30; i++)
	{
		scanf("%f", &niz[i]);
	}
	
	printf("Uneseno je %d brojeva manjih od zadnjeg broja.\n", broj_manjih_od_zadnjeg_broja(niz));
	
	/* kraj */
	return 0;
}

int broj_manjih_od_zadnjeg_broja(float niz[30])
{
	int i, brojac = 0;
	
	for(i = 0; i < 30; i++)
	{
		if(niz[i] < niz[29])
		{
			brojac++;
		}
	}
	return brojac;
}
