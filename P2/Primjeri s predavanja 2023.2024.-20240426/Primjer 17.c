/* primjer pokaztuje osnove rada s pokazivacima */

#include <stdio.h>

int main() 
{
	int x = 10, *pX;
	float pi = 3.14159, *pPi;
	char z = '*', *pZ;
	
	pX = &x;
	printf("Varijabla x nalazi se na adresi %d i ima vrijednost %d.\n", &x, x);
	printf("Pokazivac *px pokazuje na adresu %d na kojoj je vrijednost %d.\n", pX, *pX);
	printf("Pokazivac *px zauzima %d bajta.\n\n", sizeof(pX));
	
	pPi = &pi;
	printf("Varijabla pi nalazi se na adresi %d i ima vrijednost %f.\n", &pi, pi);
	printf("Pokazivac *pPi pokazuje na adresu %d na kojoj je vrijednost %f.\n", pPi, *pPi);
	printf("Pokazivac *pPi zauzima %d bajta.\n\n", sizeof(pPi));
	
	pZ = &z;
	printf("Varijabla z nalazi se na adresi %d i ima vrijednost %c.\n", &z, z);
	printf("Pokazivac *pZ pokazuje na adresu %d na kojoj je vrijednost %c.\n", pZ, *pZ);
	printf("Pokazivac *pZ zauzima %d bajta.\n\n", sizeof(pZ));
	 
	return 0;
}
