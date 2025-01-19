/*1.
Napisati program koji definira strukturu za zapis podataka o kompleksnim brojevima:
realni i imaginarni dio (float), unosi podatke za dva kompleksna broja i u posebnim
funkcijama računa njihov zbroj, razliku, umnožak i količnik (sve funkcije imaju dva
kompleksna broja kao ulazne parametre i vraćaju kompleksni broj koji predstavlja
rezultat računske operacije). Svi rezultati se ispisuju u glavnom programu.
*/

#include <stdio.h>
struct KompleksniBroj
{
    float realni;
    float imaginarni;
};

struct KompleksniBroj zbroj(struct KompleksniBroj br1, struct KompleksniBroj br2)
{
    struct KompleksniBroj rezultat;
    rezultat.realni = br1.realni + br2.realni;
    rezultat.imaginarni = br1.imaginarni + br2.imaginarni;
    return rezultat;
};

struct KompleksniBroj razlika(struct KompleksniBroj br1, struct KompleksniBroj br2)
{
    struct KompleksniBroj rezultat;
    rezultat.realni = br1.realni - br2.realni;
    rezultat.imaginarni = br1.imaginarni - br2.imaginarni;
    return rezultat;
};
// (a + bi)(c + di) == ac + bci + adi -bd
struct KompleksniBroj umnozak(struct KompleksniBroj br1, struct KompleksniBroj br2)
{
    struct KompleksniBroj rezultat;
    rezultat.realni = br1.realni * br2.realni - br1.imaginarni * br2.imaginarni;
    rezultat.imaginarni = br1.imaginarni * br2.realni + br1.realni * br2.imaginarni;
    return rezultat;
}
//(a+bi)(c-di) = ac + bci - adi + bd
struct KompleksniBroj kolicnik(struct KompleksniBroj br1, struct KompleksniBroj br2)
{
    struct KompleksniBroj rezultat;
    float nazivnik = br2.realni * br2.realni + br2.imaginarni * br2.imaginarni;
    rezultat.realni = (br1.realni * br2.realni + br1.imaginarni * br2.imaginarni) / nazivnik;
    rezultat.imaginarni = (br1.imaginarni * br2.realni - br1.realni * br2.imaginarni) / nazivnik;
    return rezultat;
};

int main()
{
    struct KompleksniBroj broj1, broj2;

    printf("Unesite realni dio prvog kompleksnog broja: ");
    scanf("%f", &broj1.realni);
    printf("Unesite imaginarni dio prvog kompleksnog broja: ");
    scanf("%f", &broj1.imaginarni);

    printf("Unesite realni dio drugog kompleksnog broja: ");
    scanf("%f", &broj2.realni);
    printf("Unesite imaginarni dio drugog kompleksnog broja: ");
    scanf("%f", &broj2.imaginarni);

    struct KompleksniBroj rez_zbroj = zbroj(broj1, broj2);
    printf("Zbroj: %.2f + %.2fi\n", rez_zbroj.realni, rez_zbroj.imaginarni);

    struct KompleksniBroj rez_razlika = razlika(broj1, broj2);
    printf("Razlika: %.2f + %.2fi\n", rez_razlika.realni, rez_razlika.imaginarni);

    struct KompleksniBroj rez_umnozak = umnozak(broj1, broj2);
    printf("Umnozak: %.2f + %.2fi\n", rez_umnozak.realni, rez_umnozak.imaginarni);

    struct KompleksniBroj rez_kolicnik = kolicnik(broj1, broj2);
    printf("Kolicnik: %.2f + %.2fi\n", rez_kolicnik.realni, rez_kolicnik.imaginarni);
    return 0;
}
