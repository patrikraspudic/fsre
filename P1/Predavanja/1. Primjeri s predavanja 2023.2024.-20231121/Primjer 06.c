/* primjer pokazuje rad višestrukog grananja SWITCH-CASE
   primjer unosi jedan znak i ukoliko je to samoglasnik
   ispisuje o kojem se samoglasniku radi, a u suprotnom
   ispisuje samo poruku da uneseni znak nije samoglasnik */

#include <stdio.h>

int main() 
{
	char zn;
	
	printf("Unesi jedan znak: ");
	scanf("%c", &zn);
	
	/* višestruko grananje SWITCH-CASE */
	switch(zn)
	{
		case 'a':
		case 'A':
		{
			/* blok instrukcija za vrijednosti 'a' i 'A' */
			printf("Unesen je samoglasnik A.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}		
		case 'e':
		case 'E':
		{
			/* blok instrukcija za vrijednosti 'e' i 'E' */
			printf("Unesen je samoglasnik E.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}
		case 'i':
		case 'I':
		{
			/* blok instrukcija za vrijednosti 'i' i 'I' */
			printf("Unesen je samoglasnik I.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}		
		case 'o':
		case 'O':
		{
			/* blok instrukcija za vrijednosti 'o' i 'O' */
			printf("Unesen je samoglasnik O.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}		
		case 'u':
		case 'U':
		{
			/* blok instrukcija za vrijednosti 'u' i 'U' */
			printf("Unesen je samoglasnik U.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}
		default:
		{
			/* blok instrukcija za nepobrojane vrijednosti */
			printf("Nije unesen samoglasnik.\n");
			break;		/* svaki CASE zavrsava instrukcijom break; */
		}
	}

	return 0;
}
