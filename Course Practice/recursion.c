#include <stdio.h>

void fibonacci(int n);

int main(void){

    int n = 7;

    for(int i = 0; i < n; i++){
        printf("%d ", fibonacci(n));
    }


    return 0;
}

void fibonacci(int n){
    if(n < 2){
        printf("%d ", n);
    }
         printf("%d ", fibonacci(n-1) + fibonacci(n-2));
    }