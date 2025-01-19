#include <stdio.h>

int main() 
{
	char znak[10], pom;
	int i = 0, j;
	
	printf("Unesi 10 malih slova engleskog alfabeta:\n");
	do
	{
		fflush(stdin);
		scanf("%c", &znak[i]);
		if((znak[i] >= 'a') && (znak[i] <= 'z'))
		{
			i++;
		}
		else
		{
			printf("Nije malo slovo engleskog alfabeta!\n");
		}
	}
	while (i < 10);
	
	/* sortiranje */
	for(i = 0; i < 9; i++)
	{
		for(j = i + 1; j < 10; j++)
		{
			if(znak[j] < znak[i])
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
