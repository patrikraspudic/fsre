/* primjer pokazuje osnove rada s datotekom, povezivanje i citanje iz datoteke 
   na ekran se ispisuju svi brojevi pohranjeni u datotekama 
   testna_datoteka_01.txt i testna_datoteka_02.txt (otvorenim u modu r) */

#include <stdio.h>

int main() 
{
	FILE *dat1, *dat2;
	int broj, i;
	
	/* otvaranje datoteka u modovima citanja i dodavanja w i a*/
	dat1 = fopen("testna_datoteka_01.txt", "r");
	dat2 = fopen("testna_datoteka_02.txt", "r");
	
	if(dat1 == NULL)
	{
		puts("Pogreska pri otvaranju datoteka.");
	}
	else
	{
		printf("Sadrzaj datoteke testna_datoteka_01.txt:\n");
		printf("----------------------------------------\n");
		/* citanje iz datoteke - funkcija fscanf() */
		for(i = 0; i < 3; i++)
		{
			fscanf(dat1, "%d\n", &broj);
			printf("%d\n", broj);
		}
		
		fclose(dat1);
	}

	printf("Sadrzaj datoteke testna_datoteka_02.txt:\n");
	printf("----------------------------------------\n");
	/* citanje iz datoteke - funkcija fscanf() */
	while(!feof(dat2))
	{
		fscanf(dat2, "%d\n", &broj);
		printf("%d\n", broj);
	}
	
	fclose(dat1);

	return 0;
}
