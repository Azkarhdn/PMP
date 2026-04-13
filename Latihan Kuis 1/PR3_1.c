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

#include <stdio.h>
#include <string.h>

int main() {
    char nama[3][50];
    char namaDepan[3][50];
    char namaBelakang[3][50];
    char namaFormal[3][50]; // namaDepan, namaBelakang
    char *temp;
    char swap[50];
    for (int i = 0; i < 3; i++) {
        printf("Masukkan nama: ");
        fgets(nama[i], 50, stdin);
        nama[i][strcspn(nama[i], "\n")] = 0; // hapus newline
    }
    // pisahin dulu
    for (int j=0; j<3; j++){
        temp = strtok(nama[j]," ");
        strcpy(namaDepan[j], temp);
        temp = strtok(NULL," ");
        strcpy(namaBelakang[j], temp);
        // gabungin pake koma
        strcpy(namaFormal[j], namaBelakang[j]);
        strcat(namaFormal[j], ", ");
        strcat(namaFormal[j], namaDepan[j]);
    }
    // sort nama
    for (int i=0; i<3; i++){
        for (int j=i+1; j<3; j++){
            if (strcmp(namaFormal[i], namaFormal[j]) > 0){
                strcpy(swap, namaFormal[i]);
                strcpy(namaFormal[i], namaFormal[j]);
                strcpy(namaFormal[j], swap);
            }
        }
    }
    printf("Nama sesuai urutan : \n");
    for(int i=0; i<3; i++){
        printf("%s dengan panjang %d\n", namaFormal[i], (int)strlen(namaFormal[i]));
    }

    //Latihan 2
    FILE *fp;
    fp = fopen("anggota.txt", "w");
    if (fp == NULL) {
        printf("Error membuka file\n");
        return 1;
    } else {
        printf("File berhasil dibuka\n");
        for (int i=0; i<3; i++){
        fprintf(fp, "%s\n", namaFormal[i]);
        }
        fclose(fp);
        fp = fopen("anggota.txt", "r");
        char isi[50];
        printf("Isi file anggota.txt : \n");
        while (fgets(isi, 50, fp) != NULL){
            printf("%s", isi);
        }
        fclose(fp);
    }
}