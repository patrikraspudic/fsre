#include <stdio.h>

int main() 
{
	int baza9, baza10 = 0, tf = 1, pom;
	
	printf("Unesi broj u zapisu s bazom 9: ");
	scanf("%d", &baza9);
	
	pom = baza9;
	while(pom != 0)
	{
		baza10 = baza10 + (pom % 10) * tf;
		pom = pom / 10;
		tf = tf * 9;
	}
	
	printf("(%d)9 = (%d)10\n", baza9, baza10);
	
	
	return 0;
}
