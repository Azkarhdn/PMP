/*
TP 1 - Bagian 1
Nama : Muhammad Azka Rahadian
NIM : 13224036
*/
#include <stdio.h>
int main () {
    int n;
    printf ("Masukkan jumlah bilangan: ");
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++){
        printf("Masukkan bilangan ke-%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    //bubble sort -> swap kanan
    int temp;
    for (int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                //swap
                temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }        
    }
    //print
    printf("Bilangan setelah diurutkan: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

// cd Praktikum_PMP\Modul_1
/*
gcc TP_1.c -o TP_1
.\TP_1
*/