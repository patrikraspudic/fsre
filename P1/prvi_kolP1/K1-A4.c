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
	 
	if (h < 12)
	{
		odPodne = 12 * 60 * 60;			/* od podne do ponoci */
		odPodne = odPodne + h * 60 * 60 + m * 60 + s;
	}
	else
	{
		odPodne = (h - 12) * 60 * 60 + m * 60 + s;		
	}
	
	printf("Od prethodnog podneva proteklo je %d sekundi.\n", odPodne);
	return 0;
}
