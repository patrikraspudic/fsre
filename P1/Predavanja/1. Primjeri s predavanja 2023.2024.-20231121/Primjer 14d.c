/* primjer pokazuje osnove rada s korisnicki definiranim funkcijama
   primjer unosi dva broja i u funkciji zbroji() racuna njihov zbroj
   i ispisuje ga u glavnom programu
   4. primjer - "optimalno" rjesenje */

#include <stdio.h>

int zbroji(int a, int b);

int main() 
{
	int x, y;
	printf("Unesi dva cijela broja: ");
	scanf("%d %d", &x, &y);

	printf("Njihov zbroj je %d.\n", zbroji(x, y));

	return 0;
}

int zbroji(int a, int b)
{
	return a + b;
}


