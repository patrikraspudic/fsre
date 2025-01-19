/* primjer unosi dva cijela broj i ispisuje njihov zbroj */

#include <stdio.h>

int main()
{
	/* deklaracijski dio */
	int	x, y, z;
	
	/* ulazne instrukcije scanf() */
	printf("Unesi prvi broj: ");
	scanf("%d", &x);
	printf("Unesi drugi broj: ");
	scanf("%d", &y);
	
	/* izvrsna instrukcija - operacija + */
	z = x + y;
	
	/* izlazna instrulcija - printf */
	printf("Zbroj unesenih brojeva je %d.\n", z);
	
	return 0;
}
