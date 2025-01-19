/*Napravi program koji unosi 40 realnih brojeva, a zatim 
u funkciji broj_vecih_od_prvog _broja()
računa koliko je uneseno realnih brojeva većih od prvog unesenog broja. 
Rezultat se ispisuje u glavnom programu.*/
#include <stdio.h>

int broj_vecih_od_prvog_broja(float niz[40]);

int main() 
{
	float niz[40];
	int i;
	
	printf("Unesi 40 realnih brojeva:\n");
	for(i = 0; i < 40; i++)
	{
		scanf("%f", &niz[i]);
	}
	
	printf("Uneseno je %d brojeva vecih od prvog broja.\n", broj_vecih_od_prvog_broja(niz));
	
	/* kraj */
	return 0;
}

int broj_vecih_od_prvog_broja(float niz[40])
{
	int i, brojac = 0;
	
	for(i = 0; i < 40; i++)
	{
		if(niz[i] > niz[0])
		{
			brojac++;
		}
	}
	return brojac;
}
