#include<stdio.h>
#include<stdlib.h>

int digit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else return 0;
}
int tointeger(char *input){
    int num=0;
    int sign= 1;
    int i=0;
    while(input[i]==' '){
        i++;
    }
    if(input[i] == '-'){
        sign = -1;
        i++;
    }
    while(input[i] != '\0'){
        if(digit(input[i])){
            while(digit(input[i])){
                num = num * 10 + (input[i] - '0');
                i++;
            }
        }
        else return 0;
    }
    return sign *num;
}
int main(){
    printf("input: ");
    char *input = (char *)malloc(100 * sizeof(char));
    if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]", input);
    int result = tointeger(input);
    printf("output: %d\n", result);
    free(input);
}