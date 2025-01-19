/* primjer pokazuje vezu niza i pokazivaca na prvi clan niza 
   te aritemtiku pokazivaca */

#include <stdio.h>

int main() 
{
	int niz[5] = {10, 20, 30, 40, 50};
	int *pNiz = niz; 		/* ekvivalentno instrukciji pNiz = niz[0]; */
	int i;
	
	printf("Pokazivac *pNiz pokazuje na adresu %d.", pNiz);
	
	puts("\n\nElementi niza (niz uz sintaksu niza):");
	for(i = 0; i < 5; i++)
		printf("%d ", niz[i]);

	puts("\n\nElementi niza (pokazivac uz sintaksu pokazivaca):");
	for(i = 0; i < 5; i++)
		printf("%d ", *(pNiz + i));

	puts("\n\nElementi niza (niz uz sintaksu pokazivaca):");
	for(i = 0; i < 5; i++)
		printf("%d ", *(niz + i));	

	puts("\n\nElementi niza (pokazivac uz sintaksu niza):");
	for(i = 0; i < 5; i++)
		printf("%d ", pNiz[i]);
		
	/* pNiz je varijabla koja moze mijenjati vrijednost */ 
	pNiz = &i;
	/* ime niza niz je pokazivacka konstanta koja ne moze mijenjati vrijednost 
	niz = &i; /*/
	printf("\n\nPokazivac *pNiz pokazuje na adresu %d.", pNiz);
	
	return 0;
}
