/* primjer unosi tekst i ispisuje koliko se u njemu nalazi velikih slova, 
   a koliko samoglasnika */

#include <stdio.h>
#include <string.h>

int jeLiSamoglasnik(char c);

int main() 
{
	char tekst[128];
	int bvs = 0, bs = 0, i;
	
	printf("Unesi neki tekst: ");
	gets(tekst);
	
	/* parsiranje stringa */
	for(i = 0; i < strlen(tekst); i++)
	{
		if((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
			bvs++;
		if(jeLiSamoglasnik(tekst[i]))
			bs++;
	}

	printf("U unesenom tekstu je %d velikih slova i %d samoglasnika.\n", bvs, bs);

	return 0;
}

int jeLiSamoglasnik(char c)
{
	char samoglasnici[] = "AaEeIiOoUu";
	int i;
	
	for(i = 0; i < strlen(samoglasnici); i++)
		if(c == samoglasnici[i])
			return 1;
	
	return 0;
}
