/* primjer pokazuje oblik IF-ELSE grananja u kojem postoji samo
   blok instrukcija za ispunjen uvjet
   primjer unosi cijeli broj i ukoliko je on neparan ispisuje ga, 
   a ukoliko je paran, ispisuje ga kao umnozak ciji je jedan 
   faktor broj 2 
   
   25 = 25
   18 = 2 * 9
   */

#include <stdio.h>

int main() 
{
	int x, pom;
	
	printf("Unesi jedan cijeli broj: ");
	scanf("%d", &x);
	
	printf("%d = ", x);
	pom = x;
	
	/* IF grananje bez ELSE bloka */
	if(x % 2 == 0)
	{
		/* blok za ispunjen uvjet */
		printf("2 * ");	
		pom = pom / 2;
	}
	
	printf("%d\n", pom);
	
	return 0;
}
