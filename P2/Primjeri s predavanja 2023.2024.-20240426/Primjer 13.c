/* primjer definira strukturu adresa sa clanovima: mjesto, postanski broj, ulica i
   kucni broj, strukturu student sa clanovima: prezime i ime, studij, godina studija, 
   adresa (ugnjezdena struktura) i prosjek ocjena, i strukturu nastavnik sa clanovima: 
   prezime i ime, zvanje, broj ureda, adresa (ugnjezdena struktura) i placa; unoose se 
   podaci za 5 stusdenata i inicijaliziraju podaci za 5 nastavnika te ispisuju svi 
   studenti sa adresom u Mostaru, sortirani po prosjeku ocjena silazno, odnosno abecedno 
   ako je prosjek isti te svi nastavnici s adresom izvan Mostara, sortirani abecedno */

#include <stdio.h>
#include <string.h>

/* definicija ugnjezdene strukture */
struct adresa
{
	char mjesto[32];
	int postanskiBroj;
	char ulica[64];
	int kucniBroj;
};

struct student
{
	char prezimeIme[32];
	char studij[32];
	int godinaStudija;
	/* ugnjezdena struktura */
	struct adresa sAdresa;
	float prosjekOcjena;
};

struct nastavnik
{
	char prezimeIme[32];
	char zvanje[32];
	int ured;
	/* ugnjezdena struktura */
	struct adresa nAdresa;
	float placa;
};

int main() 
{
	struct student S[5], pS;
	struct nastavnik N[5] = {{"Matic Mate", "doc. dr. sc.", 234, {"Mostar", 88000, "Splitska", 25}, 1645.26},
							 {"Ivic Ivo", "prof. dr. sc.", 248, {"Siroki Brijeg", 88220, "Mostarska", 16}, 1864.54},
							 {"Anic Ana", "izv. prof. dr. sc.", 244, {"Capljina", 88300, "Dubrovacka", 14}, 1705.54},
							 {"Maric Marija", "v. asist.", 345, {"Mostar", 88000, "Zagrebacka", 6}, 1248.11},
							 {"Bozic Bozo", "doc. dr. sc.", 245, {"Stolac", 88360, "Capljinska", 11}, 1547.65}}, pN;
	int i, j;
	
	/* unos podataka za studente*/
	puts("Unesi podatke za 5 studenata:");
	for(i = 0; i < 5; i++)
	{
		printf(" %d. student:\n", i + 1);
		printf("  - prezime i ime: ");
		fflush(stdin);
		gets(S[i].prezimeIme);
		printf("  - studij: ");
		fflush(stdin);
		gets(S[i].studij);
		printf("  - godina studija: ");
		scanf("%d", &S[i].godinaStudija);
		
		/* unos clanova ugnjezdene strukture */
		printf("  - mjesto: ");
		fflush(stdin);
		gets(S[i].sAdresa.mjesto);
		printf("  - postanski broj: ");
		scanf("%d", &S[i].sAdresa.postanskiBroj);
		printf("  - ulica: ");
		fflush(stdin);
		gets(S[i].sAdresa.ulica);
		printf("  - kucni broj: ");
		scanf("%d", &S[i].sAdresa.kucniBroj);		
		
		printf("  - prosjek ocjena: ");
		scanf("%f", &S[i].prosjekOcjena);		
	}

	
	/* sortiranje studenata po prosjeku, odnosno abecedno */
	for(i = 0; i < 4; i++)
		for(j = i + 1; j < 5; j++)
			if((S[i].prosjekOcjena < S[j].prosjekOcjena) ||
			   ((S[i].prosjekOcjena == S[j].prosjekOcjena) && (strcmp(S[i].prezimeIme, S[j].prezimeIme) > 0)))
			{
				pS = S[i];
				S[i] = S[j];
				S[j] = pS;
			}
	
	/* ispis studenata koji su iz Mostara */
	puts("\nStudenti koji su iz Mostara su:");
	for(i = 0; i < 5; i++)
		if(strcmp(S[i].sAdresa.mjesto, "Mostar") == 0)
			printf("%s %s (%.2f)\n", S[i].prezimeIme, S[i].studij, S[i].prosjekOcjena);

	
	/* sortiranje nastavnika abecedno */
	for(i = 0; i < 4; i++)
		for(j = i + 1; j < 5; j++)
			if(strcmp(N[i].prezimeIme, N[j].prezimeIme) > 0)
			{
				pN = N[i];
				N[i] = N[j];
				N[j] = pN;
			}
	
	/* ispis nastavnika koji nisu iz Mostara */
	puts("\nNastavnici koji nisu iz Mostara su:");
	for(i = 0; i < 5; i++)
		if(strcmp(N[i].nAdresa.mjesto, "Mostar") != 0)
			printf("%s %s (%s)\n", N[i].zvanje, N[i].prezimeIme, N[i].nAdresa.mjesto);
	
	
	return 0;
}
