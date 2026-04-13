#include <stdio.h>
#define PI 3.14159

void hitungluas(float r) {
    float luas = PI*r*r;
    printf("Luas lingkaran adalah %2f\n", luas);
}

int main(){
    float r;
    printf("Masukkan jari-jari : ");
    scanf("%f", &r);
    hitungluas(r);
    return 0;
}