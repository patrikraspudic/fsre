/* primjer pokazuje rad s WHILE petljom
   primjer unosi dva prirodna broja i, koristenjem Euklidovog algoritma, 
   pronalazi njihovu najvecu zajednicku mjeru
   Euklidov algoritam:
   x = y -> NZM(x, y) = x
   x > y -> NZM(x, y) = NZM(y, x - y)  */

#include <stdio.h>

int main() 
{
	int x, y, xc, yc, NZM;
	
	printf("Unesi dva prirodna broja: ");
	scanf("%d %d", &x, &y);
	
	/* kopije originalnih podataka */
	xc = x;
	yc = y;
	
	/* WHILE petlja s prethodnim ispitivanjem uvjeta */
	while(xc != yc)
	{
		/* veci broj mijenjamo razlikom veci - manji */
		if(xc > yc)
		{
			xc = xc - yc;
		}
		else
		{
			yc = yc - xc;
		}
	}
    
	NZM = xc;
	
	printf("NZM(%d, %d) je %d.\n", x, y, NZM);
	
	return 0;
}
