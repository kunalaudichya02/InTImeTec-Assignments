#include <stdio.h>
#include <stdlib.h>

long long calculateMod(long long B, long long N, long long M)
{
    if(N==0) return 1; //base case of recursion

    long long halfPart = calculateMod(B, N/2, M); //solving the problem recursively by dividing the exponent in half
    
    long long result = (halfPart * halfPart) % M;  //finally squaring the half part to get the actual result

    if(N % 2 == 1){ //if exp is odd, then multiply the result by an additional exp
        result = (B * result) % M;
    }
    return result;
}

int main() {
    long long b, n, m;

    printf("Enter Base: ");
    if(scanf("%lld", &b) != 1){
        printf("enter valid value");
        while(getchar() != '\n');
        return 1;
    };

    printf("Enter Exponent: ");
    if(scanf("%lld", &n)!= 1){
        printf("enter valid value");
        while(getchar() != '\n');
        return 1;
    };
    
    printf("Enter Modulus: ");
    if(scanf("%lld", &m) != 1){
        printf("enter valid value");
        while(getchar() != '\n');
        return 1;
    };
    

    if(b<=0){
        printf("Base must be positive.\n");
        return 1;
    }
    if(n<0){
        printf("Exponent must be non-negative.\n");
        return 1;
    }
    if(m<=1){
        printf("Modulus must be greater than 1.\n");
        return 1;
    }
    long long ans = calculateMod(b, n, m);
    printf("%lld", ans);
    return 0;  
}