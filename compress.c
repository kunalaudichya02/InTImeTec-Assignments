#include<stdio.h>
#include<stdlib.h>

int stringLength(char *str){
    int count = 0;
    while(*str!= '\0'){
        count++;
        str++;
    }
    return count;
}
void compressString(char str[], int length){
    char output[200];
    int index = 0;
    int i = 0;

    while (i < length) {
        char ch = str[i];
        int count = 0;
        while (i < length && str[i] == ch) {
            count++;
            i++;
        }
        output[index++] = ch;
        output[index++] = count + '0';
    }

    output[index] = '\0';

    if (stringLength(output) > length) {
        printf("%s\n", str);
    } else {
        printf("%s\n", output);
    }
}
int main(){
    char string[100];
    scanf("%[^\n]", string);
    int n = stringLength(string);
    compressString(string, n);
}