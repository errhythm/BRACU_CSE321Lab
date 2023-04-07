#include <stdio.h>

int main() {
    int a,b;
    int p1;
    a = fork();
    if(a == 0){
        b = fork();
        if(b == 0){
            p1 = getpid();
            printf("I am the grandchild\n");
        }
        else if(b > 0){
            wait(p1);
            printf("I am the child\n");
        }
    }
    else if(a > 0){
        wait(NULL);
        printf("I am the parent\n");
    }
    return 0;
}