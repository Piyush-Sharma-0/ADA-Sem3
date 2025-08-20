#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
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
        generateRandomArray(arr,n);

        int key=arr[n/2]; // middle element, ensures success

        clock_t start=clock();
        for(int k=0;k<1000;k++){
            linear_search(arr,n,key);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/1000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
    }
    return 0;
}
