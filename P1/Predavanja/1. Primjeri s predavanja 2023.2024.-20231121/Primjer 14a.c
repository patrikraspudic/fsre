/* primjer pokazuje osnove rada s korisnicki definiranim funkcijama
   primjer unosi dva broja i u funkciji zbroji() racuna njihov zbroj
   i ispisuje ga u glavnom programu
   1. primjer - globalne varijable */

#include <stdio.h>

/* dekalaracija globalnih varijabli */
int x, y, z;

/* prototip funkcije zbroji() tipa void i bez ulaznih parametara
   prototip = zaglavlje + ; */
void zbroji();

int main() 
{
	printf("Unesi dva cijela broja: ");
	scanf("%d %d", &x, &y);

	/* poziv funkcije tipa void i bez ulaznih parametara */
	zbroji();

	printf("Njihov zbroj je %d.\n", z);
	
	return 0;
}

/* definicija funkcije zbroji() tipa void i bez ulaznih parametara
   definicija = zaglavlje + tijelo */
void zbroji()
{
	z = x + y;
}


