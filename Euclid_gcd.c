#include<stdlib.h>
#include<stdio.h>

/* implementing Euclidean Algorithm to find the greatest common divisor of two numbers*/

int gcd(int a, int b){

    while (b != 0){    
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int a, b;
printf("Calculating gcd of two numbers with Euclidean Algorithm \n");
printf("\na: ");
scanf("%d", &a);

printf("\nb: ");
scanf("%d", &b);

printf("\ngcd: %d\n", gcd(a,b));
return 0;
}
