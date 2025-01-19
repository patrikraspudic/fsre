/* Napravi program koji unosi N = 10 cijelih brojeva i meðu njima pronalazi i 
   ispisuje one brojeve koji su neparni, dvoznamenkasti, prosti i imaju znamenku 3  */

#include <stdio.h>
#define N 10

int prost(int n);
int ima_li_znamenku_3(int n);

int main() 
{
	int niz[N], i;
	
	/* unos brojeva */
	printf("Unesi %d cijelih brojeva:\n", N);
	for(i = 0; i < N; i++)
	{
		scanf("%d", &niz[i]);
	}
	
	/* ispis neparnih, dvoznamenkastih, prostih brojeva koji imaju znamenku 3 */
	printf("Medju unesenim brojevima neparni, dvoznamenkasti, prosti  brojevi koji imaju znamenku 3 su:\n");
	for(i = 0; i < N; i++) 
	{
		if(niz[i] % 2 == 1)
		{
			if((niz[i] > 9) && (niz[i] < 100))
			{
				if(prost(niz[i]) == 1)
				{
					if(ima_li_znamenku_3(niz[i]) == 1)
					{
						printf("%d\n", niz[i]);						
					}
				}	
			}
		}
	}	


	return 0;
}

int prost(int n)
{
	int rezultat = 1;
	int i;
	
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			rezultat = 0;
		}
	}

	return rezultat; 
}

int ima_li_znamenku_3(int n)
{
	int rezultat = 0;
	
	while(n != 0)
	{
		if(n % 10 == 3)
		{
			rezultat = 1;
		}
		n /= 10;
	}
	
	return rezultat;
}
