/* primjer pokazuje rad s FOR petljom i nizom 
   primjer unosi 10 cijelih brojeva i ispisuje njihov zbroj */

#include <stdio.h>

int main() 
{
	int broj[10], zbroj = 0, i;
	
	printf("Unesi 10 cijelih brojeva:\n");
	
	/* FOR petlja */
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &broj[i]);
		zbroj = zbroj + broj[i];	// alternativno: zbroj += broj[i];
	}

	printf("Zbroj unesenih brojeva je %d.\n", zbroj);

	return 0;
}
