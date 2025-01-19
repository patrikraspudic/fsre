/* primjer pokazuje razliku izmedju prijenosa podataka u funkciju po vrijednosti
  i po adresi
  primjer inicijalizira dva cijela broja i u funkcijama zamijeni_1() i zamijeni_2()
  im zamijenjuje vrijednosti uz prijenos po vrijednosti i po adresi */

#include <stdio.h>

void zamijeni_1(int x, int y);
void zamijeni_2(int *x, int *y);

int main() 
{
	int x = 10, y = 20;
	
	printf("Prije poziva funkcije zamijeni_1(): x = %d, y = %d \n", x, y);
	
	/* prijenos podataka u funkciju zamijeni_1() po vrijednosti */
	zamijeni_1(x, y);
	printf("Poslije poziva funkcije zamijeni_1(): x = %d, y = %d \n", x, y);

	/* prijenos podataka u funkciju zamijeni_2() po adresi */
	zamijeni_2(&x, &y);
	printf("Poslije poziva funkcije zamijeni_2(): x = %d, y = %d \n", x, y);
	
	return 0;
}

void zamijeni_1(int x, int y)
{
	int pom;
	
	pom = x;
	x = y;
	y = pom;
	printf("Unutar funkcije zamijeni_1(): x = %d, y = %d \n", x, y);
}

void zamijeni_2(int *x, int *y)
{
	int pom;
	
	pom = *x;
	*x = *y;
	*y = pom;
	printf("Unutar funkcije zamijeni_2(): x = %d, y = %d \n", *x, *y);
}
