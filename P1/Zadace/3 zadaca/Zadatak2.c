/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    char niz[50], uneseniZnak;
    int i = 0, brojSamoglasnika[5] = { 0, 0, 0, 0, 0 }, j;

    do {
        printf("Unesite neki znak: ");
        scanf(" %c", &uneseniZnak);
        niz[i] = uneseniZnak;
        i++;
    } while (i < 4 || niz[i - 4] != 'k' || niz[i - 3] != 'r' || niz[i - 2] != 'a' || niz[i - 1] != 'j');

    for (j = 0; j < i; j++) {
        switch (niz[j]) {
            case 'A':
            case 'a':
                brojSamoglasnika[0]++;
                break;
            case 'E':
            case 'e':
                brojSamoglasnika[1]++;
                break;
            case 'I':
            case 'i':
                brojSamoglasnika[2]++;
                break;
            case 'O':
            case 'o':
                brojSamoglasnika[3]++;
                break;
            case 'U':
            case 'u':
                brojSamoglasnika[4]++;
                break;
            default:
                break;
        }
    }
    printf("Broj unesenih samoglasnika je:\n A, a: %d\n E, e: %d\n I, i: %d\n O, o: %d\n U, u: %d", brojSamoglasnika[0], brojSamoglasnika[1], brojSamoglasnika[2], brojSamoglasnika[3], brojSamoglasnika[4]);
    return 0;
}
