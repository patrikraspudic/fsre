/*1. Napisati program koji unosi tekst i formira novi string u kojem je svaki zna zamijenjen
skupinom od tri znaka koji predstavljaju ASCII kod tog znaka (npr. slovo 'A' mijenja se
skupinom znakova "065", a slovo 'm' skupinom znakova "109") te se formirani string
ispisuje na ekran.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char ulaz[256],novi[256];
    int i,j = 0;

    printf("Unesi neki string: ");
    fflush(stdin);
    gets(ulaz);

    for(i = 0;i < strlen(ulaz);i++)
    {
        if(isprint(ulaz[i]))
        {
            
            novi[j++] = (ulaz[i] / 100) + '0'; // Stotice
            novi[j++] = ((ulaz[i] / 10) % 10) + '0'; // Desetice
            novi[j++] = (ulaz[i] % 10) + '0'; // Jedince
        }
        
    }
    novi[j] = '\0';

    printf("Formirani string:\n%s",novi);

    return 0;
}