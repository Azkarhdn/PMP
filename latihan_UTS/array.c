/*NILAI TERTINGGI KEDUA
menentukan nilai tertinggi kedua 
input : N dan arr[i]
output : Tertinggi Kedua = ..
*/
#include <stdio.h>
int main (){
    int n, arr[n], max1=-9999, max2=-9999;
    printf("Jumlah Siswa : ");
    scanf("%d", &n);
    for (int i=0; i<n;i++){
        printf("Masukkan Nilai Siswa ke-%d: ", i+1);
        scanf("%d", &arr[i]);
        if(arr[i]>max1){
            max2 = max1;
            max1= arr[i];
        }
        else if (arr[i]>max2 && arr[i]!=max1){
            max2 = arr[i];
        }
    }
    if (max2==-9999){
        printf("TIDAK ADA");
    }else {
    printf("Nilai Terbesar Kedua : %d", max2);;
    }
    return 0;
}