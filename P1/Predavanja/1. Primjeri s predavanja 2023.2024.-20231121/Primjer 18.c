/* primjer pokazuje rad rekurzivne funkcije - funkcije koja poziva samu sebe
   primjer unosi cijeli broj i ispisuje njegov faktorijel */

#include <stdio.h>

int broj_poziva = 0;

int faktorijel(int n);

int main() 
{
	int n;
	
	printf("Unesi prirodan broj: ");
	scanf("%d", &n);	
	
	/* poziv rekurzivne funkcije iz glavnog programa */
	printf("%d! = %d\n", n, faktorijel(n));
	printf("Rekurzivna funkcija je pozvana %d puta.", broj_poziva);
	return 0;
}

int faktorijel(int n)
{
	broj_poziva++;
	/* provjera jesmo li dosli do kraja rekurzivnih poziva */
	if(n == 0)							/* pravilo zaustavljanja */
	{
		return 1;
	}
	else
	{
		return n * faktorijel(n - 1);	/* rekurzivni poziv */ 
	}
}


