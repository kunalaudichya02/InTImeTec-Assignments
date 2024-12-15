#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to check if the character is a digit
int isValidDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else return 0;
}

// function to check if the character is a white space
int isWhiteSpace(char ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\n')
        return 1;
    else
        return 0;
}

// function to find the size or length of a string
int stringLength(const char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

// function to perform operations using the given number and operators
int performOperation(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
    {
        if (b == 0)
        {
            printf("Error: Division by zero.\n");
        }
        return a / b;
    }
    return 0;
}

// to check the validity of the expression
int isValidExpression(const char *expression)
{
    int size = stringLength(expression);
    int prevWasOperator = 0;

    for (int i = 0; i < size; i++)
    {
        char ch = expression[i];

        if (isWhiteSpace(ch))
            continue;

        if (i == 0 && (ch == '*' || ch == '/'))
        { // to check if the first character is '*' or '/' (invalid)
            printf("Error: Expression cannot start with '*' or '/' \n");
            return 0;
        }

        if (!(isValidDigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/'))
        { // to check valid characters
            return 0;
        }

        if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && prevWasOperator)
        { // to check if there are no consecutive operators
            printf("Error: Consecutive operators are not allowed\n");
            return 0;
        }

        prevWasOperator = (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    if (prevWasOperator)
    {
        printf("Error: Expression cannot end with an operator\n");
        return 0;
    }

    return 1;
}

int solve(const char *expression)
{
    int numbers[100], numsTop = -1;
    char operators[100], opsTop = -1;
    int currentNumber = 0;
    int i = 0;

    while (expression[i] != '\0')
    {
        char ch = expression[i];

        if (isWhiteSpace(ch))
        {
            i++;
            continue;
        }

        if (isValidDigit(ch))
        {
            currentNumber = currentNumber * 10 + (ch - '0');
        }
        else
        {

            numbers[++numsTop] = currentNumber;
            currentNumber = 0;

            while (opsTop >= 0 &&
                   ((ch == '+' || ch == '-') ||
                    (operators[opsTop] == '*' || operators[opsTop] == '/')))
            {

                int b = numbers[numsTop--];
                int a = numbers[numsTop--];
                numbers[++numsTop] = performOperation(a, b, operators[opsTop--]);
            }
            operators[++opsTop] = ch; // to push the current operator
        }
        i++;
    }

    numbers[++numsTop] = currentNumber; // to push the last number

    while (opsTop >= 0)
    {
        int b = numbers[numsTop--];
        int a = numbers[numsTop--];
        numbers[++numsTop] = performOperation(a, b, operators[opsTop--]);
    }
    return numbers[numsTop];
}

int main()
{
    char expression[100];
    printf("enter an expression: ");
    fgets(expression, 100, stdin);

    int j = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (!isWhiteSpace(expression[i]))
        {
            expression[j++] = expression[i];
        }
    }
    expression[j] = '\0';

    int size = stringLength(expression);
    if (size == 0)
    {
        printf("Input cannot be empty");
        return 0;
    }

    if (isValidExpression(expression))
    {
        int result = solve(expression);
        printf("your result is  %d\n", result);
    }
    else
    {
        printf("Invalid expression\n");
    }

    return 0;
}
