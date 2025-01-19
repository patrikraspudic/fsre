/* primjer unosi broj u binarnom zapisu (dekadski broj sastavljen od nula i )
   jedinica) i ispisuje njegov dekadski zapis */

#include <stdio.h>

int main() 
{
	int bin_broj, pom_bin_broj, dec_broj = 0, tf = 1, bz;
	
	printf("Unesi broj u binarnom zapisu: ");
	scanf("%d", &bin_broj);
	
	pom_bin_broj = bin_broj;
	
	while(pom_bin_broj != 0)
	{
		bz = pom_bin_broj % 10;
		dec_broj += bz * tf;
		tf = tf * 2;
		pom_bin_broj /= 10;
	}
	
	printf("(%d)2 = (%d)10\n", bin_broj, dec_broj);
	return 0;
}
