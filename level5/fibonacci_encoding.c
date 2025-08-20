#include <stdio.h>

#define N 30 

int fib[N];

int largestFiboLessOrEqual(int n) {
    fib[0] = 1;
    fib[1] = 2;
    int i;
    for (i = 2; fib[i - 1] <= n; i++)
    
        fib[i] = fib[i - 1] + fib[i - 2];
    return i - 2;
}

void fibonacciEncoding(int n, char codeword[]) {
    int index = largestFiboLessOrEqual(n);
    int i;
    
    for (i = 0; i <= index + 1; i++)
        codeword[i] = '0'; 

    i = index;

    while (n) {
        codeword[i] = '1'; 
        n -= fib[i];

        i--;

        while (i >= 0 && fib[i] > n) {
            codeword[i] = '0';
            i--;
        }
    }

    codeword[index + 1] = '1';
    codeword[index + 2] = '\0'; 
}

int main() {
 
 
              
    char codeword[N]; 
    fibonacciEncoding(N, codeword);
    printf("Fibonacci code word for %d is %s\n", N, codeword);
    return 0;
}


