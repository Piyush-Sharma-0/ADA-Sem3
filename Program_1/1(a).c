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

int generateRandomKey(){
    int key= rand()%10000;
    return key;
}

int main() {
    int n;
    printf("Enter total elements int the array");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    int key = generateRandomKey;
    generateRandomArray(arr,n);
    int result;
    clock_t start=clock();

    for(int i=0;i<1000;i++){
        result = linear_search(arr, n, key);
    }
    clock_t end=clock();

    double time= ((double)(end=start))/CLOCKS_PER_SEC/1000;
    printf("Time taken=%f",time);
    return 0;
}
