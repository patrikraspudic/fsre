/* primjer pokazuje osnove rada s korisnicki definiranim funkcijama
   primjer unosi dva broja i u funkciji zbroji() racuna njihov zbroj
   i ispisuje ga u funkciji zbroji()
   2. primjer - lokalne varijable i void funkcija zbroji() */

#include <stdio.h>

/* prototip funkcije zbroji() tipa void i sa dva ulazna parametra */
void zbroji(int a, int b);

int main() 
{
	/* dekalaracija lokalnih varijabli funkcije main() */
	int x, y;
	printf("Unesi dva cijela broja: ");
	scanf("%d %d", &x, &y);

	/* poziv funkcije tipa void sa dva ulazna parametra */
	zbroji(x, y);

	return 0;
}

/* definicija funkcije zbroji() tipa void sa dva ulazna parametra */
void zbroji(int a, int b)
{
	/* dekalaracija lokalnih varijabli funkcije zbroji() */
	int c;
	
	c = a + b;
	printf("Njihov zbroj je %d.\n", c);
}


