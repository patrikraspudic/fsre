/* primjer pokazuje da se niz u funkciju uvijek prenosi po adresi i da su
   sve promjene vidljive i nakon povratka iz funkcije
   primjer sortira inicijalizirani niz cijelih brojeva */ 

#include <stdio.h>

void ispis(int niz[10]);
void sortiranje(int niz[10]);

int main() 
{
	int niz[10] = {11, -6, 22, 43, 61, 128, 5, 18, -22, 0};
	
	printf("Prije sortiranja: ");
	/* proslijedjivanje niza u funkciju izvodi se navodjenjem samo imena niza
	   bez ugladih zagrada i indeksa*/
	ispis(niz);
	
	sortiranje(niz);
	
	printf("Poslije sortiranja: ");
	ispis(niz);
	
	return 0;
}

void ispis(int niz[10])
{
	int i;
	
	for(i = 0; i < 10; i++)
	{
		printf("%d ", niz[i]);
	}
	printf("\n");
}

void sortiranje(int niz[10])
{
	int i, j, pom;
	
	for(i = 0; i < 9; i++)
	{
		for(j = i + 1; j < 10; j++)
		{
			if(niz[i] > niz[j])
			{
				pom = niz[i];
				niz[i] = niz[j];
				niz[j] = pom;
			}
		}
	}
}
