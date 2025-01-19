/* Napravi program koji u funkciji unos() unosi realne brojeve sve dok se ne 
unese broj ciji je realni dio barem 100 puta veci od njegovog decimalnog 
dijela, a zatim u funkciji obrada_podataka() pronalazi najmanji i najveci 
uneseni broj, te njihovu aritmeticku sredinu, te koristenjem funkcije 
suma_znamenki() pronalazi sumu znamenki cijelog dijela pronadjene aritmeticke 
sredine najmanjeg i najveceg broja. Svi rezultati se ispisuju u glavnom programu. */


#include <stdio.h>

void unos(float niz[100], int *i);
void obrada_podataka(float niz[100], int i, float *min, float *max, float *as);
int suma_znamenki(float as);

int main()
{
	float niz[100], min, max, as;
	int sz, i;
	
	unos(niz, &i);
	obrada_podataka(niz, i, &min, &max, &as);
	printf("Najmanji uneseni broj je %.2f, a najveci %.2f.\n", min, max);
	printf("Njihova aritmeticka sredina je %.2f.\n", as);
	
	sz = suma_znamenki(as);
	printf("Suma znamenki cijelog dijela aritmeticke sredine je %d.\n", sz);

	return 0;
}

void unos(float niz[100], int *i)
{
	int n = 0, kontrola = 0;
	
	*i = 0;
	printf("Unosi realne brojeve (realni dio barem 100 puta veci od decimalnog dijela za kraj):\n");
	do
	{
		scanf("%f", &niz[n]);
		if((int) niz[n] > (100 * (niz[n] - (int) niz[n])))
		{
			kontrola = 1;
		}
		n++;
	}
	while(kontrola == 0);
	*i = n;
}

void obrada_podataka(float niz[100], int i, float *min, float *max, float *as)
{
	int j;
	
	*min = niz[0];
	*max = niz[0];
	for(j = 0; j < i; j++)
	{
		if(niz[j] < *min)
		{
			*min = niz[j];
		}
		if(niz[j] > *max)
		{
			*max = niz[j];
		}
	}
	
	*as = (*min + *max) / 2;
}

int suma_znamenki(float as)
{
	int zbroj = 0, cd_as;
	
	cd_as = (int) as;
	
	while(cd_as != 0)
	{
		zbroj += cd_as % 10;
		cd_as /= 10;
	}
	
	return zbroj;
}

