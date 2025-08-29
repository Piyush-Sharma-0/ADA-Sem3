#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int k=arr[i],j=i-1;
        while(j>=0 && arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
}

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}

int main(){
    int sizes[]={10,50,100,500,1000,3000,6000,7000,8000};
    int num_sizes=9;

    for(int i=0;i<num_sizes;i++){
        int n=sizes[i];
        int* arr=(int*)malloc(n*sizeof(int));
        int* temp=(int*)malloc(n*sizeof(int));
        generateRandomArray(arr,n);

        for(int j=0;j<n;j++) temp[j]=arr[j];

        clock_t start=clock();
        for(int k=0;k<1000;k++){
            for(int j=0;j<n;j++) arr[j]=temp[j];
            insertion_sort(arr,n);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
        free(temp);
    }
    return 0;
}
