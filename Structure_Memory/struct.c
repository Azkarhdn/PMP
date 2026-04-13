#include <stdio.h>
#include <string.h>

struct Mobil {
    char plat[20];
    char jenis[20];
    int jam;
    int tarif;
    int total;
};

int main(){

    struct Mobil parkir[3];

    // INPUT
    for(int i=0;i<3;i++){

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

        // PROSES
        parkir[i].total = parkir[i].jam * parkir[i].tarif;
    }

    // OUTPUT
    printf("\n=== DATA PARKIR ===\n");

    for(int i=0;i<3;i++){
        printf("\nMobil %d\n",i+1);
        printf("Plat: %s\n",parkir[i].plat);
        printf("Jenis: %s\n",parkir[i].jenis);
        printf("Total bayar: %d\n",parkir[i].total);
    }

    return 0;
}