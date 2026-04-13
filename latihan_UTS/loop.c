/* PROGRAM TABUNGAN
input : traget dan tabungan per hari
output : total tabungan akhir dan jumlah hari
jika tabungan harian >= 50 maka mendapat bonus 10*/
#define FLAG -99
#include<stdio.h>
int main (){
    int target, nominal;
    printf("Target tabungan: ");
    scanf("%d", &target);
    while(target!=FLAG){
        int total=0, hari=0;
        while(total<target){
            scanf("%d", &nominal);
            if(nominal>=50){
                total += nominal+10;
            }else{
                total +=nominal;
            }
            hari ++;
        }
        printf("Total Tabungan = %d\n", total);
        printf("Jumlah Hari = %d\n", hari);
        printf("\nTarget tabungan: ");
        scanf("%d", &target);
    }
    printf("SELESAI");
    return 0;
}