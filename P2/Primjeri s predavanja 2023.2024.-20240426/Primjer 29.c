/* primjer na ekran ispisuje sadrzaj ove programske datoteke 
   Primjer 29.c */

#include <stdio.h>

int main() 
{
	FILE *dat;
	char zn;
	
	dat = fopen("Primjer 29.c", "r");

	printf("Sadrzaj datoteke Primjer 29.c:\n");
	printf("------------------------------\n");
	/* citanje iz datoteke - funkcija fscanf() */

	while(!feof(dat))
	{
		zn = fgetc(dat);
		putchar(zn);
	}
		
	fclose(dat);

	return 0;
}
