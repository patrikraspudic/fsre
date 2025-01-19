/* Patrik Raspudić, indeks 2233/RR */

#include <stdio.h>

void prikaziZapise(int dcb) {
    printf("Binarno: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (dcb >> i) & 1);
    }

    printf("\nOktalno: ");
    int oktalniZapis[3];
    int temp = dcb;
    for (int i = 2; i >= 0; i--) {
        oktalniZapis[i] = temp % 8;
        temp /= 8;
    }
    for (int i = 0; i < 3; i++) {
        printf("%d", oktalniZapis[i]);
    }

    printf("\nHeksadecimalno: ");
    char heksCifre[] = "0123456789ABCDEF";
    int heksZapis[2];
    temp = dcb;
    for (int i = 1; i >= 0; i--) {
        heksZapis[i] = temp % 16;
        temp /= 16;
    }
    for (int i = 0; i < 2; i++) {
        printf("%c", heksCifre[heksZapis[i]]);
    }

    printf("\n");
}

int main() {
    int dcb;

    printf("Unesite dekadski broj (iz intervala [0, 255]): ");
    scanf("%d", &dcb);

    if (dcb < 0 || dcb > 255) {
        printf("Uneseni broj nije u intervalu [0, 255].\n");
        return 1; 
    }

    prikaziZapise(dcb);

    return 0; 
}
