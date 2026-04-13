/*pointer menukar 2 bilangan agar berurutan
*/
#include <stdio.h>
void swap(int *a, int*b){
    int temp;
    if(*a>*b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main (){
    int x,y;
    printf ("Bilangan 1 : ");
    scanf("%d", &x);
    printf ("Bilangan 2 : ");
    scanf("%d", &y);
    swap(&x,&y);
    printf("%d %d", x, y);
    return 0;
}