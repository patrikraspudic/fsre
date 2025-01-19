#include <stdio.h>

int je_li_prost(int n);

int main() 
{
	int broj[15], i = 0, j, pom;
	
	/* unos 15 prostih brojeva */
	printf("Unesi 15 prostih brojeva:\n");
	do
	{
		scanf("%d", &broj[i]);
		if(je_li_prost(broj[i]) == 1)
		{
			i++;
		}
		else
		{
			printf("Broj %d nije prost!\n", broj[i]);
		}
	}
	while(i != 15);

	/* sortiranje niza u uzlaznom redoslijedu */
	for(i = 0; i < 14; i++)
	{
		for(j = i + 1; j < 15; j++)
		{
			if(broj[i] > broj[j])
			{
				pom = broj[i];
				broj[i] = broj[j];
				broj[j] = pom;
			}
		}
	}
	
	/* ispis sortiranog niza */
	printf("Niz prostih brojeva sortiran uzlazno:\n");
	for(i = 0; i < 15; i++)
	{
		printf("%d\n", broj[i]);
	}
	
	
	return 0;
}

int je_li_prost(int n)
{
	int prost = 1, i;
	
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			prost = 0;
		}
	}
	
	return prost;
}
