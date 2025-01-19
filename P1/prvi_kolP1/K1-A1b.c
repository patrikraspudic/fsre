 #include <stdio.h>

int main() 
{
	int i, j;
	
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if((i % 2 == 0) && (j % 2 == 0) && ((i + j == 2) || (i + j == 6)))
			{
				printf ("  ");
			}
			else
			{
				if((i + j) % 2 == 0)
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

