#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removespace(char str[], int size) {
    int n = 0;
    for (int i = 0; i < size; i++) {
        if (i <= 0 || str[i] != ' ' || str[i - 1] == ' ') {
            if (str[i] != ' ') {
                str[n] = str[i];
                n++;
            }
        } else {
            str[n] = str[i];
            n++;
        }
    }
}

int main() {
    FILE *fptr = fopen("E:\\input.txt", "r");
    if (fptr == NULL) {
        printf("Could not read input file!!\n");
        exit(1);
    }
    char str[1000];
    fscanf(fptr, "%[^\n]s", str);

    removespace(str, 1000); //
    printf("%s\n", str);

    FILE *ofptr;
    ofptr = fopen("E:\\output.txt", "w");
    fprintf(ofptr, "%s", str);
    return 0;
}