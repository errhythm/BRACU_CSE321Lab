#include <stdio.h>

int perfectNumber(n){
    int total = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            total = total + i;
        }
    }
    if(total == n){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    int up, low, n, perfect;
    printf("Lower Limit:\n");
    scanf("%d",&low);
    printf("Upper Limit:\n");
    scanf("%d",&up);

    for (n = low; n < up + 1; n++){
        perfect = perfectNumber(n);
        if(perfect == 1){
            printf("%d\n", n);
        }
    }
    return 0;
}