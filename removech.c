#include<stdio.h>
#include<stdlib.h>


void removeCharacter(char *string, char c){
    char output[100];
    int i=0;
    while(*string != '\0'){
        if(*string!= c){
            output[i++]= *string;
            string++;
        }
        else{
            string++;
        }
    }
    output[i] = '\0';
    printf("%s", output);
}
int main(){
    char string[100];
    char c;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", string);
    printf("Enter a character: ");
    scanf("%c", &c);

    removeCharacter(string, c);
}