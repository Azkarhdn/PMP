#include <stdio.h>
#define INITIAL 35
#define CHARGE 1.10
#define LATE 2 
#define FLAG -99

double calculate(double gal, double prev){
    double bill = INITIAL + ((gal+prev) * CHARGE);
    return bill;
}
void penalty (double unpaid, double bill){
    double total ;
    if (unpaid >0){
        total = bill + LATE;
    } else {
        total = bill;
    }
    printf("Your bill is : %.2f\n", total);
}

int main (){
    double gal;
    double prev;
    double unpaid;
    double bill;
    printf("Consumptions now : ");
    scanf("%lf", &gal);
    while (gal != FLAG){
        printf("Previous consumption : ");
        scanf("%lf", &prev);
        printf("Unpaid bill : ");
        scanf("%lf", &unpaid);
        bill = calculate(gal, prev);
        penalty(unpaid, bill);
        printf("=================\n");
        printf("Consumptions now : ");
        scanf("%lf", &gal);
    }
    return 0;
}