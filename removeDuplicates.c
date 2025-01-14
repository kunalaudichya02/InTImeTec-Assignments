#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(char *input, char *output)
{
    char *ptr = input;
    char *print = output;

    while(*ptr!='\0'){
        int repeated=0;
        for(char *temp=input; temp<ptr; temp++){
            if(*temp==*ptr){
                repeated = 1;
            }
        }
        
        if(!repeated){
            *print = *ptr;
            print++;
        }
        ptr++;
    }
    *print = '\0';

    printf("%s", output);
}

int main()
{
    char *input = (char *)malloc(100 * sizeof(char));
     if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]", input);
    char *output = (char *)malloc(100 * sizeof(char));
     if(output == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    removeDuplicates(input, output);
    free(input);
    free(output);
    return 0;
}

