/* primjer pokaztuje rad s nizom pokazivaca */

#include <stdio.h>

int main() 
{
	int niz[10] = {21, -45, 8, 124, -35, 55, 78, -128, 3, 11};
	int *pNiz[10], i, j, *pom;
	
	printf("Elementi niza su: ");
	for(i = 0; i < 10; i++)
		printf("%d ", niz[i]);
	printf("\n");
	
	/* povezivanje elemenata niza pokazivaca i elemenata niza cijelih brojeva */
	for(i = 0; i < 10; i++)
		pNiz[i] = &niz[i];
		
	printf("\nElementi niza (preko pokazivaca prije preslagivanja) su: ");
	for(i = 0; i < 10; i++)
		printf("%d ", *pNiz[i]);
	printf("\n");
		
	/* preslagivanje niza pokazivaca kako bi redom pokazivali na sortirane brojeve */
	for(i = 0; i < 9; i++)
		for(j = i + 1; j < 10; j++)
			if(*pNiz[i] > *pNiz[j])
			{
				pom = pNiz[i];
				pNiz[i] = pNiz[j];
				pNiz[j] = pom;
			}

	printf("\nElementi niza (preko pokazivaca nakon preslagivanja) su: ");
	for(i = 0; i < 10; i++)
		printf("%d ", *pNiz[i]);
	printf("\n");

	printf("Elementi niza su: ");
	for(i = 0; i < 10; i++)
		printf("%d ", niz[i]);
	printf("\n");
	
	return 0;
}
