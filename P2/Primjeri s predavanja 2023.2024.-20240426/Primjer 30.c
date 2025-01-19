/* primjer sadrzaj ove programske datoteke Primjer 30.c  kopira u datoteku 
   Primjer 30.backup */

#include <stdio.h>

int main() 
{
	FILE *dat1, *dat2;
	char zn;
	
	dat1 = fopen("Primjer 30.c", "r");
	dat2 = fopen("Primjer 30.backup", "w");
	
	while(!feof(dat1))
	{
		zn = fgetc(dat1);
		if(zn != EOF)
			fputc(zn, dat2);
	}
		
	fclose(dat1);
	fclose(dat2);
	
	puts("Podaci su pohranjeni u datoteku Primjer 30.backup");

	return 0;
}
