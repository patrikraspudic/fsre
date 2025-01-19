/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    int broj1, broj2, broj3, broj4;
    printf("Unesite četiri prirodna broja:\n");
    scanf("%d%d%d%d", &broj1, &broj2, &broj3, &broj4);

    // Računanje NZD-a unutar main funkcije
    int temp = broj1;
    int brojevi[4] = {broj1, broj2, broj3, broj4};
    for(int i = 1; i < 4; i++) {
        int a = temp, b = brojevi[i];
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        temp = a;
    }

    printf("Najveći zajednički djelitelj unesenih brojeva je: %d\n", temp);
    return 0;
}