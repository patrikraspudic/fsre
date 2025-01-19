/* primjer unoosi znakove sve dok se zaredom ne unesu znakovi 'k', 'r', 'a' i 'j'
   te ih smješta u za to predvidjeni, dinamicki zauzet memorijski prostor optimalne 
   velicine, nakon unosa se za svako slovo engleskog alfabeta ispisuje slovo i 
   broj njegovih ponavljanja, bez oobzira radi li se o velikim ili malom slovu
   brojeve ponavljanja slova pohraniti u dinamicki zauzet memorijski prostor
   odgovarajuce velicine */ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
int kontrola_kraja(char *znakovi, int broj_znakova);

int main() 
{
	char *znakovi = (char *)malloc(sizeof(char) * 4);
	int *ponavljanja = (int *)malloc(sizeof(int) * 26);
	int broj_znakova = 0, i, j;
	
	/* unos znakova */
	puts("Unosi znakove ('k', 'r', 'a', 'j' za kraj):");
	while(broj_znakova < 4)
	{
		fflush(stdin);
		scanf("%c", (znakovi + broj_znakova));
		broj_znakova++;
	}
	while(kontrola_kraja(znakovi, broj_znakova) == 0)
	{
		znakovi = (char *)realloc(znakovi, sizeof(char) * (broj_znakova + 1));
		fflush(stdin);
		scanf("%c", (znakovi + broj_znakova));
		broj_znakova++;
	}
	
	puts ("Gotovo!");
	
	/* inicijaliziranje niza ponavljanja slova */
	for(i = 'A'; i <='Z'; i++)
		*(ponavljanja + i - 'A') = 0;
		
	/* brojanje ponavljanja slova */
	for(i = 0; i < broj_znakova; i++)
		(*(ponavljanja + toupper(*(znakovi + i)) - 'A'))++;	
	
	/* ispis broja ponavljanja */
	for(i = 'A'; i <='Z'; i++)	
		printf("Slovo %c ponavlja se %d puta.\n", i, *(ponavljanja + i - 'A'));
	
	return 0;
}

int kontrola_kraja(char *znakovi, int broj_znakova)
{
	if(*(znakovi + broj_znakova - 4) != 'k')
		return 0;
	if(*(znakovi + broj_znakova - 3) != 'r')
		return 0;
	if(*(znakovi + broj_znakova - 2) != 'a')
		return 0;
	if(*(znakovi + broj_znakova - 1) != 'j')
		return 0;						
	return 1;
}
