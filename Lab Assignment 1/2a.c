#include <stdio.h>

int main() {
    int n1,n2,n3;
    printf("Enter 1st number:\n");
    scanf("%d", &n1);
    printf("Enter 2nd number:\n");
    scanf("%d", &n2);
    printf("Enter 3rd number:\n");
    scanf("%d", &n3);

    if(n1 > n2){
        int sub = n1 - n2;
        printf("Subtraction = %d\n", sub);
    }
    if(n2 > n3){
        int add = n2 + n3;
        printf("Addition = %d\n", add);
    }
    if(n2 == n3){
        int mul = n2 * n3;
        printf("Multiplication = %d\n", mul);
    }
    return 0;
}