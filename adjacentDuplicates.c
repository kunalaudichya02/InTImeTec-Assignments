#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void removeDuplicates(char *str) {
    int len = stringLength(str);
    int i = 0, j = 0;

    while (i < len) {
        if (str[i] == str[i + 1]) {
            while (str[i] == str[i + 1]) {
                i++;
            }
            i++;
        } else {
            str[j++] = str[i++];
        }
    }
    str[j] = '\0';
    if (j < len) {
        removeDuplicates(str);
    }
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    removeDuplicates(str);
    printf("Result: %s\n", str);
    return 0;
}
