/* primjer unosi dva stringa koji predstavljaju ime i prezime osobe i
   formira treci string oblika prezime(razmak)ime */

#include <stdio.h>
#include <string.h>

int main()
{
	char ime[32], prezime[32], osoba[64];

	printf("Unesi ime osobe: ");
	fflush(stdin);
	gets(ime);
	printf("Unesi prezime osobe: ");
	fflush(stdin);
	gets(prezime);

	strcpy(osoba, prezime);
	strcat(osoba, " ");
	strcat(osoba, ime);

	printf("Osoba se zove %s.", osoba);

	return 0;
}
