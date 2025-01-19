/* primjer pokazuje razlicite nacine unosa i ispisa stringa */

#include <stdio.h>

int main() 
{
	char tekst1[32], tekst2[32];

	printf("Unesi dva puta isti tekst:\n");
	fflush(stdin);
	gets(tekst1);
	fflush(stdin);
	scanf("%s", tekst2);

	printf("Pomocu gets()  prihvacen je tekst: ");
	puts(tekst1);
	printf("Pomocu scanf() prihvacen je tekst: ");
	puts(tekst2);	
	
	return 0;
}
