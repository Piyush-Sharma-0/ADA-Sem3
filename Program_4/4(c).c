#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib_memo(int n, int* memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];  // already computed
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

int main() {
    int sizes[] = {100, 1000, 5000, 10000};
    int num_sizes = 4;
    int repetitions = 10000;  

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int* memo = (int*)malloc((n + 1) * sizeof(int));
        clock_t start = clock();
        for (int j = 0; j < repetitions; j++) {
            fib_memo(n,memo);
        }
        clock_t end = clock();
        free(memo);
        double time = ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
        printf("for size=%d time=%f\n",n, time); 
    }

    return 0;
}
