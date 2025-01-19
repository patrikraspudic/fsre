/* 2.
Napisati program koji dinamički zauzima memoriju za 10 stringova maksimalne duljine
od 30 znakova, unosi stringove, sortira ih po duljini uzlazno, odnosno po abecedi (ako je
duljina ista) te ih ispisuje. Koristiti isključivo sintaksu pokazivača.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char **stringovi = NULL;
    int red = 5, duljina = 30;
    char *pom = NULL;
    int i, j;

    stringovi = (char **)malloc(sizeof(char *) * red);

    pom = (char *)malloc(sizeof(char) * 30);

    for (i = 0; i < red; i++)
    {
        *(stringovi + i) = (char *)malloc(sizeof(char) * duljina);
        puts("Unesite neki string: ");
        fflush(stdin);
        gets(*(stringovi + i));
    }

    for (i = 0; i < red - 1; i++)
        for (j = i + 1; j < red; j++)
            if ((strlen(*(stringovi + i)) > strlen(*(stringovi + j))) ||
                ((strlen(*(stringovi + i)) == strlen(*(stringovi + j))) && (strcmp(*(stringovi + i), *(stringovi + j)) > 0)))
            {
                strcpy(pom, *(stringovi + i));
                strcpy(*(stringovi + i), *(stringovi + j));
                strcpy(*(stringovi + j), pom);
            }
    puts("\n");
    for (i = 0; i < red; i++)
        puts(*(stringovi + i));

    for (i = 0; i < red; i++)
        free(*(stringovi + i));
    free(stringovi);
    free(pom);

    return 0;
}