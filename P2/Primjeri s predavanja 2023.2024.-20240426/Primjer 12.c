/* primjer definira strukturu Sportas sa clanovima prezime i ime, sport (stringovi),
   godine, visina i tezina, unosi podatke za 5 sportasa i ispisuje prezimena i imena
   te visine kosarkasa sortirane po visini silazno, odnosno po abecedi, ako je visina ista */

#include <stdio.h>
#include <string.h>

struct Sportas
{
	char prezimeIme[32];
	char sport[32];
	int godine;
	int visina;
	int tezina;
};

int main()
{
	struct Sportas s[5], pS;
	int i, j;

	/* unos niza struktura */
	puts("Unesi podatke za 5 sportasa:");
	for (i = 0; i < 5; i++)
	{
		printf(" %d. sportas:\n", i + 1);
		printf("   - prezime i ime: ");
		fflush(stdin);
		gets(s[i].prezimeIme);
		printf("   - sport: ");
		fflush(stdin);
		gets(s[i].sport);
		printf("   - godine: ");
		scanf("%d", &s[i].godine);
		printf("   - visina: ");
		scanf("%d", &s[i].visina);
		printf("   - tezina: ");
		scanf("%d", &s[i].tezina);
	}

	/* sortiranje svih sportasa */
	for (i = 0; i < 4; i++)
		for (j = i + 1; j < 5; j++)
			if ((s[j].visina > s[i].visina) ||
				((s[j].visina == s[i].visina) && (strcmp(s[i].prezimeIme, s[j].prezimeIme) > 0)))
			{
				/* zamjena dviju struktura */
				pS = s[i];
				s[i] = s[j];
				s[j] = pS;
			}

	/* ispis samo kosarkasa */
	puts("\nKosarkasi sortirani po visini:");
	for (i = 0; i < 5; i++)
		if (strcmp(s[i].sport, "kosarka") == 0)
			printf("%-20s &d\n", s[i].prezimeIme, s[i].visina);

	return 0;
}
