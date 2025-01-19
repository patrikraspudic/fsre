/* primjer pokazuje osnove rada sa strukturama u C-u */
#include <stdio.h>
#include <string.h>

/* definiranje strukture - korisnickog tipa podatka */
struct Student
{
	char prezimeIme[32];
	char studij[32];
	int brojIndeksa;
	int godinaStudija;
	float prosjekOcjena;
};

int main()
{
	struct Student s1, s2 = {"Ivic Ivo", "Racunarstvo", 1345, 2, 4.11}, s3;
	struct Student S[3] = {{"Anic Ana", "Psihologija", 124, 3, 3.45},
						   {"Juric Jure", "Strojarstvo", 123, 2, 2.11},
						   {"Matic Mate", "Pravo", 3214, 4, 3.88}};

	printf("Student %s ima prosjek ocjena %.2f.\n", s2.prezimeIme, s2.prosjekOcjena);

	s2.prosjekOcjena = 3.96;
	printf("Student %s ima prosjek ocjena %.2f.\n", s2.prezimeIme, s2.prosjekOcjena);

	printf("Student %s studija na studiju %s.\n", S[1].prezimeIme, S[1].studij);

	strcpy(S[1].studij, "Agronomija");
	printf("Student %s studija na studiju %s.\n", S[1].prezimeIme, S[1].studij);

	/* strukturu mozemo pridruziti pomocu operatora = */
	s1 = S[2];
	printf("Student %s (broj indeksa: %d) je na %d. godini studija %s i ima prosjek ocjena %.2f.\n",
		   s1.prezimeIme, s1.brojIndeksa, s1.godinaStudija, s1.studij, s1.prosjekOcjena);

	/* unos podataka za jednog studenta */
	puts("Unesi podatke za jednog studenta:");
	printf(" - prezime i ime: ");
	fflush(stdin);
	gets(s3.prezimeIme);
	printf(" - studij: ");
	fflush(stdin);
	gets(s3.studij);
	printf(" - broj indeksa: ");
	scanf("%d", &s3.brojIndeksa);
	printf(" - godina studija: ");
	scanf("%d", &s3.godinaStudija);
	printf(" - prosjek ocjena: ");
	scanf("%f", &s3.prosjekOcjena);
	printf("Student %s (broj indeksa: %d) je na %d. godini studija %s i ima prosjek ocjena %.2f.\n",
		   s3.prezimeIme, s3.brojIndeksa, s3.godinaStudija, s3.studij, s3.prosjekOcjena);

	return 0;
}
