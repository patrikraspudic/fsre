/* primjer unosi neki tekst i provjerava radi li se o palindromu, tj. 
   cta li se isto od naprijed i od straga */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
	char tekst[128], samoSlova[128];
	int i, j = 0, kontrola = 1;
	
	puts("Unesi neki tekst:");
	fflush(stdin);
	gets(tekst);
	
	for(i = 0; i < strlen(tekst); i++)
		if(isalpha(tekst[i]))
 			samoSlova[j++] = toupper(tekst[i]);
	samoSlova[j] = '\0';
			
	for(i = 0; i < strlen(samoSlova) / 2; i++)
		if(samoSlova[i] != samoSlova[strlen(samoSlova) - i - 1])
			kontrola = 0;
	
	if(kontrola == 1)
		puts("Tekst je palindrom!\n");
	else
		puts("Tekst nije palindrom!\n");
			
	return 0;
}
