/*4.
Napisati program koji dinamički alocira memoriju za string koji se formira spajanjem
unesenih stringova na način da se u obzir uzimaju samo velika slova engleskog alfabeta iz
unesenih stringova. Memorija se realocira prije dodavanja svakog znaka u formirani
string. Unos prestaje u trenutku kada broj suglasnika u formiranom stringu bude veći od
30. Nakon toga string se ispisuje. Koristiti isključivo sintaksu pokazivača.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int suglasnik(char c);
int main()
{
    int bs = 0, duljina = 0, boolean = 0;
    char *input = NULL, *s = NULL;
    int i, j;
    input = (char *)malloc(sizeof(char) * 128);
    puts("Unosite stringove dok im broj suglasnika nije veci od 30");
    while (!boolean)
    {
        fflush(stdin);
        gets(input);
        for (i = 0; i < strlen(input); i++)
        {
            if (isupper(*(input + i)))
            {
                s = (char *)realloc(s, sizeof(char) * (duljina + 1));
                *(s + duljina) = *(input + i);
                duljina++;
                if (suglasnik(*(input + i)))
                {
                    bs++;
                    boolean = bs > 30;
                }
            }
        }
    }
    *(s + duljina) = '\0';
    puts("\nIspis:");
    puts(s);
    free(s);

    return 0;
}
int suglasnik(char c)
{
    char *samoglasnici = "AEIOU";
    int i;
    for (i = 0; i < strlen(samoglasnici); i++)
        if (tolower(c) == *(samoglasnici + i))
            return 0;
    return 1;
}