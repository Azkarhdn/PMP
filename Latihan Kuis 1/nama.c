/* NOTES PRIBADI
fgets (nama var, size, stdin) -> baca satu baris full
scanf ("%s", nama var) -> baca satu kata, berhenti di spasi
strcmp (var1, var2) -> compare string, 0 jika sama
strlen (nama var) -> panjang string
strcpy (var1, var2) -> copy string var2 ke var1
strcat (var1, var2) -> var 1 tujuan, var 2 tambahan
sscanf (nama var, "%s", nama var) -> baca satu kata, berhenti di spasi
strtok (nama var, " ") -> baca satu kata, berhenti di spasi, simpan sisa string untuk dipanggil lagi
strchr (nama var, 'a') -> cari karakter 'a' terakhir dalam string
strstr (nama var, "abc") -> cari substring "abc" terakhir dalam string
var[strcspn(var,"\n")] = 0; -> hapus newline dari fgets
*/

#include <stdio.h>
#include <string.h>

int main (){
    char nama[3][50];
    char formal[3][50];
    char *temp;
    for (int i=0; i<3; i++){
        printf("Masukkan nama : ");
        fgets(nama[i], 50, stdin);
        nama[i][strcspn(nama[i], "\n")] = 0;
    }
    for (int j=0; j<3; j++){
        temp = strtok(nama[j]," ");
        while (temp != NULL){
            printf("%s", temp);
            temp = strtok(NULL," ");
            if (temp!=NULL){
                printf(", ");
            }
        }
        printf("\n");
    }
}
