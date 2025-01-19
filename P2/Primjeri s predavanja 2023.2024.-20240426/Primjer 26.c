/* primjer definira strukturu za zapis podataka o sportskom klubu: 
   naziv kluba, sport, grad i broj clanova, unosi podatke o klubovima 
   sve dok se kao ime kluba ne unese "KRAJ" u dinamicki zauzet 
   memorijski prostor optimalne velicine i nakon toga ispisuje, 
   sortirane po broju clanova silazno, odnosno po nazivu kluba abecedno, ako
   je broj clanova isti, sve nogometne klubove */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct klub
{
	char naziv[32];
	char sport[32];
	char grad[32];
	int clanovi;
};

int main() 
{
	struct klub *k = NULL, pomK;
	char naziv_kluba[32];
	int i, j, broj_klubova = 0, kontrola = 1;
	
	/* unos podataka */
	do
	{
		printf("Unesi podatke za %d. klub\n", broj_klubova + 1);
		fflush(stdin);
		printf(" - unesi naziv kluba: ");
		gets(naziv_kluba);
		if(strcmp(naziv_kluba, "KRAJ") == 0)
			kontrola = 0;
		else
		{
			/* unosimo ostatak podataka za klub */
			k = (struct klub *)realloc(k, sizeof(struct klub) * (broj_klubova + 1));
			strcpy((k + broj_klubova)->naziv, naziv_kluba);
			fflush(stdin);
			printf(" - unesi sport kluba: ");
			gets((k + broj_klubova)->sport);
			fflush(stdin);
			printf(" - unesi grad kluba: ");
			gets((k + broj_klubova)->grad);			
			printf(" - unesi broj clanova kluba: ");
			scanf("%d", &((k + broj_klubova)->clanovi));
			broj_klubova++;
		}	
	}
	while (kontrola == 1);
	
	printf("\nUneseni su podaci za %d klubova.\n\n", broj_klubova);

	
	/* sortiranje po zadanom kriteriju */
	for(i = 0; i < broj_klubova - 1; i++)
		for(j = i + 1; j < broj_klubova; j++)
			if(((*(k + j)).clanovi > (*(k + i)).clanovi) ||
			   (((*(k + j)).clanovi == (*(k + i)).clanovi) && (strcmp((k + j)->naziv, (k + i)->naziv) < 0)))
			{
				pomK = *(k + i);
				*(k + i) = *(k + j);
				*(k + j) = pomK; 
			}   
	
	/* ispis ngometnih klubova */ 
	for(i = 0; i < broj_klubova; i++)
		if((strcmp((k + i)->sport, "nogomet") == 0))
			printf("%s %s %s %d\n", (k + i)->naziv, (k + i)->sport, (k + i)->grad, (k + i)->clanovi);	
	
	return 0;
}
