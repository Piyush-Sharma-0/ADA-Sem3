#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}

int main(){
    int n;
    printf("Enter total elements int the array");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    generateRandomArray(arr,n);
    clock_t start=clock();

    for(int i=0;i<1000;i++){
        bubble_sort(arr, n);
    }
    clock_t end=clock();
    printf("Array is-\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    double time= ((double)(end=start))/CLOCKS_PER_SEC/1000;
    printf("Time taken=%f",time);
    
}