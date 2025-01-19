#include <stdio.h>

int main() 
{
	char znak[15], pom;
	int i = 0, j;
	
	printf("Unesi 15 velikih slova engleskog alfabeta:\n");
	do
	{
		fflush(stdin);
		scanf("%c", &znak[i]);
		if((znak[i] >= 'A') && (znak[i] <= 'Z'))
		{
			i++;
		}
		else
		{
			printf("Nije veliko slovo engleskog alfabeta!\n");
		}
	}
	while (i < 15);
	
	/* sortiranje */
	for(i = 0; i < 14; i++)
	{
		for(j = i + 1; j < 15; j++)
		{
			if(znak[j] > znak[i])
			{
				pom = znak[i];
				znak[i] = znak[j];
				znak[j] = pom;
			}
		}
	}
	
	/* ispis */
	printf("Sortirani znakovi:\n");
	for(i = 0; i < 15; i++)
	{
		printf("%c\n", znak[i]);
	}
	
	
	return 0;
}
