#include <stdio.h>

int main()
{
	int i, j;
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if((i < 3) && ((i + j < 2) || (j > i + 2)))
			{
				printf("  ");
			}
			else if((i >= 3) && ((i + j > 6) || (j < i - 2)))
			{
				printf("  "); 
			}
			else
			{
				printf("* ");
			}
		}
		printf("\n");
	}
	return 0;
}
