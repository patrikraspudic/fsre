#include <stdio.h>

int main() 
{
	int baza6, baza10 = 0, tf = 1, pom;
	
	printf("Unesi broj u zapisu s bazom 6: ");
	scanf("%d", &baza6);
	
	pom = baza6;
	while(pom != 0)
	{
		baza10 = baza10 + (pom % 10) * tf;
		pom = pom / 10;
		tf = tf * 6;
	}
	
	printf("(%d)6 = (%d)10\n", baza6, baza10);
	
	
	return 0;
}
