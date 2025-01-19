/* primjer pokazuje rad rekurzivne funkcije - funkcije koja poziva samu sebe
   primjer unosi cijeli broj n i ispisuje n-ti clan Fibonaccijevog niza
   1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
   Fibonacci(1) = Fibonacci(2) = 1
   Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n -2), za n >= 2 */

#include <stdio.h>

int broj_poziva = 0;

int Fibonacci(int n);

int main() 
{
	int n;
	
	printf("Unesi prirodan broj: ");
	scanf("%d", &n);	
	
	/* poziv rekurzivne funkcije iz glavnog programa */
	printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));
	printf("Rekurzivna funkcija je pozvana %d puta.", broj_poziva);
	
	return 0;
}

int Fibonacci(int n)
{
	broj_poziva++;
	/* provjera jesmo li dosli do kraja rekurzivnih poziva */
	if((n == 1) || (n == 2))							/* pravilo zaustavljanja */
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);		/* rekurzivni poziv */ 
	}
}


