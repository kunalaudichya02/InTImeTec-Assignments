#include <stdio.h>

int length(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int containsAllCharacters(char *substring, char *pattern) {
    int patternCount[256] = {0};
    int substringCount[256] = {0};
    
    for (int i = 0; pattern[i] != '\0'; i++) {
        patternCount[pattern[i]]++;
    }
    
    for (int i = 0; substring[i] != '\0'; i++) {
        substringCount[substring[i]]++;
    }
    
    for (int i = 0; i < 256; i++) {
        if (patternCount[i] > 0 && substringCount[i] < patternCount[i]) {
            return 0;
        }
    }
    return 1;
}

void findSmallestWindow(char *str, char *pattern) {
    int len1 = length(str);
    int len2 = length(pattern);
    char smallestWindow[100];
    int minLength = len1 + 1;

    for (int start = 0; start < len1; start++) {
        for (int end = start; end < len1; end++) {
            char temp[100];
            int index = 0;
            for (int i = start; i <= end; i++) {
                temp[index++] = str[i];
            }
            temp[index] = '\0';
            
            if (containsAllCharacters(temp, pattern)) {
                int tempLength = length(temp);
                if (tempLength < minLength) {
                    minLength = tempLength;
                    for (int i = 0; i <= tempLength; i++) {
                        smallestWindow[i] = temp[i];
                    }
                }
            }
        }
    }
      if (minLength == len1 + 1) {
        printf("No pattern exist\n");
    } else {
        printf("%s", smallestWindow);
    }
}

int main() {
    char str[100];
    char pattern[100];
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);
    printf("Enter the pattern: ");
    scanf("%[^\n]%*c", pattern);
    findSmallestWindow(str, pattern);
    return 0;
}
