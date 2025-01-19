/*Napravi program koji u funkciji unos() unosi velika slova engleskog alfabeta 
(zanemarujući ostale unesene znakove) sve dok se ne unese znak '!', 
a zatim u funkciji paran_broj_ponavljanja()
ispisuje one znakove koji su uneseni paran broj puta.*/
#include <stdio.h>

void unos(char znak[100], int *i);
int paran_broj_ponavljanja(char znak[100], int i);

int main() 
{
	char znak[100];
	int i, j;
	
	unos(znak, &i);
	paran_broj_ponavljanja(znak, i);
	
	/* kraj */
	return 0;
}

void unos(char znak[100], int *i)
{
	int kontrola = 0;
	
	*i = 0;
	printf("Unosi velika slova engleskog alfabeta (! za kraj):\n");
	do
	{
		fflush(stdin);
		scanf("%c", &znak[*i]);
		if((znak[*i] >= 'A') && (znak[*i] <= 'Z'))
		{
			(*i)++;
		}
		else
		{
			if(znak[*i] == '!')
			{
				kontrola = 1;
			}
			else
			{
				printf("Nije veliko slovo engleskog alfabeta!\n");
			}
		}		
	}
	while(kontrola == 0);
}

int paran_broj_ponavljanja(char znak[100], int i)
{
	int j, k, bp;
	
	printf("Znakovi koji se ponavljaju paran broj puta su:\n");
	for(j = 0; j < i; j++)
	{
		bp = 0;
		for(k = 0; k < i; k++)
		{
			if(znak[k] == znak[j])
			{
				bp++;
			}
		}
		if(bp % 2 == 0)
		{
			printf("%c\n", znak[j]);
		}
	}
}
