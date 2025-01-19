/* Patrik Raspudić, indeks 2233/RR */

#include <stdio.h>

void print_binary(int n) {
    if (n > 1) {
        print_binary(n/2);
    }
    printf("%d", n % 2);
}

int main() {
    int dcb;
    printf("Unesite dekadski cijeli broj iz intervala [0, 255]: ");
    scanf("%d", &dcb);

    if(dcb < 0 || dcb > 255) {
        printf("Broj nije u zadanom intervalu.\n");
        return 1;
    }

    printf("Dekadski broj %d u bazi 2 je: ", dcb);
    print_binary(dcb);
    printf("\n");
    printf("Dekadski broj %d u bazi 8 je: %o\n", dcb, dcb);
    printf("Dekadski broj %d u bazi 16 je: %x\n", dcb, dcb);

    return 0;
}