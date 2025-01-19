/* Patrik Raspudić, indeks 2233/RR */
#include <stdio.h>

void main() {

	double brojevi[20], cijeliDio, decimalniDio;
	int i = 0;
	printf("Molimo unosite 20 realnih brojeva\n");
	for (i = 0; i < 20; i++) {
		scanf("%lf", &brojevi[i]);
	}
	printf("Brojevi ciji je cijeli nije barem 100 puta veci od njihovog decimalnog dijela su:\n");
	for (i--; i >= 0; i--) {
		decimalniDio = brojevi[i] - (int) brojevi[i];
		cijeliDio = brojevi[i] - decimalniDio;

			if (cijeliDio/100 < decimalniDio) {

				printf("%.2lf\n", brojevi[i]);

			}
	}


}