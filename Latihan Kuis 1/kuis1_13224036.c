/* 12/03/2026 
Nama : Muhammad Azka Rahadian
Kelas : 13224036
*/
#include <stdio.h>
/* SOAL
Menghitung volume benda putar yang terbentuk ketika grafik f(x) = ax^2 + bx + c diputar 360 derajat terhadap sumbu x dengan interval [xa, xb].
rumus V = pi * integral dari xa ke xb (f(x))^2 dx

format input.txt 
a b c 
xa xb

program: 
1. Membaca nilai a, b, c, xa, xb dari file input.txt
2. Menghitung integral mendapatkan V berdasarkan nilai input
3. Menampilkan hasil V ke layar
*/
#define PI 3.14
int main (){
    float V;
    FILE *fp;
    fp = fopen("input.txt","r");
    if (fp==NULL) {
        printf("file tidak valid\n");
        return 1;
    } else{
        //fscanf(fp, "format", &var); -> baca dari file dengan format tertentu
        float a,b,c,xa,xb;
        fscanf(fp,"%f%f%f", &a,&b, &c);
        fscanf(fp,"%f%f", &xa,&xb);
        fclose(fp);
        //udah kebaca harusnya
        //TES DULU
        //printf("a: %f, b: %f, c: %f, xa: %f, xb: %f\n", a,b,c,xa,xb);
        
        //NO.2
        V = PI*(((a*a*xb*xb*xb*xb*xb)/5 + (2*a*b*xb*xb*xb*xb)/4 + (((2*a*c+b*b)/3)*xb*xb*xb) + ((2*b*c)/2)*xb*xb + (c*c*xb)) - ((a*a*xa*xa*xa*xa*xa)/5 + (2*a*b*xa*xa*xa*xa)/4 + (((2*a*c+b*b)/3)*xa*xa*xa) + ((2*b*c)/2)*xa*xa + (c*c*xa)) );

    }
    // NO.3
    printf("V = %f", V);
    return 0;
}

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