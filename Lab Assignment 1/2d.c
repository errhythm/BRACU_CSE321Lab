#include <stdio.h>

void checkValidity(char * a) {
    char arr[9] = "sheba.xyz";
    char * p1;
    char * p2;
    int cnt = 0;

    for (p1 = a;* p1 != '\0'; p1++) {
        if ( * p1 == '@') {
            ++p1;
            for (p2 = arr;* p2 != '\0'; p2++) {
                if ( * p1 == * p2) {
                    cnt++;
                    p1++;
                    if (cnt == 9) {
                        printf("Email address is okay");
                        break;
                    }
                } else {
                    printf("Email address is outdated");
                    return;
                }
            }
        }
    }
}

int main() {
    char a[100] = "";
    gets(a);
    checkValidity(a);
    return 0;
}