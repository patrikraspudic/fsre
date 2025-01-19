/* primjer unosi neki tekst i ispisuje koliko je u njemu velikih, a koliko malih slova 
   engleskog alfabeta, te ga ispisuje na nacin da sva mala slova zamijeni velikima i 
   obrnuto, ostavljajuæi ostale znakove istima 
   primjer koristi funkcije iz ctype.h biblioteke zaglavlja*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
	char tekst[256];
	int i, bms = 0, bvs = 0;
	
	puts("Unesi neki tekst:");
	fflush(stdin);
	gets(tekst);
	
	for(i = 0; i < strlen(tekst); i++)
	{
		if(islower(tekst[i]))
			bms++;
		if(isupper(tekst[i]))
			bvs++;
	}
	
	printf("U tekstu je %d malih i %d velikih slova.\n", bms, bvs);
	
	for(i = 0; i < strlen(tekst); i++)
	{
		if(islower(tekst[i]))
			putchar(toupper(tekst[i]));
		else 
			putchar(tolower(tekst[i]));
	}	
	printf("\n");
	
	return 0;
}
