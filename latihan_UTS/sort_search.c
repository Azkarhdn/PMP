/*PROGRAM DATA NILAI
Menerima jumlah mahasiswa N
Menerima N nilai mahasiswa
sort kecil->besar (bubble sort)
menerima nilai x yang ingin dicari
mencari nilai tsb ada dalam array apa ngga
*/
#include <stdio.h>
int main (){
    int n, x;
    printf("Jumlah Mahasiswa : ");
    scanf("%d", &n);
    int arr[n];
    printf("isi array : ");
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf ("cari nilai : ");
    scanf("%d", &x);
    // bubble sort
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    printf ("hasil sorting : ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // linear search
    int found =0;
    for (int i=0; i<n; i++){
        if (arr[i]==x){
            found=1;
            printf("Nilai ditemukan di index ke-%d", i);
            break;
        }
    }
    if (found==0){
        printf("Nilai tidak ditemukan\n");
    }
    return 0;
}