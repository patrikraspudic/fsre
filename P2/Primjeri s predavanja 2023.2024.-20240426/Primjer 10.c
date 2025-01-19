/* primjer unosi rijeci sve dok se ne unese rijec sa barem tri samoglasnika 
   i nakon toga ispisuje sve unesene rijeci sortirane silazno po broju slova 
   odnosno abecedno ne vodeci racuna o razlici velikih i malih slova, 
   ako je broj slova isti */

#include <stdio.h>
#include <string.h>

int brojSamoglasnika(char rijec[32]);
void sortiranje(char rijeci[32][32], int n);

int main() 
{
	char rijeci[32][32];
	int i = 0, j;
	
	/* unos rijeci */
	puts("Unosi rijeci (rijec sa barem 3 samoglasnika za kraj):");
	do
	{
		fflush(stdin);
		gets(rijeci[i++]);
	}
	while(brojSamoglasnika(rijeci[i - 1]) < 3);
	
	/* sortiranje po zadanom kriteriju */
	sortiranje(rijeci, i);
	
	/* ispis sortiranih rijeci */
	puts("\nSortirane rijeci su:");
	for(j = 0; j < i; j++)
		puts(rijeci[j]);
	
	return 0;
}

int brojSamoglasnika(char rijec[32])
{
	char samoglasnici[] = "AaEeIiOoUu";
	int br = 0, i, j;
	
	for(i = 0; i < strlen(rijec); i++)
		for(j = 0; j < 10; j++)
			if(rijec[i] == samoglasnici[j])
				br++;
	return br;
}

void sortiranje(char rijeci[32][32], int n)
{
	char pom[32];
	int i, j;
	
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if((strlen(rijeci[i]) < strlen (rijeci[j])) ||
				((strlen(rijeci[i]) == strlen (rijeci[j])) && (stricmp(rijeci[i], rijeci[j]) > 0)))
			{
				strcpy(pom, rijeci[i]);
				strcpy(rijeci[i], rijeci[j]);
				strcpy(rijeci[j], pom);
			}
}
