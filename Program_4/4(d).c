#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fib_bottom_up(int n) {
    if (n == 0) return;
    if (n == 1) return;

    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    //printf("%d",dp[n]);
    //free(dp);
}

int main() {
    int sizes[] = {109, 1000, 5000, 10000};
    int num_sizes = 4;
    int repetitions = 10000;  // Run each input size 10000 times

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];

        clock_t start = clock();
        for (int j = 0; j < 1; j++) {
            fib_bottom_up(n);
        }
        clock_t end = clock();

        double time = ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
        printf("for size=%d time=%f\n",n, time);  
    }

    return 0;
}
