#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int performOperation(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            printf("Error: Division by zero.\n");
        }
        return a / b;
    }
    return 0;
}

//to check the validity of the expression
int isValidExpression(const char *expression) {
      int size = strlen(expression);
    // if (size == 0) return 0;

     int prevWasOperator = 0;

    for (int i = 0; i < size; i++) {
    char ch = expression[i];

     if (isspace(ch)) continue; 

     if( i ==0 && (ch == '*' || ch == '/')){ //to check if the first character is '*' or '/' (invalid)
        printf("Error: Expression cannot start with '*' or '/' \n");
        return 0;
     }

     if (!(isdigit(ch) || ch == '+' || ch == '-' || ch == '*' || ch == '/')) { //to check valid characters
     return 0;
        } 

        if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && prevWasOperator) { //to check if there are no consecutive operators
            printf("Error: Consecutive operators are not allowed\n");
            return 0;
        }

    prevWasOperator = (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    if (prevWasOperator) {
        printf("Error: Expression cannot end with an operator\n");
        return 0;
    }

    return 1;
}

int solve(const char *expression) {
    int numbers[100], numsTop = -1; 
    char operators[100], opsTop = -1; 
    int currentNumber = 0;
    int i = 0;

    while (expression[i] != '\0') {
        char ch = expression[i];

        if (isspace(ch)) {
            i++;
            continue; 
        }

        if (isdigit(ch)) {
            currentNumber = currentNumber * 10 + (ch - '0');  
        } else {
          
            numbers[++numsTop] = currentNumber;
            currentNumber = 0;

           
            while (opsTop >= 0 && 
                  ((ch == '+' || ch == '-') || 
                  (operators[opsTop] == '*' || operators[opsTop] == '/'))) {
                if ((ch == '*' || ch == '/') && (operators[opsTop] == '+' || operators[opsTop] == '-')) break;
                 int b = numbers[numsTop--];
                 int a = numbers[numsTop--];
                numbers[++numsTop] = performOperation(a, b, operators[opsTop--]); 
            }
            operators[++opsTop] = ch; // to push the current operator
        }
            i++;
    }

   
      numbers[++numsTop] = currentNumber; //to push the last number

    while (opsTop >= 0) {
        int b = numbers[numsTop--];
        int a = numbers[numsTop--];
        numbers[++numsTop] = performOperation(a, b, operators[opsTop--]);
    }
    return numbers[numsTop];
}

int main() {
    char expression[100];
    printf("enter an expression: ");
    fgets(expression, 100, stdin);

    int j = 0;
    for(int i = 0; expression[i] != '\0'; i++){
        if(!isspace(expression[i])){
            expression[j++] = expression[i];
        }
    }
    expression[j] = '\0';


    int size = strlen(expression);
    if(size == 0){
        printf("Input cannot be empty");
        return 0;
    }

     if (isValidExpression(expression)) {
        int result = solve(expression);
        printf("your result is  %d\n", result);
    } else {
        printf("Invalid expression\n");
    }


    return 0;
}
