#include<stdio.h>
#include<stdlib.h>

int stringLength(char *str) {
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}
void checkRotation(char *string1, char *string2){
    int len1 = stringLength(string1);
    int len2 = stringLength(string2);

    if(len1 != len2){
        printf("False");
        return;
    }

    int newLength = (2 * len1);
    char newString[newLength +1];
    
    for(int i=0; string1[i] != '\0'; i++){
        newString[i] = string1[i];
        newString[i+len1] = string1[i];
    }
    newString[newLength] = '\0';

    char *ptr1 = newString;
    char *ptr2 = string2;

    while(*ptr1 != '\0'){
        if(*ptr1 == *ptr2){
            while(*ptr1 == *ptr2 && *ptr1!= '\0' && *ptr2 != '\0'){
                ptr1++;
                ptr2++;
            }
            if(*ptr2 == '\0'){
                printf("True");
                return;
            }
        }
        ptr1++;
    }
    printf("False");
}

int main()
{
    char string1[100];
    printf("enter a string:");
    scanf("%[^\n]%*c", string1);
    char string2[100];
    printf("enter another string:");
    scanf("%[^\n]%*c", string2);
    checkRotation(string1, string2);
    return 0;
}