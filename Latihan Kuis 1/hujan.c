#include <stdio.h>
#define STOP -99

void decide(float prob) {
    if (prob > 60) {
        printf("Pakai mobil\n");
    } else if (prob >= 30 && prob <= 60) {
        printf("Pakai motor\n");
    } else if (prob < 30 && prob >= 0) {
        printf("Jalan kaki\n");
    }
}
void decidebensin (float jarak, float bensin, float konsumsi){
    float range = bensin / konsumsi;
    if (range >= jarak){
        printf("Bentar, isi bensin dulu\n");
    } else {
        printf("silahkan berangkat\n");
    }
}

int main (){
    float prob;
    printf("probabilitas hujan (persen) : ");
    scanf("%f", &prob);
    while (prob != STOP) {
        if (prob < 0 || prob > 100) {
            printf("Probabilitas tidak valid\n");
        } else {
            decide(prob);
            if (prob>60){
                float jarak, bensin, konsumsi;
                printf("Masukkan jarak dari rumah ke kampus (km): ");
                scanf("%f", &jarak);
                printf("Masukkan bensin tersedia (liter): ");
                scanf("%f", &bensin);
                printf("Masukkan konsumsi bensin (km/liter): ");
                scanf("%f", &konsumsi);
                decidebensin(jarak, bensin, konsumsi);
            }
        }
        printf("probabilitas hujan (persen) : ");
        scanf("%f", &prob);
    }
}