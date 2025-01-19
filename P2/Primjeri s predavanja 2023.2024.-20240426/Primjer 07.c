/* primjer unosi recenicu i ispisuje koliko je u njoj rijeci */

#include <stdio.h>
#include <string.h>

int main() 
{
	char recenica[256];
	int i, br = 1, pz, zz;
	
	printf("Unesi recenicu: ");
	gets(recenica);
	
	/* trazenje prvog znaka koji nije razmak */
	pz = 0;
	while(recenica[pz] == ' ')
		pz++;
	
	if(pz == strlen(recenica))
		/* uneseni string se sastoji samo od razmaka */
		br = 0;
	else
	{
		/* trazenje prvog znaka koji nije razmak */
		zz = strlen(recenica) - 1;
		while(recenica[zz] == ' ')
			zz--;
	
		for(i = pz; i <= zz; i++)
			if((recenica[i] == ' ') && (recenica[i - 1] != ' '))
				br++;
	}
	
	printf("U recenici je %d rijeci.\n", br);

	return 0;
}
