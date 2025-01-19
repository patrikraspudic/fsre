/* primjer unosi 5 recenica i formira strukture sa clanovima: tekst recenice, 
   broj rijeci u recenici, rijec koja je prva po abecedi, broj samoglasnika i 
   prosjek ASCII kodova znakova recenice i ispisuje podatke o recenici koja ima
   najvise rijeci i onoj ciji je prosjek ASCII kodova znakova najmanji */ 

#include <stdio.h>
#include <string.h>

struct Recenica
{
	char tekstRecenice[128];
	int brojRijeci;
	char prvaPoAbecedi[32];
	int brojSamoglasnika;
	float prosjekASCII;
};

struct Recenica formirajStrukturu(char Rec[128]);
void ispisiStrukturu(struct Recenica Rec);

int main() 
{
	char unesenaRecenica[128];
	int i;
	struct Recenica R[5], RNR, RNP;
	
	/* unos recenica i formiranje struktura */
	puts("Unesi 5 recenica:");
	for(i = 0; i < 5; i++)
	{
		printf(" %d. recenica: ", i + 1);
		fflush(stdin);
		gets(unesenaRecenica);
		R[i] = formirajStrukturu(unesenaRecenica);
	}
	
	/* ispis recenice s najvise rijeci */
	RNR = R[0];
	for(i = 0; i < 5; i++)
		if(R[i].brojRijeci > RNR.brojRijeci)
			RNR = R[i];
	puts("\nRecenica s najvise rijeci:");
	ispisiStrukturu(RNR);

	/* ispis recenice s najmanjim prosjekom ASCII kodova znakova */
	RNP = R[0];
	for(i = 0; i < 5; i++)
		if(R[i].prosjekASCII < RNP.prosjekASCII)
			RNP = R[i];
	puts("\nRecenica s najmanjim prosjekom ASCII kodova znakova:");
	ispisiStrukturu(RNP);	
	return 0;
}

struct Recenica formirajStrukturu(char Rec[128])
{
	struct Recenica rezultat;
	int i, j, br = 0, bs = 0, zbrojASCII = 0;
	char rijeci[16][16], samoglasnici[] = "AaEeIiOoUu", prva[16];
	
	strcpy(rezultat.tekstRecenice, Rec);
	rezultat.brojSamoglasnika = 0;
	for(i = 0; i <= strlen(Rec); i++)
	{
		for(j = 0; j < 10; j++)
			if(samoglasnici[j] == Rec[i])
				rezultat.brojSamoglasnika++;
		zbrojASCII += Rec[i];
		if((Rec[i] == ' ') || (Rec[i] == '\0'))
		{
			rijeci[br][bs] = '\0';
			br++;
			bs = 0;
		}
		else
		{
			rijeci[br][bs] = Rec[i];
			bs++;
		}
	}
	
	rezultat.brojRijeci = br;
	rezultat.prosjekASCII = zbrojASCII / (float) strlen(Rec);
	
	strcpy(prva, rijeci[0]);
	for(i = 0; i < br; i++)
		if(stricmp(prva, rijeci[i]) > 0)
			strcpy(prva, rijeci[i]);
	strcpy(rezultat.prvaPoAbecedi, prva);
	
	return rezultat;
}

void ispisiStrukturu(struct Recenica Rec)
{
	printf("Tekst recenica: %s\n", Rec.tekstRecenice);
	printf("Broj rijeci u recenici: %d\n", Rec.brojRijeci);
	printf("Prva rijec po abecedi: %s\n", Rec.prvaPoAbecedi);
	printf("Broj samoglasnika u recenici: %d\n", Rec.brojSamoglasnika);
	printf("Prosjek ASCII kodova znakova recenice: %.2f\n", Rec.prosjekASCII);
	puts("----------");
}
