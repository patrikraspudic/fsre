/* primjer sadrzaj odabrane tekstualne datoteke kopira na zeljeno mjesto i 
   pod zeljenim imenom */

#include <stdio.h>

int main() 
{
	FILE *dat1, *dat2;
	char datoteka1[64], datoteka2[64];
	char zn;
	
	printf("Koju datoteku zelis kopirati? ");
	fflush(stdin);
	gets(datoteka1);
	dat1 = fopen(datoteka1, "r");
	
	if(dat1 == NULL)
	{
		printf("Pogreska u otvaranju izvorisne datoteke.\n");
	}
	else
	{
		printf("Gdje ju zelis kopirati i pod kojim imenom? ");
		fflush(stdin);
		gets(datoteka2);
		dat2 = fopen(datoteka2, "w");
		
		if(dat2 == NULL)
		{
			printf("Pogreska u otvaranju odredisne datoteke.\n");
		}
		else
		{
			while(!feof(dat1))
			{
				zn = fgetc(dat1);
				if(zn != EOF)
					fputc(zn, dat2);
			}
			fclose(dat2);
		}
		fclose(dat1);
	
		puts("Podaci su pohranjeni u odredisnu datoteku.\n");
	}

	return 0;
}
