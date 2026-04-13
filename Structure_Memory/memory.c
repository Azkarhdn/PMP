#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mobil {
    char plat[20];
    char jenis[20];
    int jam;
    int tarif;
    int total;
};

int main(){

    int n;
    printf("Masukkan jumlah mobil: ");
    scanf("%d",&n);
    getchar();

    // malloc untuk n mobil
    struct Mobil *parkir;
    parkir = (struct Mobil*) malloc(n * sizeof(struct Mobil));

    if(parkir == NULL){
        printf("Memory gagal dialokasi\n");
        return 1;
    }

    // INPUT DATA
    for(int i=0;i<n;i++){

        printf("\nMobil ke-%d\n",i+1);

        printf("Plat: ");
        fgets(parkir[i].plat,20,stdin);
        parkir[i].plat[strcspn(parkir[i].plat,"\n")] = 0;

        printf("Jenis: ");
        fgets(parkir[i].jenis,20,stdin);
        parkir[i].jenis[strcspn(parkir[i].jenis,"\n")] = 0;

        printf("Lama parkir (jam): ");
        scanf("%d",&parkir[i].jam);

        printf("Tarif per jam: ");
        scanf("%d",&parkir[i].tarif);
        getchar();

        // HITUNG TOTAL
        parkir[i].total = parkir[i].jam * parkir[i].tarif;
    }

    // OUTPUT DATA
    printf("\n=== DATA PARKIR ===\n");

    for(int i=0;i<n;i++){
        printf("\nMobil %d\n",i+1);
        printf("Plat: %s\n",parkir[i].plat);
        printf("Jenis: %s\n",parkir[i].jenis);
        printf("Total bayar: %d\n",parkir[i].total);
    }

    // CARI BIAYA TERBESAR
    int max = parkir[0].total;
    int idx = 0;

    for(int i=1;i<n;i++){
        if(parkir[i].total > max){
            max = parkir[i].total;
            idx = i;
        }
    }

    printf("\nMobil dengan biaya terbesar:\n");
    printf("%s (%d)\n", parkir[idx].plat, max);

    // FREE MEMORY
    free(parkir);

    return 0;
}