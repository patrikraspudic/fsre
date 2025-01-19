/* primjer definira strukturu za zapis podataka o filmovima: naslov filma, zanr, reziser, 
   glavni glumac, godina izdanja i zarada (u milijunima), unose se podatci za 10 filmova 
   i ispisuju svi podatci za filmove izdane nakon 2000. godine koji su zaradili vise od 
   30 milijuna, sortirani silazno po zaradi, odnosno po godini izdanja ako je zarada ista 
   te se odredjuje koji je film zaradio najvise novca i ispiuju se njegovi podatci */

#include <stdio.h>
#include <string.h>
#define N 10

struct film
{
	char naslov[32];
	char zanr[16];
	char reziser[32];
	char glumac[32];
	int godina;
	float zarada;
};

void unosPodataka(struct film F[N]);
void sortiranje(struct film F[N]);
void ispisPodataka(struct film F[N]);
void ispisJednogFilma(struct film F);
struct film najvecaZarada(struct film F[N]);

int main() 
{
	struct film F[N], fnz;
	
	unosPodataka(F);
	fnz = najvecaZarada(F);
	sortiranje(F);
	ispisPodataka(F);

	puts("\nFilm s najvecom zaradom");
	printf("----------\n");
	ispisJednogFilma(fnz);
	
	return 0;
}

void unosPodataka(struct film F[N])
{
	int i;
	
	puts("Unesi podatke za 3 filmova:");
	for(i = 0; i < N; i++)
	{
		printf(" %d. film:\n", i + 1);
		printf("   - naslov filma: ");
		fflush(stdin);
		gets(F[i].naslov);
		printf("   - zanr filma: ");
		fflush(stdin);
		gets(F[i].zanr);		
		printf("   - reziser: ");
		fflush(stdin);
		gets(F[i].reziser);
		printf("   - glavni glumac: ");
		fflush(stdin);
		gets(F[i].glumac);
		printf("   - godina izdanja: ");
		scanf("%d", &F[i].godina);		
		printf("   - zarada (u milijunima dolara): ");
		scanf("%f", &F[i].zarada);						
	}
}

void ispisPodataka(struct film F[10])
{
	int i;
	puts("\nFilmovi izdani nakon 2000. godine sa zaradom preko 30 milijuna USD");
	printf("----------\n");
	for(i = 0; i < N; i++)
		if((F[i].godina > 2000) && (F[i].zarada > 30))
			ispisJednogFilma(F[i]);
}

void ispisJednogFilma(struct film F)
{
	printf("Film: %s\n", F.naslov);
	printf("Zanr: %s\n", F.zanr);
	printf("Reziser: %s\n", F.reziser);
	printf("Glavni glumac: %s\n", F.glumac);
	printf("Godina izdanja: %d\n", F.godina);
	printf("Zarada: %.2f milijuna USD\n", F.zarada);
	printf("----------\n");
}

void sortiranje(struct film F[10])
{
	struct film pF;
	int i, j;
	
	for(i = 0; i < N - 1; i++)
		for(j = i + 1; j < N; j++)
			if((F[i].zarada < F[j].zarada) ||
			   ((F[i].zarada == F[j].zarada) && (F[i].godina > F[j].godina)))
			{
				pF = F[i];
				F[i] = F[j];
				F[j] = pF;
			}
}

struct film najvecaZarada(struct film F[N])
{
	struct film FNZ;
	int i; 
	
	FNZ = F[0];
	for(i = 0; i < N; i++)
		if(F[i].zarada > FNZ.zarada)
			FNZ = F[i];
	
	return FNZ;
}
