/* primjer pokaztuje osnove rada s pokazivacima i razliku izmedju 
   pX = pY; i *pX = *pY;*/

#include <stdio.h>

int main() 
{
	int x = 10, y = 20, *pX = &x, *pY = &y;
	
	printf("Pocetna situacija:\n");
	printf("Varijabla x nalazi se na adresi %d i ima vrijednost %d.\n", &x, x);
	printf("Varijabla y nalazi se na adresi %d i ima vrijednost %d.\n", &y, y);
	printf("Pokazivac *pX pokazuje na adresu %d na kojoj je vrijednost %d.\n", pX, *pX);
	printf("Pokazivac *pY pokazuje na adresu %d na kojoj je vrijednost %d.\n", pY, *pY);
	printf("Pri tome je x = %d, a y = %d.\n", x, y);
	
	pX = pY;
	printf("\nNakon pX = pY:\n");
	printf("Varijabla x nalazi se na adresi %d i ima vrijednost %d.\n", &x, x);
	printf("Varijabla y nalazi se na adresi %d i ima vrijednost %d.\n", &y, y);
	printf("Pokazivac *pX pokazuje na adresu %d na kojoj je vrijednost %d.\n", pX, *pX);
	printf("Pokazivac *pY pokazuje na adresu %d na kojoj je vrijednost %d.\n", pY, *pY);
	printf("Pri tome je x = %d, a y = %d.\n", x, y); 
	
	pX = &x;
	pY = &y;
	printf("\nPovratak na pocetnu situaciju:\n");
	printf("Varijabla x nalazi se na adresi %d i ima vrijednost %d.\n", &x, x);
	printf("Varijabla y nalazi se na adresi %d i ima vrijednost %d.\n", &y, y);
	printf("Pokazivac *pX pokazuje na adresu %d na kojoj je vrijednost %d.\n", pX, *pX);
	printf("Pokazivac *pY pokazuje na adresu %d na kojoj je vrijednost %d.\n", pY, *pY);
	printf("Pri tome je x = %d, a y = %d.\n", x, y);	
	
	*pX = *pY;
	printf("\nNakon *pX = *pY:\n");
	printf("Varijabla x nalazi se na adresi %d i ima vrijednost %d.\n", &x, x);
	printf("Varijabla y nalazi se na adresi %d i ima vrijednost %d.\n", &y, y);
	printf("Pokazivac *pX pokazuje na adresu %d na kojoj je vrijednost %d.\n", pX, *pX);
	printf("Pokazivac *pY pokazuje na adresu %d na kojoj je vrijednost %d.\n", pY, *pY);
	printf("Pri tome je x = %d, a y = %d.\n", x, y); 
	
	return 0;
}
