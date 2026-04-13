/*
TP 1 - Bagian 2
Nama : Muhammad Azka Rahadian
NIM : 13224036
*/
#include <stdio.h>
#include <string.h>

int visited[1000]={0};
int sumSquare(int n){
    int sum =0;
    int digit;
    while(n>0){
        digit = n%10;
        sum += digit*digit;
        n=n/10;
    }
    return sum;
}
void proses(int n, int count){
    if (n==1){
        printf("%d", count);
        return;
    }
    if (visited[n]==1){
        printf("infinity");
        return;
    }
    visited[n]=1;
    int next = sumSquare(n);
    proses(next, count+1);
}
int main(){
    int n;
    printf("Masukkan N: ");
    scanf("%d", &n);
    proses(n,0);
    return 0;
}
