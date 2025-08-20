#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[m]){
                m=j;
            }
        }
        int t=arr[m];
        arr[m]=arr[i];
        arr[i]=t;
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
            selection_sort(arr,n);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/1000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
        free(temp);
    }
    return 0;
}
