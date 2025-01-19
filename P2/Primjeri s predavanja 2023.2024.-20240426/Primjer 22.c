/* primjer pokazuje realoociranje memorije u situaciji kada pocetno
   zauzeta memorija nije odgovarajuce velicine 
   primjer unosi cijele brojeve sve dok njihov zbroj ne predje 100
   i zatim ispisuje njihov prosjek */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int *pInt = NULL, zbroj = 0, i = 0;
	float prosjek;
		
	puts("Unosi cijele brojeve dok im zbroj ne predje 100:");
	do
	{
		pInt = (int *)realloc(pInt, sizeof(int) * (i + 1) * 100);
		printf("Pokazivac pInt pokazuje na adresu %d.\n", pInt);
		scanf("%d", (pInt + i));
		zbroj += *(pInt + i);
		i++;
	}
	while(zbroj <= 100);
	
	free(pInt);
	
	printf("\nNakon %d unesenih brojeva zbroj je %d.\n", i, zbroj);
	prosjek = (float) zbroj / i;
	printf("Njihov prosjek je %.2f.\n", prosjek);
	return 0;
}
