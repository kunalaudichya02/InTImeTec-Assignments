#include <stdio.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutations(char *str, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%c", str[i]);
        }
        printf(" ");
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&str[start], &str[i]);
        permutations(str, start + 1, end);
        swap(&str[start], &str[i]);
    }
}

int calculateLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char input[100];
    printf("Enter the string: ");
    scanf("%s", input);
    int length = calculateLength(input);
    permutations(input, 0, length - 1);
    return 0;
}
