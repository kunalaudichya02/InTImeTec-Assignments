#include<stdio.h>
#include<stdlib.h>

void toLower(char *string){
    while(*string != '\0'){
        if(*string >= 'A' && *string <= 'Z'){
            *string = *string + 32;
        }
        string++;
    }
}
int stringLength(char *string){
    int count=0;
    while(string[count]!='\0'){
        count++;
    }
    return count;
}
void sort(char *string){
    int n = stringLength(string);
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(string[j]>string[j+1]){
                char temp = string[j];
                string[j] = string[j+1];
                string[j+1] = temp;
            }
        }
    }
}

int compareString(char *str1, char* str2){
    while(*str1 != '\0' && *str2 != '\0'){
        if(*str1 != *str2) return 0;
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0'){
        return 1;
    }
    else{
        return 0;
    }
}
void checkAnagram(char *str1, char *str2){
    toLower(str1);
    toLower(str2);
    sort(str1);
    sort(str2);
    if(compareString(str1, str2)){
        printf("true");
    }
    else{
        printf("false");
    }
}
int main(){
    char *str1 = (char *)malloc(100 * sizeof(char));
     if(str1 == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]%*c", str1);
    char *str2 = (char *)malloc(100 * sizeof(char));
     if(str2 == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]%*c", str2);
    checkAnagram(str1, str2);
    free(str1);
    free(str2);
}