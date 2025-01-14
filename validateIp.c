#include<stdio.h>
#include<stdlib.h>
int ifDigit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}
int checkRange(int num){
    if(num < 0 || num > 255){
        return 0;
    }
    return 1;
}
void checkValidity(char *ip){
    
    int segments = 0;
    while(*ip != '\0'){
        int digits = 0;
        int num = 0;
        char *first = ip;
            while(ifDigit(*ip) && *ip != '.'){
                num = num *10 + (*ip - '0');
                digits++;
                ip++;
            }
            if(digits>1 && *first == '0'){
                printf("Invalid");
                return;
            }
            if(checkRange(num)==0 || digits>3 || digits<1){
                printf("Invalid");
                return;
            }
            segments++;
            if(*ip == '.'){
                ip++;
            }else if(*ip != '\0'){
                printf("Invalid");
                return;
            }
    }
    if(segments != 4){
        printf("Inavlid");
    }
    else{
        printf("Valid");
    }
}
int main(){
    char *ip = (char *)malloc(15 * sizeof(char));
    if(ip == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    printf("Enter an IP address: ");
    scanf("%[^\n]", ip);
    checkValidity(ip);
    free(ip);
    return 0;
}