#include <stdio.h>

int main() 
{
	int broj5, zn5, tf5 = 1, broj10 = 0, broj7[16] = {}, i, j, pom, kontrola = 1;
	
	/* unos broja u sustavu s bazom 5 i provjera ispravnosti*/
	printf("Unesi broj u sustavu s bazom 5 s najvise 10 znamenki: ");
	scanf("%d", &broj5);
	
	pom = broj5;
	i = 0;
	while(pom != 0)
	{
		zn5 = pom % 10;
		if(zn5 > 4)
		{
			kontrola = 0;
		}
		broj10 += (pom % 10) * tf5;
		tf5 *= 5;
		pom /= 10;
		i++;
	}
	if(i > 10)
	{
		kontrola = 0;
	}
	
	if(kontrola == 1)
	{
		printf("Uneseni broj je ispravan!\n");
		printf("(%d)5 = (%d)10\n", broj5, broj10);
		
		pom = broj10;
		i = 15;
		while (pom != 0)
		{
			broj7[i] = pom % 7;
			i--;
			pom /= 7;
		}
		printf("(%d)10 = (", broj10);
		for(j = i + 1; j < 16; j++)
		{
			printf("%d", broj7[j]);
		}
		printf(")7\n");
	}
	else
	{
		printf("Uneseni broj nije ispravan!\n");
	}
	
	return 0;
}


