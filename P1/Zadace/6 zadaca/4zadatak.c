/*Patrik Raspudic 2233/rr*/
/*Napisati program koji unosi realne brojeve sve dok zadnji uneseni broj ne bude jednak
nekom od ranije unesenih brojeva. Nakon toga program u funkciji ispis() ispisuje one
brojeve čiji je cijeli dio 100 ili više puta veći od decimalnog dijela.*/
#include<stdio.h>

void ispis(float brojevi[100],int i);

int main()
{
	float brojevi[100];
	int bool = 0, i = 0,j;
	printf("Unosite realne brojeve za kraj unesite isti prethodno unesen\n");
	do
	{
		scanf("%f", &brojevi[i]);
		if(i > 0)
		{
			for(j = 0;j < i;j++)
			{
				if(brojevi[i] == brojevi[j])
				{
					bool = 1;
					break;
				}
			}
		}
		i++;
	}while(bool != 1);
	ispis(brojevi,i);
	return 0;
}
void ispis(float brojevi[100], int i)
{
	int j;
	printf("Brojevi ciji je cijeli dio 100 puta veci od decmalnog dijela:\n");
	for(j = 0;j < i;j++)
	{
		if((int)brojevi[j] >= 100*(brojevi[j] - (int)brojevi[j]))
		{
			printf(" %f", brojevi[j]);
		}
	}
}







    