/* primjer unosi recenicu i zatim ispisuje njene rijeci u obrnutom poretku */

#include <stdio.h>
#include <string.h>

int main() 
{
	char recenica[256], rijeci[16][16];
	int i, br = 0, bs = 0;
	
	puts("Unesi recenicu:");
	fflush(stdin);
	gets(recenica);
	
	/* rastavljanje recenice na rijeci */
	for(i = 0; i <= strlen(recenica); i++)
		if((recenica[i] == ' ') || (recenica[i] == '\0'))
		{
			rijeci[br][bs] = '\0';
			br++;
			bs = 0;
		}
		else
		{
			rijeci[br][bs] = recenica[i];
			bs++;
		}
	
	puts("Rijeci recenice u obrnutom poretku su:");
	for(i = br - 1; i >= 0; i--)
		puts(rijeci[i]);
		
	
	return 0;
}
