#include <stdio.h>
// program menghitung akar
int main (){
    float a, b, c, d, x1, x2;
    printf("Masukkan nilai a: ");
    scanf("%f", &a);
    printf("Masukkan nilai b: ");
    scanf("%f", &b);
    printf("Masukkan nilai c: ");
    scanf("%f", &c);

    d = b*b - 4*a*c;

    if (d < 0){
        printf("Akar imajiner\n");
    } else {
        x1 = (-b + sqrt(d)) / (2*a);
        x2 = (-b - sqrt(d)) / (2*a);
        printf("Akar 1: %.2f\n", x1);
        printf("Akar 2: %.2f\n", x2);
    }
    return 0;
}