/*5.Napisati program koji unosi 10 rečenica i ispisuje samo one kod kojih se neka riječ
ponavlja barem dva puta.*/
#include <stdio.h>
#include <string.h>

int provjeri_ponavljanje(char recenica[]);

int main()
{
    char recenica[10][100];
    int i;

    printf("Unesite 10 recenica:\n");

    for (i = 0; i < 10; i++)
    {
        fflush(stdin);
        gets(recenica[i]);
        if (recenica[i][strlen(recenica[i]) - 1] == '\n')
        {
            recenica[i][strlen(recenica[i]) - 1] = '\0';
        }
    }

    printf("Recenice u kojima se rijec ponavlja barem dva puta:\n");

    for (i = 0; i < 10; i++)
    {
        if (provjeri_ponavljanje(recenica[i]))
        {
            printf("%s\n", recenica[i]);
        }
    }

    return 0;
}

int provjeri_ponavljanje(char recenica[])
{
    char rijec[100][100];
    int brojac = 0;
    int i, j = 0;

    for (i = 0; i < strlen(recenica); i++)
    {
        if (recenica[i] != ' ')
        {
            rijec[brojac][j++] = recenica[i];
        }
        else
        {
            rijec[brojac][j] = '\0';
            brojac++;
            j = 0;
        }
    }

    for (i = 0; i <= brojac; i++)
    {
        for (j = i + 1; j <= brojac; j++)
        {
            if (strcmp(rijec[i], rijec[j]) == 0)
            {
                return 1;
            }
        }
    }

    return 0;
}