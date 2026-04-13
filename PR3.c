#include <stdio.h>

void hitungSinCos()
{
    double x;
    int n;
    printf("Masukkan nilai x (dalam radian): ");
    scanf("%lf", &x);
    printf("Masukkan jumlah suku deret: ");
    scanf("%d", &n);
    double sin = 0;
    double cos = 0;
    int i, j;
    /* menghitung sin(x) */
    for(i = 0; i < n; i++) {
        int pangkat = 2*i+1;
        double atas =1;
        for(j=0; j<pangkat; j++) {
            atas = atas * x;
        }
        double bawah = 1;
        for(j=1; j<=pangkat; j++) {
            bawah = bawah * j;
        }
        double suku = atas / bawah;
        if(i%2 == 0) {
            sin = sin + suku;
        } else {
            sin = sin - suku;
        }
    }

    /* menghitung cos(x) */
    for(i = 0; i < n; i++) {
        int pangkat = 2*i;
        double atas = 1;
        for(j = 0; j < pangkat; j++) {
            atas = atas * x;
        }
        double bawah = 1;
        for(j = 1; j <= pangkat; j++) {
            bawah = bawah * j;
        }
        double suku = atas / bawah;
        if(i % 2 == 0) {
            cos = cos + suku;
        }
        else {
            cos = cos - suku;
        }
    }
    printf("sin(%lf) = %lf\n", x, sin);
    printf("cos(%lf) = %lf\n", x, cos);
}

int main() {
    hitungSinCos();
    return 0;
}