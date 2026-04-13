/* Menerima jumlah peserta n dengan nama
- hitung peserta yang memiliki awal A atau a
- cari nama dengan panjang karakter terpanjang
- cek nama peserta
*/
#include <stdio.h>
#include <string.h>
int main (){
    int n;
    char nama [10][10];
    char cari [10];

    printf("Jumlah Peserta : ");
    scanf("%d", &n);
    //input nama
    for (int i=0; i<n; i++){
        printf("Nama ke-%d : ",i+1);
        scanf("%s", &nama[i]);
    }
    //input cari
    printf("Nama dicari : ");
    scanf("%s", &cari);
    // hitung awalan A
    int count =0;
    for (int i=0;i<n;i++){
        if(nama[i][0]=='A' || nama[i][0]=='a'){
            count++;
        }
    }
    // nama terpanjang
    int idx=0;
    for(int i=1;i<n;i++){
        if(strlen(nama[i])>strlen(nama[idx])){
            idx = i;
        }
    }
    //cari nama
    int found =0;
    for(int i=0;i<n;i++){
        if(strcmp(nama[i],cari)==0){
            found =1;
            break;
        }
    }
    printf("Jumlah nama diawali A : %d\n", count);
    printf("Nama terpanjang : %s\n", nama[idx]);
    if(found==1){
        printf("Status Pencarian = DITEMUKAN\n");
    }else {
        printf("Status Pencarian = TIDAK\n");
    }
    return 0;
}