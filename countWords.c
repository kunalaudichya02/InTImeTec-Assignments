#include<stdio.h>
#include<stdlib.h>

int countWords(char *input) {
    int count =0;
    char *ptr = input;
    while(*ptr != '\0'){
        while(*ptr == ' '){
            ptr++;
        }
        if(*ptr != ' '){
            count++;
        }
        
        while(*ptr != ' ' && *ptr !='\0'){
            ptr++;
        }
    }
    return count;
}
int main()
{
    char *input = (char *)malloc(1000 * sizeof(char));
     if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]", input);
    int result = countWords(input);
    printf("Number of words: %d\n", result);
    free(input);
    return 0;
}