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
    if(item2->ratio > item1->ratio) return 1;
    else if(item2->ratio < item1->ratio) return -1;
    return 0;
}

int knapsack_greedy(int n, int capacity, Item items[]) {
    qsort(items, n, sizeof(Item), compare);
    int total_value = 0;
    for(int i = 0; i < n; i++) {
        if(capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        }
    }
    return total_value;
}

int main() {
    int n =1000, capacity = 300;
    Item items[n];

    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100 + 1;
        items[i].weight = rand() % 10 + 1;
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    FILE* f=fopen("knapsack_times.txt","a");
    if(!f){ printf("Cannot open file\n"); return 1; }

    clock_t start=clock();
    for(int i=0;i<1000;i++){
        double result=knapsack_greedy(n,capacity,items);
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC/1000;

    fprintf(f,"0/1 Greedy %f\n",time_taken);
    fclose(f);
    printf("0/1 Greedy %f\n",time_taken);
    return 0;
}
