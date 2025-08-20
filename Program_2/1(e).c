#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }
    }
    int t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;
    return i+1;
}

void quick_sort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]=rand()%10000;
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
            quick_sort(arr,0,n-1);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/1000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
        free(temp);
    }
    return 0;
}
