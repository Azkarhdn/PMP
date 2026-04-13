#include <stdio.h>
 
int main (){
    int row1,row2,col1,col2;
    printf("Masukkan jumlah baris matriks pertama: ");
    scanf("%d", &row1); 
    printf("Masukkan jumlah kolom matriks pertama: ");
    scanf("%d", &col1);
    printf("Masukkan jumlah baris matriks kedua: ");
    scanf("%d", &row2);
    printf("Masukkan jumlah kolom matriks kedua: ");
    scanf("%d", &col2);

    //cek syarat
    if (col1 != row2) {
        printf("Matriks tidak dapat dikalikan\n");
        return 0;
    }
    int A[10][10], B[10][10], C[10][10];

    //matriks A
    printf("Masukkan elemen matriks pertama:\n");
    for (int i=0; i<row1; i++) {
        for (int j=0; j<col1; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    //matriks B
    printf("Masukkan elemen matriks kedua:\n");
    for (int i=0; i<row2; i++) {
        for (int j=0; j<col2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    // perkalian matriks
    for (int i=0; i<row1; i++) {
        for (int j=0; j<col2; j++) {
            C[i][j] = 0;
            for (int k=0; k<col1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    // cetak hasil
    printf("Hasil perkalian matriks:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}