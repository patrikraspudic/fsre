/* primjer pokazuje rad DO-WHILE petlje
   primjer unosi cijele brojeve sve dok njihov zbroj na predje 
   100 i nakon toga ispisuje njihov prosjek uz kontrolu deklarirane
   dimenzije niza brojeva */

#include <stdio.h>

int main() 
{
	int broj[20], zbroj = 0, i = 0;
	float prosjek;

	printf("Unosi brojeve dok im zbroj ne predje 100:\n");
	
	/* DO-WHILE petlja s naknadnim ispitivanjem uvjeta */
	do
	{
		scanf("%d", &broj[i]);
		zbroj = zbroj + broj[i];
		i++;
	}
	while((zbroj <= 100) && (i < 20));	/* slozeni uvjet - konjukcija dva jednostavna uvjeta */
	
	if((i == 20) && (zbroj <= 100))
	{
		printf("Prekid unosa zbog popunjavanja niza.\n");
		printf("Nakon %d unesenih brojeva zbroj iznosi %d.\n", i, zbroj);
	}
	else
	{
		printf("Nakon %d unesenih brojeva zbroj je veci od 100 i iznosi %d.\n", 
		i, zbroj);
	}
	
	prosjek = (float)zbroj / i; /*casting */
	printf("Njihov prosjek je %f.\n", prosjek);
	
	
	return 0;
}
