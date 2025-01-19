/* primjer pokazuje ugnijezdeno IF-ELSE grananje
   primjer unosi realni broj x i ispisuje vrijednost funkcije
          { -x + 2, za x < -2
   f(x) = { x^2, za -2 <= x < 1
          { sqrt(x), za x >= 1
*/          
        
#include <stdio.h>
#include <math.h>

int main() 
{
	float x, y;
	
	printf("Unesi realan broj x: ");
	scanf("%f", &x);
	
	/* ugnijezdeno IF-ELSE grananje */
	if(x < -2)			/* vanjsko IF-ELSE grananje  - prvi uvjet*/
	{
		/* blok za ispunjen prvi uvjet */
		y = -x + 2;
	}
	else if(x < 1)		/* ugnijezdeno IF-ELSE grananje - drugi uvjet */
	{
		/* blok za ispunjen drugi uvjet */
		y = pow(x, 2);	/* funkcija potencije */
	}
	else
	{	
		/* blok za neispunjene sve testirane uvjete */
		y = sqrt(x);	/* funkcija kvadratnog korijena */
	}
	
	printf("f(%f) = %f\n", x, y);

	return 0;
}
