#include <stdio.h>
#include <string.h>

#define MAX 100
#define TARIF 5000

struct Mobil {
    char plat[20];
    char jenis[20];
    int jamMasuk;
    int menitMasuk;
};

// PROTOTYPE
void tambahMobil(struct Mobil parkir[], int *count, int kapasitas);
void keluarMobil(struct Mobil parkir[], int *count);
void tampil(struct Mobil parkir[], int count, int kapasitas);

// ================= MAIN =================
int main(){

    struct Mobil parkir[MAX];

    int kapasitas, count = 0, pilihan = 0;

    printf("Masukkan kapasitas parkir (max %d): ", MAX);
    scanf("%d",&kapasitas);
    getchar();

    if(kapasitas > MAX){
        printf("Kapasitas melebihi batas!\n");
        return 1;
    }

    while(pilihan != 4){

        printf("\n=== MENU PARKIR ===\n");
        printf("1. Mobil masuk\n");
        printf("2. Mobil keluar\n");
        printf("3. Tampilkan data\n");
        printf("4. Keluar program\n");
        printf("Pilih: ");
        scanf("%d",&pilihan);
        getchar();

        if(pilihan == 1){
            tambahMobil(parkir, &count, kapasitas);
        }
        else if(pilihan == 2){
            keluarMobil(parkir, &count);
        }
        else if(pilihan == 3){
            tampil(parkir, count, kapasitas);
        }
    }

    return 0;
}

// ================= TAMBAH MOBIL =================
void tambahMobil(struct Mobil parkir[], int *count, int kapasitas){

    if(*count == kapasitas){
        printf("Parkir penuh!\n");
        return;
    }

    printf("Plat: ");
    fgets(parkir[*count].plat,20,stdin);
    parkir[*count].plat[strcspn(parkir[*count].plat,"\n")] = 0;

    printf("Jenis: ");
    fgets(parkir[*count].jenis,20,stdin);
    parkir[*count].jenis[strcspn(parkir[*count].jenis,"\n")] = 0;

    printf("Jam masuk (0-23): ");
    scanf("%d",&parkir[*count].jamMasuk);

    printf("Menit masuk (0-59): ");
    scanf("%d",&parkir[*count].menitMasuk);
    getchar();

    (*count)++;

    printf("Mobil masuk berhasil!\n");
}

// ================= KELUAR MOBIL =================
void keluarMobil(struct Mobil parkir[], int *count){

    if(*count == 0){
        printf("Parkir kosong!\n");
        return;
    }

    char cari[20];
    printf("Masukkan plat keluar: ");
    fgets(cari,20,stdin);
    cari[strcspn(cari,"\n")] = 0;

    int found = -1;

    for(int i=0;i<*count;i++){
        if(strcmp(parkir[i].plat,cari) == 0){
            found = i;
            break;
        }
    }

    if(found == -1){
        printf("Mobil tidak ditemukan\n");
    } 
    else {

        int jamKeluar, menitKeluar;

        printf("Jam keluar (0-23): ");
        scanf("%d",&jamKeluar);

        printf("Menit keluar (0-59): ");
        scanf("%d",&menitKeluar);
        getchar();

        // KONVERSI KE MENIT
        int masuk = parkir[found].jamMasuk * 60 + parkir[found].menitMasuk;
        int keluar = jamKeluar * 60 + menitKeluar;

        // HITUNG DURASI
        int durasiMenit = (keluar - masuk + 1440) % 1440;

        // PEMBULATAN KE JAM
        int durasiJam = (durasiMenit + 59) / 60;

        int biaya = durasiJam * TARIF;

        printf("\n=== STRUK PARKIR ===\n");
        printf("Plat: %s\n", parkir[found].plat);
        printf("Durasi: %d menit (%d jam)\n", durasiMenit, durasiJam);
        printf("Total bayar: %d\n", biaya);

        // HAPUS DATA (SHIFT ARRAY)
        for(int i=found;i<*count-1;i++){
            parkir[i] = parkir[i+1];
        }

        (*count)--;

        printf("Mobil keluar berhasil!\n");
    }
}

// ================= TAMPIL DATA =================
void tampil(struct Mobil parkir[], int count, int kapasitas){

    printf("\n=== DATA PARKIR ===\n");
    printf("Terisi: %d / %d\n",count,kapasitas);

    for(int i=0;i<count;i++){
        printf("%d. %s (%s) - Masuk: %02d:%02d\n",
               i+1,
               parkir[i].plat,
               parkir[i].jenis,
               parkir[i].jamMasuk,
               parkir[i].menitMasuk);
    }
}