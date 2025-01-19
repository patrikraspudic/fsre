/* primjer pokazuje vezu pokazivaca i strukture */

#include <stdio.h>

struct Test
{
	char tekst[32];
	int broj;
};

int main() 
{
	struct Test T = {"Danas je cetvrtak.", 16}, *pTest;

	pTest = &T;
	printf("Struktura T nalazi se na adresi %d.\n", &T);
	printf("Pokazivac pTest pokazuje na adresu %d.\n", pTest);

	printf("\nStruktura T se sastoji od tekstualnog i cjelobrojenog podatka.\n");
	printf("Tekstualni podatak je \"%s\".\n", T.tekst);
	printf("Cjelobrojni podatak je %d.\n", T.broj);
	
	printf("\nPristup elementima strukture preko pokazivaca:\n");
	printf("Tekstualni podatak je \"%s\".\n", pTest->tekst);
	printf("Cjelobrojni podatak je %d.\n", pTest->broj);

	return 0;
}
