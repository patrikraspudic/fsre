#include <stdio.h>

int je_li_dvoznamenkast(int n);

int main() 
{
	int broj[15], i = 0, j, pom;
	
	/* unos 15 dvoznamenkastih brojeva */
	printf("Unesi 15 dvoznamenkastih brojeva:\n");
	do
	{
		scanf("%d", &broj[i]);
		if(je_li_dvoznamenkast(broj[i]) == 1)
		{
			i++;
		}
		else
		{
			printf("Broj %d nije dvoznamenkast!\n", broj[i]);
		}
	}
	while(i != 15);

	/* sortiranje niza u silaznom redoslijedu */
	for(i = 0; i < 14; i++)
	{
		for(j = i + 1; j < 15; j++)
		{
			if(broj[i] < broj[j])
			{
				pom = broj[i];
				broj[i] = broj[j];
				broj[j] = pom;
			}
		}
	}
	
	/* ispis sortiranog niza */
	printf("Niz dvoznamenkastih brojeva sortiran silazno:\n");
	for(i = 0; i < 15; i++)
	{
		printf("%d\n", broj[i]);
	}
	
	
	return 0;
}

int je_li_dvoznamenkast(int n)
{
	if(((n >= -99) && (n<= -10)) || ((n >= 10) && (n <= 99))) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
