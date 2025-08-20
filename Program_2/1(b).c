#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]){
                m=j;
            }
        }
        int t=a[m];
        a[m]=a[i];
        a[i]=t;
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
        selection_sort(arr, n);
    }
    clock_t end=clock();
    printf("Array is-\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    double time= ((double)(end=start))/CLOCKS_PER_SEC/1000;
    printf("Time taken=%f",time);
    
}
