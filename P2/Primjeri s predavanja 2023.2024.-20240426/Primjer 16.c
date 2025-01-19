/* primjer definira strukturu grad sa clanovima: naziv grada, drzava grada, broj stanovnika,
   povrsina u kilometrima kvadratnim, inicijalizira niz od 10 gradova i ispisuje, sortirane 
   po abecedi gradove iz Bosne i Hercegovine s najmanje 20.000 stanovnika, pri cemu se ispisuju
   svi podaci o gradu */  

#include <stdio.h>
#include <string.h>

struct grad
{
	char naziv[32];
	char drzava[32];
	int brojStanovnika;
	float povrsina;
};

void sortirajAbecedno(struct grad G[10]);
void ispisGrada(struct grad G);

int main() 
{
	struct grad G[10] = {{"Mostar", "Bosna i Hercegovina", 103124, 25.64},
						 {"Zagreb", "Hrvatska", 826541, 106.45},
						 {"Sarajevo", "Bosna i Hercegovina", 651124, 38.45}, 
						 {"Beograd", "Srbija", 1865124, 184.11},
						 {"Banja Luka", "Bosna i Hercegovina", 256145, 30.11}, 
						 {"Stolac", "Bosna i Hercegovina", 15124, 28.14},
						 {"Split", "Hrvatska", 310541, 45.45},
						 {"Capljina", "Bosna i Hercegovina", 24124, 29.45}, 
						 {"Novi Sad", "Srbija", 125124, 45.11},
						 {"Ljubljana", "Slovenija", 451245, 44.17}}; 
	int i;
	
	sortirajAbecedno(G);
	puts("Gradovi u Bosni i Hercegovini s vise od 20000 stanovnika su:");
	for(i = 0; i < 10; i++)
		if((G[i].brojStanovnika > 20000) && (strcmp(G[i].drzava, "Bosna i Hercegovina") == 0))
			ispisGrada(G[i]);

	return 0;
}

void sortirajAbecedno(struct grad G[10])
{
	struct grad pG;
	int i, j;
	
	for(i = 0; i < 9; i++)
		for(j = i + 1; j < 10; j++)
			if(stricmp(G[i].naziv, G[j].naziv) > 0)
			{
				pG = G[i];
				G[i] = G[j];
				G[j] = pG;
			}
}

void ispisGrada(struct grad G)
{
	printf("Grad %s (%s) ima %d stanovnika i zauzima povrsinu of %.2f kilometara kvadratnih.\n", 
		G.naziv, G.drzava, G.brojStanovnika, G.povrsina);
}
