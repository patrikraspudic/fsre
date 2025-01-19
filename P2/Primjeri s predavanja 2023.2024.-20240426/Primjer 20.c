/* primjer pokazuje osnove dinamickog zauzimanja/alokacije memorije (DMA) */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *pInt = NULL;
	
	if(pInt != NULL)
		printf("Pokazivac *pInt pokazuje na adresu %d na kojoj je vrijednost %d.\n", pInt, *pInt);
	else
		printf("Pokazivac *pInt ima vrijednost NULL, tj. ne pokazuje ni na sta.\n");
		
	printf("\nKada nam memorija zatreba dinamicki je zauzimamo.\n");
	pInt = (int *)malloc(sizeof(int));
	if(pInt != NULL)
		printf("Pokazivac *pInt pokazuje na adresu %d na kojoj je vrijednost %d.\n", pInt, *pInt);
	else
		printf("Pokazivac *pInt ima vrijednost NULL, tj. ne pokazuje ni na sta.\n");
	
	printf("\nNa dodijeljenu adresu spremam vrijednost 100.\n");
	*pInt = 100;
	if(pInt != NULL)
		printf("Pokazivac *pInt pokazuje na adresu %d na kojoj je vrijednost %d.\n", pInt, *pInt);
	else
		printf("Pokazivac *pInt ima vrijednost NULL, tj. ne pokazuje ni na sta.\n");
	
	printf("\nKoju vrijednost zelis pohraniti na dodijeljenu adresu: ");
	scanf("%d", pInt);
	if(pInt != NULL)
		printf("Pokazivac *pInt pokazuje na adresu %d na kojoj je vrijednost %d.\n", pInt, *pInt);
	else
		printf("Pokazivac *pInt ima vrijednost NULL, tj. ne pokazuje ni na sta.\n");

	printf("\nKada nam memorija vise ne treba oslobadjamo ju.\n");
	free(pInt);
	pInt = NULL;
	if(pInt != NULL)
		printf("Pokazivac *pInt pokazuje na adresu %d na kojoj je vrijednost %d.\n", pInt, *pInt);
	else
		printf("Pokazivac *pInt ima vrijednost NULL, tj. ne pokazuje ni na sta.\n");
	
	
	return 0;
}
