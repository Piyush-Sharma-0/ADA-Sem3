#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return (item2->ratio > item1->ratio) - (item2->ratio < item1->ratio);
}

double fractional_knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n =1000, capacity = 300;
    Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100 + 1;
        items[i].weight = rand() % 10 + 1;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    FILE* f = fopen("knapsack_times.txt","w");

    clock_t start = clock();
    for(int i=0;i<1000;i++){
        double result = fractional_knapsack(items,n,capacity);
    }
    clock_t end = clock();
    double time_taken = (double)(end-start)/CLOCKS_PER_SEC/1000;

    fprintf(f,"Fractional Greedy %f\n",time_taken);
    fclose(f);
    printf("Fractional Greedy %f\n",time_taken);
    return 0;
}
