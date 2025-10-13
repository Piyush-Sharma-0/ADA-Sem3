#include <stdio.h>
#include <time.h>

void fibonachi_by_recursive(int n, int x, int y) {
    if (n == 0)
        return;
    if (n == 1) {
        // printf("%d", x);
        return;
    }
    // printf("%d %d ", x, y);
    x = x + y;
    y = y + x;
    fibonachi_by_recursive(n - 2, x, y);
}

int main() {
    int sizes[] = {100, 1000, 5000, 10000};
    int num_sizes = 4;
    int repetitions = 10000;  

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];

        clock_t start = clock();
        for (int j = 0; j < repetitions; j++) {
            fibonachi_by_recursive(n, 0, 1);
        }
        clock_t end = clock();

        double time = ((double)(end - start)) / CLOCKS_PER_SEC / repetitions;
        printf("for size=%d time=%f\n",n,time);  
    }

    return 0;
}
