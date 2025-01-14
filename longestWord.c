#include <stdio.h>
#include <stdlib.h>

void longestWord(char *input)
{
    char maxLength[100];
    int i = 0;
    int max = 0;

    while (input[i] != '\0')
    {
        while (input[i] == ' ' && input[i] != '\0')
            i++;

        if (input[i] != '\0'){
            int count = 0;
            char *start = &input[i];

            while (input[i] != ' ' && input[i] != '\0')
            {
                i++;
                count++;
            }
            if (count > max)
            {
                max = count;
                int j = 0;
                while (start < &input[i])
                {
                    maxLength[j++] = *start;
                    start++;
                }
                maxLength[j] = '\0';
            }
        }
    }

    printf("%s", maxLength);
}

int main()
{
    printf("input: ");
    char *input = (char *)malloc(100 * sizeof(char));
     if(input == NULL){
        printf("Memory allocation failed");
        return 1;
    }
    scanf("%[^\n]", input);
    longestWord(input);
    free(input);
}