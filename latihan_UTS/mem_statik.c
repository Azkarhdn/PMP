/* 
Hitung total nilai -> total = stok*harga
tentukan barang dengan total nilai terbesar
hitung barang yang stoknya <10
tampilkan barang dengan total nilai >100000
OUTPUT
Barang dengan nilai terbesar: <nama> (<nilai>)
Jumlah barang hampir habis = X
Daftar barang dengan nilai > 100000:
*/
#include<stdio.h>
#include <string.h>

struct Barang{
    char kode [10];
    char nama [20];
    int stok;
    int harga;
};
int main (){
    int n;
    printf("Jumlah barang: ");
    scanf("%d", &n);
    struct Barang b[100];
    // input data
    for (int i=0;i<n;i++){
        printf("Data %d\n", i+1);
        scanf("%s %s %d %d", &b[i].kode, &b[i].nama, &b[i].stok, &b[i].harga);
    }
    //hitung total nilai
    int idx=0, count=0;
    for(int i=0; i<n; i++){
        int total = b[i].stok*b[i].harga;
        // cari max
        if(total>b[idx].stok*b[idx].harga){
            idx=i;
        }
        //barang mau habis
        if(b[i].stok<10){
            count++;
        }

    }
    printf("Barang dengan nilai terbesar: %s  Rp%d\n", b[idx].nama, b[idx].stok*b[idx].harga);
    printf("Jumlah barang hampir habis : %d\n", count);
    printf("Daftar barang dengan nilai > 100000: ");
    for(int i=0;i<n;i++){
        if(b[i].stok*b[i].harga>100000){
            printf("%s, ", b[i].nama);
        }
    }
    return 0;

}

