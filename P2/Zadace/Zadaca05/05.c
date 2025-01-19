/*5.
Napisati program koji iz datoteke drzave.txt čita podatke o svim državama zapisanima u
datoteci: naziv države (string - pretpostaviti da se radi o jednoj riječi), glavni grad (string -
pretpostaviti da se radi o jednoj riječi), kontinent (string - pretpostaviti da se radi o
jednoj riječi), površina države u kvadratnim kilometrima (int) i broj stanovnika (int).
Nakon toga ispisuju se podaci o azijskim državama sa manje od 10.000.000 stanovnika
sortirani po broju stanovnika države uzlazno.
*/
#include <stdio.h>
#include <string.h>
struct drzave
{
    char drzava[16];
    char glavniGrad[16];
    char kontinent[16];
    int povrsina;
    int brojStanovnika;
};
int main()
{
    struct drzave d[5], pom;
    int i = 0, j, k;
    FILE *dat;

    dat = fopen("drzave.txt", "r");
    if (dat == NULL)
    {
        printf("Greska pri otvaranju datoteke.\n");
    }
    while (fscanf(dat, "%s %s %s %d %d\n", &d[i].drzava, &d[i].glavniGrad, &d[i].kontinent, &d[i].povrsina, &d[i].brojStanovnika) == 5)
    {
        i++;
    }
    fclose(dat);

    for (j = 0; j < i - 1; j++)
        for (k = j + 1; k < i; k++)
            if (d[j].brojStanovnika > d[k].brojStanovnika)
            {
                pom = d[j];
                d[j] = d[k];
                d[k] = pom;
            }
    j = 0;
    for (k = 0; k < i; k++)
        if ((strcmp(d[k].kontinent, "Azija")) == 0 && (d[k].brojStanovnika < 10000000))
        {
            printf("%d. drzava\n", ++j);
            printf("%s\n%s\n%s\n%d\n%d\n\n", d[k].drzava, d[k].glavniGrad, d[k].kontinent, d[k].povrsina, d[k].brojStanovnika);
        }
    return 0;
}