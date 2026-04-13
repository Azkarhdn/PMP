/* PROGRAM MENGELOLA NILAI
menerima nilai
input berhenti jika nilai -1
nilai disimpan di array
hitung rata2 nilai awal
perbaikan nilai
    if nilai < 60 (+10)
    if nilai >= 60 (+5)
cari rata2 baru dan jumlah mahasiswa yang lulus
*/
#include <stdio.h>
#define FLAG -1
void perbaikan(int *x){
    if(*x<60){
        *x+=10;
    }else if (*x>=60){
        *x+=5;
    }
}
int main (){
    int arr [100], n=0, x;
    scanf("%d", &x);
    while (x!=FLAG){
        arr[n]=x;
        n++;
        scanf("%d", &x);
    }
    //hitung awal
    int sum =0;
    float avg_awal;
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    avg_awal = sum/n;
    //ke fungsi baru
    for(int i=0; i<n; i++){
        perbaikan(&arr[i]);
    }
    int sum_tot =0,lulus=0;
    float avg_last;
    for(int i=0; i<n; i++){
        sum_tot += arr[i];
        if(arr[i]>=60){
            lulus++;
        }
    }
    avg_last = sum_tot/n;
    printf("Rata-Rata Awal : %.2f\n", avg_awal);
    printf("Rata-Rata Akhir : %.2f\n", avg_last);
    printf("Jumlah lulus : %d", lulus);
    return 0;
}