#include <stdio.h>

int main()
{
	int i, j;
		
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if((i % 4 != 0) && (j % 4 == 0))
			{
				printf("  ");
			}
			else if((i % 4 == 2) && (j % 2 != 0))
			{
				printf("  ");
			}
			else
			{
				printf(" %c", 'A' + j % 3);
			}
		}
		printf("\n");
	}
	return 0;
}
