#include<stdio.h>
#include<stdlib.h>

int stringLength(char *str){
    int length=0;
    while(*str != '\0'){
        length++;
        str++;
    }
    return length;
}

int palindromicSubstring(char *input, int left, int right){

    while(left<right){
        if(input[left] != input[right]){
            return 0;
        }
        else{
            left++;
            right--;
        }
    }
    return 1;
}

void findSubstring(char *input, int length){
 char string[100];
 int maxLength=0;
 int index=0;
    for(int size=length ; size>=1; size--){
        for(int start=0; start<=length-size; start++){
            if(palindromicSubstring(input, start, start + size -1)){
                maxLength=size;
                index=start;
                break;
            }
        }
        if(maxLength>0){
            break;
        }
        
    }
    for(int i=index; i<index + maxLength; i++){
        printf("%c", input[i]);
    }
}
int main(){
    char *input = (char *)malloc(100 * sizeof(char));
    if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]", input);
    int length = stringLength(input);
    findSubstring(input, length);
    free(input);
    return 0;
}