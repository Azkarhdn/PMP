// Muhammad Azka Rahadian / 13224036

#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define INITIAL 4000
#define MobilPerJam 3000
#define TrukPerJam 5000

struct Mobil {
    char plat [10];
    char jenis [10];
    int jam, menit ;
};
void inputMobil(struct Mobil parkir[], int *count, int kapasitas){
    if(*count == kapasitas){
        printf("Parkir Penuh\n");
        return;
    }
    // input data 
    printf("Plat Nomor : ");
    fgets (parkir[*count].plat, 10, stdin);
    parkir[*count].plat[strcspn(parkir[*count].plat,"\n")] = 0;
    printf("Jenis Mobil : ");
    fgets (parkir[*count].jenis, 10, stdin);
    parkir[*count].jenis[strcspn(parkir[*count].jenis,"\n")] = 0;
    printf("Jam Masuk (0-23) : ");
    scanf("%d", &parkir[*count].jam);
    printf("Menit Masuk (0-59) : ");
    scanf("%d", &parkir[*count].menit);
    getchar();
    (*count)++;
    printf("Mobil masuk\n");
}

void MobilKeluar (struct Mobil parkir[], int *count){
    if (*count==0){
        printf("Parkir kosong\n");
        return;
    } else {
        char search[10];
        printf("Masukkan plat : ");
        fgets(search, 10, stdin);
        search[strcspn(search,"\n")] = 0;

        //proses cari plat
        int found = -1;
        for (int i=0; i<*count; i++){
            if (strcmp(parkir[i].plat, search)==0){
                found = i;
                break;
            }
        }
        // gaketemu
        if (found==-1){
            printf("Mobil tidak ditemukan\n");
            return;
        } else {
            int jamOut, minOut;
            printf("Masukkan jam keluar (0-23) : ");
            scanf("%d", &jamOut);
            printf("Masukkan menit keluar (0-59) : ");
            scanf("%d", &minOut);
            getchar();

            //convert ke menit semua
            int masuk = parkir[found].jam*60 + parkir[found].menit;
            int keluar = jamOut*60 + minOut;

            //hitung lama parkir
            int lamaMenit = (keluar-masuk +1440) %1440; //biar ketauan kalau lebih dari sehari
            int lamaJam = (lamaMenit)/60; //pembulatan atas
            int sisaMenit = lamaMenit % 60;

            int biaya;
            //hitung biaya 
            if (strcmp(parkir[found].jenis,"truk")==0){
                biaya = INITIAL + lamaJam*TrukPerJam;
            }
            else if (strcmp(parkir[found].jenis, "mobil")== 0){
                biaya = INITIAL + lamaJam*MobilPerJam;
            } else {
                printf("Tipe mobil tidak ditemukan\n");
                return;
            }

            // bikin struk parkir
            printf("\n==== DETAIL PARKIR ====\n");
            printf("Plat : %s\n", parkir[found].plat);
            printf("Lama parkir : %d jam %d menit\n", lamaJam, sisaMenit );
            printf("Total biaya parkir : %d\n", biaya);

            //shift memory
            for (int i=found; i<*count-1; i++){
                parkir[i] = parkir[i+1];
            }
            (*count)--;
            printf("Mobil keluar\n");
        }

    }
}
void DataParkir(int count, int kapasitas){
    printf("\n==== DATA PARKIR ====\n");
    printf("Parkir terisi : %d / %d\n", count,kapasitas);
}
void DataKendaraan(struct Mobil parkir[], int count){
    printf("\n==== DATA KENDARAAN ====\n");
    if (count==0){
        printf("Parkir kosong\n");
        return;
    } else {
        for (int i=0; i<count; i++){
        printf("%d. %s, %s, -- Masuk : %02d:%02d\n", i+1, parkir[i].plat, parkir[i].jenis, parkir[i].jam, parkir[i].menit);
        }
    }
    
}

int main (){
    int count =0, pilihan =0, kapasitas = CAPACITY;
    struct Mobil parkir[CAPACITY];

    while (pilihan!=5){
        printf("\nPilih Menu Parkir\n");
        printf("1. Input Mobil\n");
        printf("2. Mobil Keluar\n");
        printf("3. Data Kapasitas Parkiran\n");
        printf("4. Data Kendaraan Parkir\n");
        printf("5. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan==1){
            inputMobil(parkir, &count, kapasitas);
        }
        else if (pilihan==2){
            MobilKeluar(parkir, &count);
        }
        else if (pilihan==3){
            DataParkir(count, kapasitas);
        }
        else if (pilihan==4){
            DataKendaraan(parkir, count);
        }
    }
    return 0; 

}

/* NOTES PRIBADI
fgets (nama var, size, stdin) -> baca satu baris full
scanf ("%s", nama var) -> baca satu kata, berhenti di spasi
strcmp (var1, var2) -> compare string, 0 jika sama
strlen (nama var) -> panjang string
strcpy (var1, var2) -> copy string var2 ke var1
strcat (var1, var2) -> var 1 tujuan, var 2 tambahan
sscanf (nama var, "%s", nama var) -> baca satu kata, berhenti di spasi
strtok (nama var, " ") -> baca satu kata, berhenti di spasi, simpan sisa string untuk dipanggil lagi
strchr (nama var, 'a') -> cari karakter 'a' terakhir dalam string
strstr (nama var, "abc") -> cari substring "abc" terakhir dalam string
var[strcspn(var,"\n")] = 0; -> hapus newline dari fgets
*/