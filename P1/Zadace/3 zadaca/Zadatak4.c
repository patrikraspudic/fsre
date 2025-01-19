/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

int main() {
    char znakovi[1000];
    int i = 0;
    char c[2];

    printf("Unesite znakove jedan po jedan. Unesite 'x' za kraj.\n");

    while(1) {
        scanf("%s", c);
        if(c[0] == 'x') {
            break;
        }
        znakovi[i++] = c[0];
    }

    for(int j = 0; j < i; j++) {
        if(znakovi[j] >= 'A' && znakovi[j] <= 'Z' || znakovi[j] >= 'a' && znakovi[j] <= 'z') {
            printf("%c", znakovi[j]);
        } else {
            printf("%d", znakovi[j]);
        }
    }

    return 0;
}
