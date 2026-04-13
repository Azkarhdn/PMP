// SOAL 1 - Gerbang Koloni Bertingkat
// input : izin, suhu, radiasi, jam
/* izin -> 1-3; suhu dalam 0.1C -> 371 jadi 37.1; radiasi bilbul non negatif; jam 0-23
*/
#include <stdio.h>
int main (){
    int izin, suhu, radiasi, jam;
    scanf("%d %d %d %d", &izin, &suhu, &radiasi, &jam);
    if(radiasi<=6 && radiasi>=0){
        if (suhu>=390){
            printf("KARANTINA");
        }else {
            if(izin==1){
                if(jam<6 || jam>20){
                    printf("TOLAK");
                }else {
                    printf("MASUK");
                }
            }
            else if(izin==2){
                if (radiasi<=2 && jam>=8 && jam <=18){
                    printf("MASUK");
                }else {
                    printf("PEMERIKSAAN");
                }
            }
            else if (izin ==3){
                if (radiasi==0 && suhu<380){
                    printf("MASUK");
                }
                else {
                    printf("TOLAK");
                }
            } else{
                printf("TOLAK");
            }
        }
    } else {
        printf("TOLAK");
    }
    return 0;

    //printf("hasil : %d %d %d %d", izin, suhu, radiasi, jam);

}