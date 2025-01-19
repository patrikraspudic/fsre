/* primjer unosi cijeli broj i prikazuje ga u binarnom zapisu */

#include <stdio.h>

int main() 
{
	int d_broj, pom_d_broj, bin_broj[32] = {}, index = 31, i, j;
	
	printf("Unesi dekadski broj: ");
	scanf("%d", &d_broj);
	
	pom_d_broj = d_broj;
	
	if(pom_d_broj >= 0)
	{
		/* za uneseni broj veci ili jednak nuli */
		while(pom_d_broj != 0)
		{
			bin_broj[index] = pom_d_broj % 2;
			index--;
			pom_d_broj /= 2;
		}
	}
	else
	{
		/* za uneseni broj manji od nule */
		pom_d_broj = -pom_d_broj;		/* apsolutna vrijednost */
		while(pom_d_broj != 0)
		{
			bin_broj[index] = pom_d_broj % 2;
			index--;
			pom_d_broj /= 2;
		}
		/* prvi komplement */
		for(i = 0; i < 32; i++)
		{
			bin_broj[i] = 1 - bin_broj[i];
		}
		/* drugi komplement */
		i = 31;
		while(bin_broj[i] == 1)
		{
			bin_broj[i] = 0;
			i--;
		}		
		bin_broj[i] = 1;
	}
	
	printf("(%d)10 = (", d_broj);
	for(i = 0; i < 32; i++)
	{	
		printf("%d", bin_broj[i]);
	}
	printf(")2\n");

	/* ako zelimo izostaviti vodece nule */
	i = 0;
	while(bin_broj[i] == 0)
	{
		i++;
	}
	printf("(%d)10 = (", d_broj);
	for(j = i; j < 32; j++)
	{	
		printf("%d", bin_broj[j]);
	}
	printf(")2\n");

	return 0;
}
