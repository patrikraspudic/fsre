#include <stdio.h>

int main()
{
	int i, j;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if((i % 8 == 0) || (j % 8 == 0))
			{
				printf(" *");
			}
			else if (((i % 4 == 2) && (j % 6 != 1)) || ((j % 4 == 2) && (i % 6 != 1)))
			{
				printf(" *");
			}
			else if ((i == 4) && (j == 4))
			{
				printf(" *");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	return 0;
}
