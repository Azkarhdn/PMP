/* SIMULATOR REAKTOR SHIFT MALAM
input : E L R M diikuti op dan x
*/
#include <stdio.h>
int main (){
    int E,L,R,M,op,x;
    scanf("%d %d %d %d", &E, &L, &R, &M);
    for (int i=0; i<M; i++){
        scanf("%d %d", &op, &x);
        if(op==1){
            E+=x;
        }
        else if (op==2){
            E-=x;
        }
        else if (op==3){
            E *=x;
        }
        else if (op==4){
            if(E>x){
                E=x;
            }
        }
        if(E<L||E>R){
            printf("GAGAL %d %d", i+1,E);
            break;
        }
    }
    printf("AMAN %d", E);
    return 0;
}