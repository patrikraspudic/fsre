/* primjer pokazuje osnove rada s korisnicki definiranim funkcijama
   primjer unosi dva broja i u funkciji zbroji() racuna njihov zbroj
   i ispisuje ga u glavnom programu
   3. primjer - lokalne varijable i int funkcija zbroji() */

#include <stdio.h>

/* prototip funkcije zbroji() tipa int i sa dva ulazna parametra */
int zbroji(int a, int b);

int main() 
{
	/* dekalaracija lokalnih varijabli funkcije main() */
	int x, y, z;
	printf("Unesi dva cijela broja: ");
	scanf("%d %d", &x, &y);

	/* poziv funkcije tipa int sa dva ulazna parametra */
	z = zbroji(x, y);
	printf("Njihov zbroj je %d.\n", z);

	return 0;
}

/* definicija funkcije zbroji() tipa int sa dva ulazna parametra */
int zbroji(int a, int b)
{
	/* dekalaracija lokalnih varijabli funkcije zbroji() */
	int c;
	
	c = a + b;

	return c;
}


