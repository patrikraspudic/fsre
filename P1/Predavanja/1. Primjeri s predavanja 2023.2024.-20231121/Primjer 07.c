/* primjer pokazuje rad FOR petlje 
   primjer unosi jedan cijeli broj i ispisuje njegovih prvih
   N potencija gdje je N definirana konstante */

#include <stdio.h>
# define N 5

int main() 
{
	int x, pot = 1, i;
	
	printf("Unesi jedan cijeli broj: ");
	scanf("%d", &x);
	
	printf("Prvih %d potencija broja %d su: ", N, x);
	
	/* FOR petlja */
	for(i = 1; i <= N; i++)
	{
		/* blok instrukcija FOR petlje */
		pot = pot * x;
		printf("%d ", pot);
	}
	printf("\n");
	
	return 0;
}
