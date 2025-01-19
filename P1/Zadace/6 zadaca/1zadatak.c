/*Patrik Raspudic 2233/rr*/
/*Napisati program koji unosi 10 znakova i u funkciji ispis() ispisuje ih na način da za svako
malo slovo engleskog alfabeta ispiše odgovarajuće veliko i obratno, dok sve znakove koji
nisu slova engleskog alfabeta ispisuje kako su i uneseni. Dodatno, za svaki znak u
zagradama, iza ispisanog znaka, ispisuje i njegov ASCII kod*/

#include<stdio.h>

void ispis(char z[10]);

int main()
{
	char znak[10];
	int i;
	printf("Unesite 10 znakova\n");
	for(i= 0;i < 10;i++)
	{
		scanf(" %c", &znak[i]);
	}
	printf("Njihov ispis:\n");
	ispis(znak);
	return 0;
}
void ispis(char z[10])
{
	int i;
	for(i = 0; i < 10;i++)
	{
		if(z[i] >= 'a' && z[i] <= 'z')
		{
			printf(" %c %c (%d)\n",z[i],z[i] - 32,z[i]);
		}
		else if(z[i] >= 'A' && z[i] <= 'Z')
		{
			printf(" %c %c (%d)\n", z[i], z[i] + 32, z[i]);
		}
		else if(!((z[i] >= 'a' && z[i] <= 'z') || (z[i] >= 'A' && z[i] <= 'Z')))
		{
			printf(" %c (%d)\n", z[i], z[i]);
		}
	}
}