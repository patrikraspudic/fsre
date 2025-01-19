/* primjer unosi 10 imena i ispisuje ih sortirane po abecedi */ 

#include <stdio.h>
#include <string.h>

int main() 
{
	int i, j;
	char imena[10][16], pom[16];
	
	/* unos podataka */
	printf("Unesi 10 imena:\n");
	for(i = 0; i < 10; i++)
		scanf("%s", imena[i]);
	
	/* sortiranje podataka */
	for(i = 0 ; i < 9; i++)
		for(j = i + 1; j < 10; j++)
			if(stricmp(imena[i], imena[j]) > 0) 
			{
				strcpy(pom, imena[i]);
				strcpy(imena[i], imena[j]);
				strcpy(imena[j], pom);
			}
	
	/* ispis podataka */
	printf("\nSortirana imena su:\n");
	for(i = 0; i < 10; i++)
		puts(imena[i]);
		
	
	return 0;
}
