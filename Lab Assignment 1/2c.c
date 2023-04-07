#include<stdio.h>
#include<string.h>
int main()
{
    char pass[100];

    scanf("%s", pass);

    int len = strlen(pass);
    int lcase = 0, ucase = 0, digit = 0, special = 0;

    for(int i=0;i<len;i++){
        if(pass[i]>=97 && pass[i]<=122){
            lcase++;
        }
        else if(pass[i]>=65 && pass[i]<=96){
            ucase++;
        }
        else if(pass[i]>=48 && pass[i]<=57){
            digit++;
        }
        else if( (pass[i]>=32 && pass[i]<=47) || (pass[i]>=58 && pass[i]<=64) || (pass[i]>=91 && pass[i]<=96) || (pass[i]>=123 && pass[i]<=126) ){
            special++;
        }
    }

    if(lcase==0){
        printf("Lowercase character missing!\n");
    }
    if(ucase==0){
        printf("Uppercase character missing!\n");
    }
    if(digit==0){
        printf("Digit missing!\n");
    }
    if(special==0){
        printf("Special character missing!\n");
    }
    if(lcase!=0 && ucase!=0 && digit!=0 && special!=0){
        printf("OK\n");
    }

    return 0;
}