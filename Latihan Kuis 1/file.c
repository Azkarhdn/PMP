/* NOTES PRIBADI
FILE *fp = fopen("nama_file.txt", "mode"); -> buka file dengan mode tertentu
fclose(fp); -> tutup file
fprintf(fp, "format", var); -> tulis ke file dengan format tertentu
fscanf(fp, "format", &var); -> baca dari file dengan format tertentu
fgets(var, size, fp); -> baca satu baris dari file
fgetc(fp); -> baca satu karakter dari file
fputc(char, fp); -> tulis satu karakter ke file
fputs(string, fp); -> tulis string ke file
while(fgets(teks,100,fp) != NULL) -> baca file baris per baris sampai akhir

MENULIS banyak data
#include <stdio.h>
int main(){
    FILE *fp;
    char nama[50];

    fp = fopen("nama.txt","w");

    for(int i=0;i<3;i++){
        printf("Masukkan nama: ");
        fgets(nama,50,stdin);
        fprintf(fp,"%s",nama);
    }
    fclose(fp);
}

MEMBACA data dari FILE
#include <stdio.h>
int main(){
    FILE *fp;
    char nama[50];

    fp = fopen("nama.txt","r");

    while(fgets(nama,50,fp) != NULL){
        printf("%s",nama);
    }
    fclose(fp);
}
*/

/* NOTES PRIBADI
FILE *fp = fopen("nama_file.txt", "mode"); -> buka file dengan mode tertentu
fclose(fp); -> tutup file
fprintf(fp, "format", var); -> tulis ke file dengan format tertentu
fscanf(fp, "format", &var); -> baca dari file dengan format tertentu
fgets(var, size, fp); -> baca satu baris dari file
fgetc(fp); -> baca satu karakter dari file
fputc(char, fp); -> tulis satu karakter ke file
fputs(string, fp); -> tulis string ke file
while(fgets(teks,100,fp) != NULL) -> baca file baris per baris sampai akhir

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