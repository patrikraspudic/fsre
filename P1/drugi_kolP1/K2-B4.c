/*Napravi program koji unosi realne brojeve sve dok se 
dva puta zaredom ne unese broj sa decimalnim dijelom manjim od 0.25,
a zatim u funkciji obrada_podataka() izračunava prosjek
svih unesenih brojeva i pronalazi najveći uneseni broj. 
Rezultati se ispisuju u glavnom programu.*/
#include <stdio.h>

void obrada_podataka(float broj[100], int i, float *prosjek, float *najveci);

int main() 
{
	float broj[100], prosjek, najveci;
	int i = 0;
	
	printf("Unosi realne brojeve (dva sa decimalnim dijelom manjim od 0.25 za kraj):\n");
	do
	{
		scanf("%f", &broj[i]);
		i++;
	}
	while((i < 2)|| ((broj[i - 1] - (int)broj[i - 1]) > 0.25) 
				 || ((broj[i - 2] - (int)broj[i - 2]) > 0.25));
	
	obrada_podataka(broj, i, &prosjek, &najveci);
	
	printf("Prosjek unesenih brojeva je %f.\n", prosjek);
	printf("Najveci uneseni broj je %f.\n", najveci);
	
	/* kraj */
	return 0;
}

void obrada_podataka(float broj[100], int i, float *prosjek, float *najveci)
{
	float zbroj = 0; 
	int j;
	
	*najveci = broj[0];
	 
	for(j = 0; j < i; j++)
	{
		zbroj = zbroj + broj[j];
		if(*najveci < broj[j])
		{
			*najveci = broj[j];
		}
	}
	*prosjek = zbroj / i;
}
