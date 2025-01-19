/*Napravi program koji u funkciji unos() unosi mala slova engleskog alfabeta 
(zanemarujući ostale unesene znakove) sve dok se ne unese znak '*', 
a zatim u funkciji neparan_broj_ponavljanja()
ispisuje ona slova koja su uneseni neparan broj puta.*/
#include <stdio.h>

void unos(char znak[100], int *i);
int neparan_broj_ponavljanja(char znak[100], int i);

int main() 
{
	char znak[100];
	int i, j;
	
	unos(znak, &i);
	neparan_broj_ponavljanja(znak, i);
	
	/* kraj */
	return 0;
}

void unos(char znak[100], int *i)
{
	int kontrola = 0;
	
	*i = 0;
	printf("Unosi mala slova engleskog alfabeta (* za kraj):\n");
	do
	{
		fflush(stdin);
		scanf("%c", &znak[*i]);
		if((znak[*i] >= 'a') && (znak[*i] <= 'z'))
		{
			(*i)++;
		}
		else
		{
			if(znak[*i] == '*')
			{
				kontrola = 1;
			}
			else
			{
				printf("Nije malo slovo engleskog alfabeta!\n");
			}
		}		
	}
	while(kontrola == 0);
}

int neparan_broj_ponavljanja(char znak[100], int i)
{
	int j, k, bp;
	
	printf("Znakovi koji se ponavljaju neparan broj puta su:\n");
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
		if(bp % 2 != 0)
		{
			printf("%c\n", znak[j]);
		}
	}
}
