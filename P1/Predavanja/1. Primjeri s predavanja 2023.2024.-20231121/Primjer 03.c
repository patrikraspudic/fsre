/* primjer pokazuje realizaciju algoritma grananja sa blokovima za ispunjen i
   neispunjen uvjet
   primjer unosi jedan cijeli broj i ispisuje njegovu apsolutnu vrijednost 
   koju racuna algoritamski i pozivom funkcije abs() */

#include <stdio.h>
#include <math.h>

int main() 
{
	int x, abs_x;
	int y, abs_y;
	
	printf("Unesi cijeli broj: ");
	scanf("%d", &x);
	
	/* IF-ELSE grananje */
	if(x >= 0)
	{
		/* blok za ispunjen uvjet */
		abs_x = x;
	}
	else
	{
		/* blok za neispunjen uvjet */
		abs_x = -x;
	}

	printf("|%d| = %d\n", x, abs_x);
	printf("-----\n");
	
	printf("Unesi jos jedan cijeli broj: ");
	scanf("%d", &y);
	/* racunanje apsolutne vrijednosti koristenjem funkcije abs() iz math.h */
	printf("|%d| = %d\n", y, abs(y));
	
	
	
	return 0;
}
