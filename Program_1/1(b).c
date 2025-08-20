#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
        result = binary_search(arr, n, key);
    }
    clock_t end=clock();
    double time= ((double)(end=start))/CLOCKS_PER_SEC/1000;
    printf("Time taken=%f",time);
    

    printf("Index: %d\n", result);
    return 0;
}