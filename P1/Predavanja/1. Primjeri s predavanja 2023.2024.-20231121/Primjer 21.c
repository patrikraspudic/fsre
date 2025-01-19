/* Napravi program koji unosi cijeli broj u dekadskom zapisu i ispisuje koliko se 
   puta u njegovom binarnom zapisu pojavljuje znamenka 1 */

#include <stdio.h>

int main() 
{
	int dek_broj, pom_broj, bin_zn[32] = {0}, i = 31, brojac = 0;
	
	/* unos broja */
	printf("Unesi broj u dekadskom zapisu: ");
	scanf("%d", &dek_broj);
	pom_broj = dek_broj;
	
	/* pretvaranje u binarni zapis */
	while(pom_broj != 0)
	{
		bin_zn[i] = pom_broj % 2;
		pom_broj /= 2;
		i--;
	}
	
	/* ispis broja u binarnom zapisu */
	printf("(%d)10 = (", dek_broj);
	for(i = 0; i < 32; i++)
	{
		printf("%d", bin_zn[i]);
	}
	printf(")2\n");
	
	/* prebrojavanje 1 u binarnom zapisu */
	for(i = 0; i < 32; i++)
	{
		if(bin_zn[i] == 1)
		{	
			brojac++;
		}	
	}
	printf("U binarnom zapisu broja %d ima %d jedinica.\n", dek_broj, brojac);
	return 0;
}

/*LAKSI I BOLJI NACIN 
#include<stdio.h>
int main()
{
    int broj10,pom,broj2 = 0,tf = 1, brojac = 0,i;
    printf("Unesi broj u dekadskom zapisu\n");
    scanf("%d",&broj10);
    pom = broj10;
    while(pom != 0)
    {
        broj2 = broj2 + (pom % 2) * tf;
        pom = pom / 2;
        tf = tf * 10;
    }
    printf("(%d)10 = (%d)2",broj10,broj2);
    while (broj2 != 0)
    {
        if (broj2 % 10 == 1)
        {
            brojac++;
        }
        broj2 = broj2 / 10;
    }
    printf("U binarnom zapisu broja %d ima %d jeidnica\n",broj10,brojac);
    return 0;
}
*/

/*IZ NEKE BAZA U BINARNU
#include<stdio.h>
int main()
{
    int broj8,broj10 = 0,pom,broj2 = 0,tf = 1,tf2 = 1, brojac = 0,i;
    printf("Unesi broj u oktalnom zapisu\n");
    scanf("%d",&broj8);
    pom = broj8;
    while(pom != 0)
    {
        broj10 = broj10 + (pom % 10) * tf;
        pom = pom / 10;
        tf = tf * 8;
    }
    pom = broj10;
    while(pom != 0)
    {
        broj2 = broj2 + (pom % 2) * tf2;
        pom = pom / 2;
        tf2 = tf2 * 10;
    }
    printf("(%d)8 = (%d)2\n",broj8,broj2);
    while (broj2 != 0)
    {
        if (broj2 % 10 == 1)
        {
            brojac++;
        }
        broj2 = broj2 / 10;
    }
    printf("U binarnom zapisu broja %d ima %d jeidnica\n",broj10,brojac);
    return 0;
}
*/