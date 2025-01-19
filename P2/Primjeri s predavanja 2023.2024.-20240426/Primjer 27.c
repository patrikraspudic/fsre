/* primjer pokazuje osnove rada s datotekom, povezivanje, zapisivanje u datoteku 
   i dodavanje novog sadrzaja u vec postojecu datoteku 
   korisnik unosi tri broja koja se pohranjuju u datoteke 
   testna_datoteka_01.txt (otvorenu u modu w) i 
   testna_datoteka_02.txt (otvorenu u modu a) */

#include <stdio.h>

int main() 
{
	FILE *dat1, *dat2;				/* pokazivaci na datotecne medjuspremnike */
	int x, y, z;
	
	printf("Unesi tri cijela broja: ");
	scanf("%d %d %d", &x, &y, &z);

	/* otvaranje datoteke u modu zapisivanja w */
	dat1 = fopen("testna_datoteka_01.txt", "w");
	dat2 = fopen("testna_datoteka_02.txt", "a");
	
	if((dat1 == NULL) || (dat2 == NULL))
	{
		puts("Pogreska pri otvaranju datoteka.");
	}
	else
	{
		/* zapisivanje u datoteke - funkcija fprintf() */
		fprintf(dat1, "%d %d %d ", x, y, z);
		fprintf(dat2, "%d %d %d ", x, y, z);
		
		puts("Podaci su pohranjeni u datoteke.");
		
		/* zatvaranje datoteka */
		fclose(dat1);
		fclose(dat2);
	}

	return 0;
}
