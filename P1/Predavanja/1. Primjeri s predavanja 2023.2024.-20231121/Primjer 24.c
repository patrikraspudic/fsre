/* Napravi program koji unosi znakove sve dok se ne svaki od samoglasnika 
   ne unese barem po dva puta (bez obzira radi li se o velikom ili malom 
   slovu), a nakon toga funkcijom paran_broj_ponavljanja() ispisuje one 
   znakove koji su uneseni paran broj puta i to na naèin da ih ispise onoliko 
   puta koliko se puta ponavljaju  */

#include <stdio.h>

void paran_broj_ponavljanja(char znak[100], int n);

int main() 
{
	int bA = 0, bE = 0, bI = 0, bO = 0, bU = 0;
	char znak[100];
	int i = 0;
	
	printf("Unosi znakove dok se svaki samoglasnik ne unese barem dva puta:\n");
	do
	{
		fflush(stdin);
		scanf("%c", &znak[i]);
		switch(znak[i])
		{
			case 'a':
			case 'A':
				{
					bA++; break;
				}
			case 'e':
			case 'E':
				{
					bE++; break;
				}
			case 'i':
			case 'I':
				{
					bI++; break;
				}
			case 'o':
			case 'O':
				{
					bO++; break;
				}
			case 'u':
			case 'U':
				{
					bU++; break;
				}												
		}
		i++;
	}
	while((bA < 2) || (bE < 2) || (bI < 2) || (bO < 2) || (bU < 2));
	
	paran_broj_ponavljanja(znak, i);
	
	return 0;
}

void paran_broj_ponavljanja(char znak[100], int n)
{
	int i, j, k, bp;
	
	printf("Znakovi koji se ponavljaju paran broj puta su:\n");
	for(i = 0; i < n; i++)
	{
		bp = 0;
		for(j = 0; j < n; j++)
		{
			if(znak[i] == znak[j])
			{
				bp++;
			}
		}
		if(bp % 2 == 0)
		{
			for(k = 0; k < bp; k++)
			{
				printf("%c", znak[i]);
			}
			printf("\n");
		}
	}
}
