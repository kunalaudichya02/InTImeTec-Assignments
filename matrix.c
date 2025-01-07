#include <stdio.h>
#include <stdlib.h>

int stringLength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void stringCopy(char to[], char from[])
{
    int i = 0;
    while (from[i] != '\0')
    {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

int main()
{
    int n, m;
    printf("Enter number of rows:");
    scanf("%d", &n);
    while (n < 1 || n > 10) {
        printf("Please enter a number between 1 and 10: ");
        scanf("%d", &n);
    }
    printf("Enter number of columns:");
    scanf("%d", &m);
    while (m < 1 || m > 101) {
        printf("Please enter a number between 1 and 101: ");
        scanf("%d", &m);
    }
    printf("Enter the names:\n");
    char names[n][m][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
    printf("The 2D array of names is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (names[i][j][0] == 'a' || names[i][j][0] == 'e' ||
                names[i][j][0] == 'i' || names[i][j][0] == 'o' ||
                names[i][j][0] == 'u' || names[i][j][0] == 'A' ||
                names[i][j][0] == 'E' || names[i][j][0] == 'I' || 
                names[i][j][0] == 'O' || names[i][j][0] == 'U'){
                count++;
            }
        }
    }
    printf("Number of names starting with a vowel: %d\n", count);
    int maxLength = 0;
    char longestName[50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int length = stringLength(names[i][j]);
            if (length > maxLength)
            {
                maxLength = length;
                stringCopy(longestName, names[i][j]);
            }
        }
    }

    printf("The longest name: %s", longestName);

    return 0;
}