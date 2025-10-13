#include <stdio.h>
#include <time.h>

void fibonachi_by_iterative(int n) {
    int x = 0;
    int y = 1;
    n = n - 2;
    // printf("%d %d ", x, y);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            x = x + y;
            // printf("%d ", x);
        } else {
            y = y + x;
            // printf("%d ", y);
        }
    }
}

int main() {
    int sizes[] = {100, 1000, 5000, 10000};
    int num_sizes = 4;
    int repetitions = 10000; 

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];

        clock_t start = clock();
        for (int j = 0; j < repetitions; j++) {
            fibonachi_by_iterative(n);
        }
        clock_t end = clock();

        double time = ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
        printf("for size=%d time=%f\n", n, time);  
    }

    return 0;
}
