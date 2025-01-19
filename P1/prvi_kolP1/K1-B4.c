/*Napravi program koji unosi vrijeme u obliku HHMMSS (zapisane pomoću cijelog broja),
provjerava radi li se o ispravnom vremenu i ispisuje koliko je vremena u sekundama preostalo od
unesenog vremena do sljedećeg podneva (npr. 214438 predstavlja 21 sat, 44 minute i 38
sekundi; 746 predstavlja 0 sati, 7 minuta i 46 sekundi).*/

#include <stdio.h>

int main() 
{
	int vrijeme, h, m, s, odPodne = 0;
	
	printf("Unesi vrijeme u obliku HHMMSS: ");
	scanf("%d", &vrijeme);
	
	s = vrijeme % 100;
	vrijeme = vrijeme / 100;
	m = vrijeme % 100;
	h = vrijeme / 100;
	
	if((h > 23) || (m > 59) || (s > 59))
	{
		printf("Neispravno vrijeme!\n");
	}
	else
	{
		printf("Vrijeme je %d:%d:%d\n", h, m, s);
	}
	 
	if (h > 11)
	{
		odPodne = 12 * 60 * 60;			/* od pono�i do podne */
		odPodne = odPodne + (23 - h) * 60 * 60 + (59 - m) * 60 + (60 - s);
	}
	else
	{
		odPodne = (11 - h) * 60 * 60 + (59 - m) * 60 + (60 - s);		
	}
	
	printf("Do sljeeceg podneva preostalo je %d sekundi.\n", odPodne);
	return 0;
}
