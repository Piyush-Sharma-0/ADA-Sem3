#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linear_search(int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}

int generateRandomKey(int arr[], int n){
    int index = 1 + rand() % (n - 1);
    return arr[index];
}

int main() {
    srand(time(NULL));
    int sizes[]={10,50,100,500,1000,2000,3000,5000,7000,10000};
    int num_sizes=10;
    for(int i=0;i<num_sizes;i++){
        int n=sizes[i];
        int* arr=(int*)malloc(n*sizeof(int));
        generateRandomArray(arr,n);
        int key = generateRandomKey(arr,n);
        int ticks;
        clock_t start=clock();

        for(int i=0;i<10000;i++){
            ticks = linear_search(arr, n, key);
        }
        clock_t end=clock();

        double time= ((double)(end-start))/CLOCKS_PER_SEC/10000;
        printf("Time taken=%f\n",time);
    }
    return 0;
}
