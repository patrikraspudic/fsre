#include <stdio.h>

int je_li_ispravan(int datum);
int dana_od_pocetka_nove_ere(int datum);
void ispis_datuma(int datum);

int main() 
{
	int datum[3], dani[3], i = 0, j, pom;
	
	while(i < 3)
	{
		printf("Unesi %d. datum u obliku DDMMGGGG: ", i + 1);
		scanf("%d", &datum[i]);
		if(je_li_ispravan(datum[i]) == 1)
		{
			printf("Datum je ispravan!\n", i + 1);
			dani[i] = dana_od_pocetka_nove_ere(datum[i]);
			i++;
		}
		else
		{
			printf("Datum nije ispravan! Pokusaj ponovno.\n", i + 1);
		}
	}
	
	for(i = 0; i < 2; i++)
	{
		for(j = i + 1; j < 3; j++)
		{
			if(dani[i] > dani[j])
			{
				pom = dani[i];
				dani[i] = dani[j];
				dani[j] = pom;
				
				pom = datum[i];
				datum[i] = datum[j];
				datum[j] = pom;
			}
		}
	}
	
	printf("Od ");
	ispis_datuma(datum[1]);
	printf(" i ");
	ispis_datuma(datum[2]);
	printf(" proslo je %d dana.\n", dani[2] - dani[1]);

	return 0;
}

int je_li_ispravan(int datum)
{
	int kontrola = 1;
	int dan, mjesec, godina;
	
	godina = datum % 10000;
	mjesec = (datum / 10000) % 100;
	dan = (datum / 1000000);
	
	/* ovo je detaljna provjera datuma, 
	   priznala bi se i jednostavnija, npr da svaki mjesec ima 30 dana */
	if(mjesec > 12)
	{
		kontrola = 0;
	}
	else if (((mjesec == 1) || (mjesec == 3) || (mjesec == 5) || (mjesec == 7) ||
		(mjesec == 8) || (mjesec == 10) || (mjesec == 12)) && (dan > 31)) 
	{
		kontrola = 0;
	}	
	else if (((mjesec == 4) || (mjesec == 6) || (mjesec == 9) || (mjesec == 11)) && (dan > 30)) 
	{
		kontrola = 0;
	}	
	else if ((mjesec == 2) && (godina % 4 == 0) && (godina % 100 != 0) && (dan > 29))
	{
		kontrola = 0;
	}
	else if	((mjesec == 2) && ((godina % 4 != 0) || ((godina % 4 == 0) && (godina % 100 == 0))) 
		&& (dan > 28))	
	{
		kontrola = 0;
	}	
	
	return kontrola;
}

int dana_od_pocetka_nove_ere(int datum)
{
	int dani = 0, i;
	int dan, mjesec, godina;
	
	godina = datum % 10000;
	mjesec = (datum / 10000) % 100;
	dan = (datum / 1000000);	

	/* ovo je detaljan izracun broja dana proteklih od 01.01.0001.  
	   priznao bi se i jednostavniji, npr da svaki mjesec ima 30 dana, a godina 365 */
	for(i = 1; i < godina; i++)
	{
		if((i % 4 != 0) || ((i % 4 == 0) && (i < 100 == 0)))
		{
			dani += 365;
		}
		else
		{
			dani += 366;
		}
	}	
	
	for(i = 1; i < mjesec; i++)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:	
			case 8:
			case 10:
			case 12:
			{
				dani += 31;
				break;
			}
			case 4:
			case 6:
			case 9:
			case 11:
			{
				dani += 30;
				break;
			}	
			case 2:
			{
				if((godina % 4 != 0) || ((godina % 4 == 0) && (godina < 100 == 0)))
				{
					dani += 28;
				}
				else
				{
					dani += 29;
				}
				break;
			}
		} 
	}
	
	dani += dan;
	return dani;
}

void ispis_datuma(int datum)
{
	int dan, mjesec, godina;
	
	godina = datum % 10000;
	mjesec = (datum / 10000) % 100;
	dan = (datum / 1000000);
	
	printf("%d.%d.%d.", dan, mjesec, godina);
}
