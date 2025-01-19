/* primjer pokazuje dinamicko zauzimanje memorije za pohranjivanje niza podataka */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int broj, *pNiz = NULL, i;
	
	printf("Koliko imas cijelih brojeva: ");
	scanf("%d", &broj);
	
	/* dinamicko zauzimanje memorije za niz cijelih brojeva */
	pNiz = (int *) malloc(sizeof(int) * broj);
	
	printf("\nUnesi %d cijelih brojeva:\n", broj);
	for(i = 0; i < broj; i++)
		scanf("%d", (pNiz + i));
		
	printf("\nUneseni brojevi su: ");
	for(i = 0; i < broj; i++)
		printf("%d ", *(pNiz + i));
	printf("\n");
	
	free(pNiz);
	
	return 0;
}
