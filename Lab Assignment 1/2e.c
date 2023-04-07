#include <stdio.h>

void checkPalindrome(char * str) {

    char * p1, * p2;
    p1 = str;

    while ( * p1 != '\0') {
        p1++;
    }
    --p1;

    p2 = str;

    while (p1 >= p2) {
        if ( * p1 == * p2) {
            --p1;
            p2++;
        } else {
            printf("Not Palindrome\n");
            return;
        }
    }

    printf("Palindrome\n");

}

int main() {
    printf("Please enter: \n");
    char str[100] = "";

    gets(str);

    checkPalindrome(str);

    return 0;
}