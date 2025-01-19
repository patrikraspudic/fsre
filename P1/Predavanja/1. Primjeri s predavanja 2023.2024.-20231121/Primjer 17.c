/* primjer pokazuje razliku izmedju ponasanja automatskih i statickih
   varijabli */

#include <stdio.h>

int funkcija_1();
int funkcija_2();

int main() 
{
	int i;
	
	printf("Ponasanje automatske varijable:\n");
	for(i = 1; i <= 10; i++)
	{
		printf("%2d. poziv: vrijednost varijable je %d\n", i, funkcija_1());
	}

	printf("Ponasanje staticke varijable:\n");
	for(i = 1; i <= 10; i++)
	{
		printf("%2d. poziv: vrijednost varijable je %d\n", i, funkcija_2());
	}

	return 0;
}

int funkcija_1()
{
	auto int x = 0;
	
	x++;
	return x;
}

int funkcija_2()
{
	static int x = 0;
	
	x++;
	return x;
}

