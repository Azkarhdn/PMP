// Muhammad Azka Rahadian
// 13224036
// Tugas 2 - Latihan 1

#include <stdio.h>
#define STOP -99
// prob hujan > 60% maka pakai mobil
// Jika prob hujan 30%-60% maka pakai motor
// Jika <30% jalan kaki
int main () {
    int prob;
    while (1) {
        printf("Masukkan probabilitas hujan (dalam persen) atau %d untuk selesai: ", STOP);
        scanf("%d", &prob);
        if (prob == STOP) {
            printf("Program dihentihhkan\n");
            break;
        }
        if (prob < 0 || prob > 100) {
            printf("Probabilitas tidak valid\n");
            continue;
        }
        if (prob > 60) {
            printf("Pakai mobil\n");
            // cek bensin cukup atau tidak
            // Data : jarak dari rumah ke kampus dan jarak yang mampu ditempuh
            // Jarak tempuh (km) = bensin tersedia (liter) * konsumsi bensin (km/liter)
            float jarak, bensin, konsumsi, tempuh;
            printf("Masukkan jarak dari rumah ke kampus (km): ");
            scanf("%f", &jarak);
            printf("Masukkan bensin tersedia (liter): ");
            scanf("%f", &bensin);
            printf("Masukkan konsumsi bensin (km/liter): ");
            scanf("%f", &konsumsi);
            tempuh = bensin * konsumsi;
            if (tempuh >= jarak){
                printf("Silakan berangkat\n");
                // Bagian 1C
                float dist_done, dist_rest, shortcut_rest, shortcut, v, t, cons_trfc;
                float fuel_trfc, fuel_sc, sisa_bensin;
                printf("Masukkan kecepatan (km/menit): ");
                scanf("%f", &v);
                printf("Masukkan waktu tempuh (menit): ");
                scanf("%f", &t);
                dist_done = v * t ;
                shortcut = jarak * 1.2; // jarak pintas 20% lebih jauh
                dist_rest = jarak - dist_done;
                shortcut_rest = shortcut - dist_done;
                cons_trfc = konsumsi * 0.8; // bensin lebih boros
                fuel_trfc = dist_rest / cons_trfc; //bensin dibutuhkan
                fuel_sc = shortcut_rest / konsumsi; // bensin dibutuhkan
                sisa_bensin = bensin - (dist_done / konsumsi); // yang sudah dipakai
                if (dist_done >= jarak) {
                    printf("Sudah sampai\n");
                } else {
                    if (fuel_sc <= sisa_bensin && fuel_trfc <= sisa_bensin) {
                        if (fuel_sc < fuel_trfc) {
                            printf("Lebih hemat bensin lewat jalan pintas\n");
                        } else {
                            printf("Lebih hemat bensin lewat jalan biasa\n");
                        }
                    } else if (fuel_sc < sisa_bensin) {
                        printf("Hanya jalan pintas yang cukup bensin\n");
                    } else if (fuel_trfc < sisa_bensin) {
                        printf("Hanya jalan biasa yang cukup bensin\n");
                    } else {
                        printf("Keduanya tidak cukup bensin, isi ulang dulu\n");
                    }
                }
            } else {
                printf("Bentar, isi bensin dulu\n");
            }
        } else if (prob >= 30) {
            printf("Pakai motor\n");
        } else {
            printf("Jalan kaki\n");
        }
    }
    return 0;
}

/* TEST CASE 
== hemat biasa ==
prob = 80
jarak = 20
bensin = 5
konsumsi = 10
v = 0.5
t = 10

== hemat pintas ==
prob = 80
jarak = 18
bensin = 5
konsumsi = 10
v = 0.5
t = 6

== sudah sampai ==
prob = 80
jarak = 15
bensin = 5
konsumsi = 10
v = 0.8
t = 20

== gacukup bensin ==
prob = 80
jarak = 18
bensin = 1
konsumsi = 10
v = 1
t = 10
*/