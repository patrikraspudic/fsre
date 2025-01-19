/* primjer unosi 5 prostih brojeva (zanemarujuci ostale unesene podatke)
   i nakon toga ispisuje njihov zbroj i prosjek */

#include <stdio.h>

int main() 
{
	int broj[5], i, prost, broj_prostih = 0, zbroj_prostih = 0;
	float prosjek_prostih;
	
	printf("Unosi prirodne brojeve dok ne uneses 5 prostih brojeva:\n");
	do
	{
		printf("Unesi broj: ");
		scanf("%d", &broj[broj_prostih]);
	
		/* eliminiramo negativne brojeve i nulu */	
		if(broj[broj_prostih] > 0)
		{
			prost = 1;
			for(i = 2; i < broj[broj_prostih]; i++)
			{
				if(broj[broj_prostih] % i == 0)
				{
					prost = 0;
				}
			}	
			if(prost == 1)
			{
				broj_prostih++;	
			}
		}
	}
	while(broj_prostih < 5);
	
	printf("Unijeli ste 5 prostih brojeva: ");
	for(i = 0; i < 5; i++)
	{
		zbroj_prostih += broj[i];
		printf("%d ", broj[i]);
	}
	printf("\n");
	
	prosjek_prostih = zbroj_prostih / 5.0;
	
	printf("Njihov zbroj je %d, a prosjek je %.2f.\n", zbroj_prostih, prosjek_prostih);
	
	
	return 0;
}
