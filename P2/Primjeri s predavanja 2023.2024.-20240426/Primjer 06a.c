/* primjer unosi neki tekst i ispisuje koliko je u njemu velikih, a koliko malih slova 
   engleskog alfabeta, te ga ispisuje na nacin da sva mala slova zamijeni velikima i 
   obrnuto, ostavljajuæi ostale znakove istima */

#include <stdio.h>
#include <string.h>

int main() 
{
	char tekst[256];
	int i, bms = 0, bvs = 0;
	
	puts("Unesi neki tekst:");
	fflush(stdin);
	gets(tekst);
	
	for(i = 0; i < strlen(tekst); i++)
	{
		if((tekst[i] >= 'a') && (tekst[i] <= 'z'))
			bms++;
		if((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
			bvs++;
	}
	
	printf("U tekstu je %d malih i %d velikih slova.\n", bms, bvs);
	
	for(i = 0; i < strlen(tekst); i++)
	{
		if((tekst[i] >= 'a') && (tekst[i] <= 'z'))
			putchar(tekst[i] - 'a' + 'A');
		else if((tekst[i] >= 'A') && (tekst[i] <= 'Z'))
			putchar(tekst[i] + 'a' - 'A');
		else
			putchar(tekst[i]);
	}	
	printf("\n");
	
	return 0;
}

