/* primjer pokazuje razlièite nacine zadavanja stringa u programu */

#include <stdio.h>
#include <string.h>

int main() 
{
	char ime1[15] = {'P', 'e', 'r', 'o', ' ', 'P', 'e', 'r', 'i', 'c', '\0'};
	char ime2[15];
	char ime3[15] = "Ante Antic";
	char ime4[15];
	
	ime2[0] = 'I';
	ime2[1] = 'v';
	ime2[2] = 'a';
	ime2[3] = ' ';
	ime2[4] = 'I';
	ime2[5] = 'v';
	ime2[6] = 'i';
	ime2[7] = 'c';
	ime2[8] = '\0';

	strcpy(ime4, "Marija Maric");
	
	printf("Imena su %s, %s, %s i %s.", ime1, ime2, ime3, ime4);

	return 0;
}
