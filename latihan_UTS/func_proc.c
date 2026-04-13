/*ANALISIS NILAI MAHASISWA
input N jumlah mahasiswa dan nilainya
cari rata2, jumlah lulus, dan nilai maks
*/
#include <stdio.h>
float cariavg(int arr[], int n){
    int sum =0;
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    float avg = sum/n;
    return avg;
}
void statistik(int arr[], int n, int *lulus, int *maks){
    *lulus =0;
    *maks=arr[0];
    for (int i=0; i<n; i++){
        if(arr[i]>=60){
            (*lulus) ++;
        }
        if(arr[i]>*maks){
            *maks = arr[i];
        }
    }
}

int main (){
    int n,x;
    printf ("Jumlah Mahasiswa : ");
    scanf("%d", &n);
    int arr[n];
    printf("Nilai Mahasiswa : ");
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    float avg = cariavg(arr,n);
    int lulus, maks;
    statistik(arr,n,&lulus, &maks);
    printf("Nilai rata-rata : %.2f\n", avg);
    printf("Jumlah lulus : %d\n", lulus);
    printf("Nilai maks : %d\n", maks);
    return 0;
    //ini mau coba test ke git
}