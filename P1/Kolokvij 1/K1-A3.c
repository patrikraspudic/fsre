#include <stdio.h>

int main() 
{
	int broj7, zn7, tf7 = 1, broj10 = 0, broj5[16] = {}, i, j, pom, kontrola = 1;
	
	/* unos broja u sustavu s bazom 7 i provjera ispravnosti*/
	printf("Unesi broj u sustavu s bazom 7 s najvise 8 znamenki: ");
	scanf("%d", &broj7);
	
	pom = broj7;
	i = 0;
	while(pom != 0)
	{
		zn7 = pom % 10;
		if(zn7 > 6)
		{
			kontrola = 0;
		}
		broj10 += (pom % 10) * tf7;
		tf7 *= 7;
		pom /= 10;
		i++;
	}
	if(i > 8)
	{
		kontrola = 0;
	}
	
	if(kontrola == 1)
	{
		printf("Uneseni broj je ispravan!\n");
		printf("(%d)7 = (%d)10\n", broj7, broj10);
		
		pom = broj10;
		i = 15;
		while (pom != 0)
		{
			broj5[i] = pom % 5;
			i--;
			pom /= 5;
		}
		printf("(%d)10 = (", broj10);
		for(j = i + 1; j < 16; j++)
		{
			printf("%d", broj5[j]);
		}
		printf(")5\n");
	}
	else
	{
		printf("Uneseni broj nije ispravan!\n");
	}
	
	return 0;
}


