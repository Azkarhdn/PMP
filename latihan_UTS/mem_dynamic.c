/* 
jumlah pembeli tidak diketahui -> dinamis
menerima n pembeli
alokasi mem untuk data pembeli
hitung total pembayaran setiap beli -> total = jml * harga
tent pembayaran terbesar
hitung total seluruh pemasukan
tampilkan semua pembeli yang membeli lebih dari rata2 jumlah tiket
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Tiket{
    char nama [20];
    int jumlah;
    int harga;
};
int main(){
    int n;
    scanf("%d", &n);
    // input data
    struct Tiket *t=(struct Tiket*)malloc(n *sizeof(struct Tiket));
    for(int i=0; i<n;i++){
        scanf("%s %d %d", &t[i].nama, &t[i].jumlah, &t[i].harga);
    }
    int idx=0, tiket_tot=0, all=0;
    //hitung total
    for(int i=0;i<n;i++){
        int total = t[i].jumlah*t[i].harga;
        if(total>t[idx].jumlah*t[idx].harga){
            idx = i;
        }
        all += total;
        tiket_tot += t[i].jumlah;
    }
    float avg_tiket = tiket_tot/n;
    printf("Pembeli Terbesar : %s Rp%d\n", t[idx].nama, t[idx].jumlah*t[idx].harga);
    printf("Total pemasukan = %d\n", all);
    printf("Pembeli diatas rata-rata : ");
    for(int i=0; i<n;i++){
        if(t[i].jumlah>avg_tiket){
            printf("%s, ", t[i].nama);
        }
    }
    free(t);
    return 0;

}