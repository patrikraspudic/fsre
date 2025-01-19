#include <stdio.h>

int main() 
{
	int i, j;
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(((i + j < 4) && (j < i)) || ((i + j > 4) && (j > i)))
			{
				printf ("  ");
			}
			else
			{
				if(j % 2 == 0)
				{
					printf("A ");
				}
				else
				{
					printf("B ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}


