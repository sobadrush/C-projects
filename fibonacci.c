#include <stdio.h>
#include <stdlib.h>

int fibonacciRec(int nn){
    if(nn == 1 || nn == 2){
        return 1;
    }
    return fibonacciRec(nn - 1) + fibonacciRec(nn - 2);
}

int fibonacciIter(int nn){
    if(nn == 1 || nn == 2){
        return 1;
    }

    int prev1 = 1;
    int prev2 = 1;
    int tmp = 0;
    for (int i = 3; i <= nn; i++){
        tmp = prev1 + prev2;
        prev1 = prev2;
        prev2 = tmp;
    }
    return tmp;
}

void listAllFibNumber(int nn, int *arr){
    int i = 1;
    while(i <= nn){
        // arr[i - 1] = fibonacciRec(i); // 遞迴
        arr[i - 1] = fibonacciIter(i); // 迭代
        i++;
    }
}

int main(){

    // //  1 1 2 3 5 8 13 ...
    int num = 10;
    int *arr = malloc (sizeof (int) * num);
    listAllFibNumber(num, arr);
    // printf("Fibonacci : %d\n", fibonacciRec(5));

    for (int i = 0; i < num; i++){
        printf("%d ", arr[i]);
    }

    printf(" \n === Fibonacci Done === \n ");
    system("pause");
    return 0;
}
