/* primjer pokazuje rad bit-znacajnih operatora u C-u */

#include <stdio.h>
#include <math.h>

void prikazi_binarno(int n);

int main() 
{
	int x, y, z, i;
	
	printf("Rad s bit-znacajnim operatorima\n");
	printf("--------------------------------------------------\n");
	
	printf("Interpretacija TRUE/FALSE vrijednosti:\n");
	printf(" TRUE = ");
	prikazi_binarno(5 == 5);
	printf("FALSE = ");
	prikazi_binarno(5 == 11);
	printf("--------------------------------------------------\n");
	
	printf("Primjena bit-znacajne negacije (bitovno NE) ~:\n");
	x = 325641273;
	printf("x = %d\n", x);
	printf("        x = ");
	prikazi_binarno(x);
	z = ~x;					/* bitovno NE (NOT) */
	printf("   z = ~x = ");
	prikazi_binarno(z);
	printf("--------------------------------------------------\n");
	
	printf("Primjena bit-znacajne konjukcije (bitovno I) &:\n");
	y = -124546218;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("        x = ");
	prikazi_binarno(x);
	printf("        y = ");
	prikazi_binarno(y);
	z = x & y;				/* bitovno I (AND) */
	printf("z = x & y = ");
	prikazi_binarno(z);
	printf("--------------------------------------------------\n");
	
	printf("Primjena bit-znacajne disjunkcije (bitovno ILI) |:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("        x = ");
	prikazi_binarno(x);
	printf("        y = ");
	prikazi_binarno(y);
	z = x | y;				/* bitovno ILI (OR) */
	printf("z = x | y = ");
	prikazi_binarno(z);	
	printf("--------------------------------------------------\n");
	
	printf("Primjena bit-znacajne ekskluzivne disjunkcije (bitovno ekskluzivno ILI) ^:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("        x = ");
	prikazi_binarno(x);
	printf("        y = ");
	prikazi_binarno(y);
	z = x ^ y;				/* bitovno ekskluzivno ILI (XOR) */
	printf("z = x ^ y = ");
	prikazi_binarno(z);
	printf("--------------------------------------------------\n");
	
	printf("Primjena bit-znacajnog pomaka ulijevo << :\n");
	printf("x = %d\n", x);
	printf("          x = ");
	prikazi_binarno(x);
	for(i = 1; i <= 32; i++)
	{
		z = x << i;				/* bitovni pomak ulijevo */
		printf("z = x << %2d = ", i);
     	prikazi_binarno(z);
	}
	printf("--------------------------------------------------\n");

	printf("Primjena bit-znacajnog pomaka udesno >> :\n");
	printf("x = %d\n", x);
	printf("          x = ");
	prikazi_binarno(x);
	for(i = 1; i <= 32; i++)
	{
		z = x >> i;				/* bitovni pomak udesno */
		printf("z = x >> %2d = ", i);
     	prikazi_binarno(z);
	}
	printf("--------------------------------------------------\n");

	
	return 0;
}

void prikazi_binarno(int n)
{
	int binarni_zapis[32] = {}, i = 31;
	
	if(n >= 0)
	{
		while(n != 0)
		{
			binarni_zapis[i] = n % 2;
			n = n / 2;
			i = i - 1;
		}
	}
	else
	{
		n = abs(n);
		while(n != 0)
		{
			binarni_zapis[i] = n % 2;
			n = n / 2;
			i = i - 1;
		}
		/* prvi komplement */
		for(i = 0; i < 32; i++)
		{
			binarni_zapis[i] = 1 - binarni_zapis[i];
		}
		/* drugi komplement */
		i = 31;
		while(binarni_zapis[i] != 0)
		{
			binarni_zapis[i] = 0;
			i--;
		}
		binarni_zapis[i] = 1;
	}
	
	/* ispis binarnog zapisa */
	for(i = 0; i < 32; i++)
	{
		printf("%d", binarni_zapis[i]);
	}
	printf("\n");
	
	
}
