/* FILE OPERATION
membaca file transaksi.txt
format : kode_transaksi jumlah -> 1 (pemasukan), 2 (pengeluaran)
*/
#include<stdio.h>
#include <string.h>
int main(){
    FILE *fp, *out;
    fp = fopen("transaksi.txt", "r");
    if (fp==NULL){
        printf("File Kosong\n");
        return 0;
    }
    int kode, jumlah, pemasukan=0, pengeluaran=0;
    //baca file
    while(fscanf(fp,"%d %d", &kode, &jumlah) != EOF){
        if(kode==1){
            pemasukan +=jumlah;
        }
        else if (kode ==2){
            pengeluaran += jumlah;
        }
    }
    int saldo = pemasukan - pengeluaran;
    fclose(fp);
    out = fopen("laporan.txt", "w");
    if(out == NULL){
        printf("Gagal membuat file output\n");
        return 0;
    }
    char status[200];
    if (saldo>=50000){
        strcpy(status,"AMAN");
    } else {
        strcpy(status,"PERINGATAN");
    }
    fprintf(out, "Total Pemasukan Rp%d\n", pemasukan);
    fprintf(out, "Total Pengeluaran Rp%d\n", pengeluaran);
    fprintf(out, "Saldo Akhir Rp%d\n", saldo);
    fprintf(out, "Status = %s\n", status);
    fclose(out);
    return 0;
}